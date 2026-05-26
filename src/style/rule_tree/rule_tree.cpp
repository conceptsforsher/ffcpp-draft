/* MPL 2.0 */
#include "style/rule_tree/rule_tree.hpp"
#include <algorithm>
#include <stack>
#include <cassert>

namespace style {

RuleNode::Ptr RuleNode::find_or_create_child(const Rule* r,uint32_t order){
    for(auto&c:children)if(c->rule==r&&c->source_order==order)return c;
    auto c=std::make_shared<RuleNode>(r,order);c->parent=this;children.push_back(c);return c;
}
void RuleNode::accumulate(std::vector<PropertyOverride>& result)const{
    std::vector<const RuleNode*>path;const RuleNode*cur=this;
    while(cur){path.push_back(cur);cur=cur->parent;}
    std::reverse(path.begin(),path.end());
    for(auto*n:path)for(auto&ov:n->overrides){auto it=std::find_if(result.begin(),result.end(),[&](auto&p){return p.name==ov.name;});if(it!=result.end())*it=ov;else result.push_back(ov);}
}
size_t RuleNode::subtree_size()const{size_t c=1;for(auto&ch:children)c+=ch->subtree_size();return c;}
size_t RuleNode::depth()const{size_t d=0;const RuleNode*n=this;while(n->parent){++d;n=n->parent;}return d;}

RuleTree::RuleTree():root_(std::make_shared<RuleNode>()),node_count_(1){}
RuleTree::~RuleTree()=default;
void RuleTree::clear(){root_=std::make_shared<RuleNode>();node_count_=1;}
size_t RuleTree::size()const{return node_count_;}
size_t RuleTree::memory_usage()const{return node_count_*(sizeof(RuleNode)+128);}
size_t RuleTree::max_depth()const{size_t md=0;std::stack<RuleNode*>s;s.push(root_.get());while(!s.empty()){auto*n=s.top();s.pop();md=std::max(md,n->depth());for(auto&c:n->children)s.push(c.get());}return md;}
RuleNode::Ptr RuleTree::insert(const std::vector<const Rule*>&rules,const std::vector<uint32_t>&orders){
    RuleNode::Ptr cur=root_;for(size_t i=0;i<rules.size();++i){uint32_t o=i<orders.size()?orders[i]:0;cur=cur->find_or_create_child(rules[i],o);++node_count_;}return cur;
}

} // namespace style
