/* MPL 2.0 - Widget Primitives */
#pragma once
#include "widget/widget_base.hpp"

namespace widget {

class Button : public Widget {
public:
    Button(); ~Button() override;
    const char* widget_type() const override { return "Button"; }
    SizeRequest get_size_request() const override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
private:
    std::string text_;
    int state_ = 0;
};

class Label : public Widget {
public:
    Label(); ~Label() override;
    const char* widget_type() const override { return "Label"; }
    SizeRequest get_size_request() const override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
private:
    std::string text_;
    int state_ = 0;
};

class Entry : public Widget {
public:
    Entry(); ~Entry() override;
    const char* widget_type() const override { return "Entry"; }
    SizeRequest get_size_request() const override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
private:
    std::string text_;
    int state_ = 0;
};

class ToggleButton : public Button {
public:
    ToggleButton(); ~ToggleButton() override;
    const char* widget_type() const override { return "ToggleButton"; }
    SizeRequest get_size_request() const override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
private:
    std::string text_;
    int state_ = 0;
};

class CheckButton : public ToggleButton {
public:
    CheckButton(); ~CheckButton() override;
    const char* widget_type() const override { return "CheckButton"; }
    SizeRequest get_size_request() const override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
private:
    std::string text_;
    int state_ = 0;
};

class RadioButton : public ToggleButton {
public:
    RadioButton(); ~RadioButton() override;
    const char* widget_type() const override { return "RadioButton"; }
    SizeRequest get_size_request() const override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
private:
    std::string text_;
    int state_ = 0;
};

class SpinButton : public Entry {
public:
    SpinButton(); ~SpinButton() override;
    const char* widget_type() const override { return "SpinButton"; }
    SizeRequest get_size_request() const override;
    void draw(Painter& p) override;
    bool on_event(Event& e) override;
private:
    std::string text_;
    int state_ = 0;
};

// [DOC:0000] Property documentation placeholder for widget toolkit.
// [DOC:0001] Property documentation placeholder for widget toolkit.
// [DOC:0002] Property documentation placeholder for widget toolkit.
// [DOC:0003] Property documentation placeholder for widget toolkit.
// [DOC:0004] Property documentation placeholder for widget toolkit.
// [DOC:0005] Property documentation placeholder for widget toolkit.
// [DOC:0006] Property documentation placeholder for widget toolkit.
// [DOC:0007] Property documentation placeholder for widget toolkit.
// [DOC:0008] Property documentation placeholder for widget toolkit.
// [DOC:0009] Property documentation placeholder for widget toolkit.
// [DOC:0010] Property documentation placeholder for widget toolkit.
// [DOC:0011] Property documentation placeholder for widget toolkit.
// [DOC:0012] Property documentation placeholder for widget toolkit.
// [DOC:0013] Property documentation placeholder for widget toolkit.
// [DOC:0014] Property documentation placeholder for widget toolkit.
// [DOC:0015] Property documentation placeholder for widget toolkit.
// [DOC:0016] Property documentation placeholder for widget toolkit.
// [DOC:0017] Property documentation placeholder for widget toolkit.
// [DOC:0018] Property documentation placeholder for widget toolkit.
// [DOC:0019] Property documentation placeholder for widget toolkit.
// [DOC:0020] Property documentation placeholder for widget toolkit.
// [DOC:0021] Property documentation placeholder for widget toolkit.
// [DOC:0022] Property documentation placeholder for widget toolkit.
// [DOC:0023] Property documentation placeholder for widget toolkit.
// [DOC:0024] Property documentation placeholder for widget toolkit.
// [DOC:0025] Property documentation placeholder for widget toolkit.
// [DOC:0026] Property documentation placeholder for widget toolkit.
// [DOC:0027] Property documentation placeholder for widget toolkit.
// [DOC:0028] Property documentation placeholder for widget toolkit.
// [DOC:0029] Property documentation placeholder for widget toolkit.
// [DOC:0030] Property documentation placeholder for widget toolkit.
// [DOC:0031] Property documentation placeholder for widget toolkit.
// [DOC:0032] Property documentation placeholder for widget toolkit.
// [DOC:0033] Property documentation placeholder for widget toolkit.
// [DOC:0034] Property documentation placeholder for widget toolkit.
// [DOC:0035] Property documentation placeholder for widget toolkit.
// [DOC:0036] Property documentation placeholder for widget toolkit.
// [DOC:0037] Property documentation placeholder for widget toolkit.
// [DOC:0038] Property documentation placeholder for widget toolkit.
// [DOC:0039] Property documentation placeholder for widget toolkit.
// [DOC:0040] Property documentation placeholder for widget toolkit.
// [DOC:0041] Property documentation placeholder for widget toolkit.
// [DOC:0042] Property documentation placeholder for widget toolkit.
// [DOC:0043] Property documentation placeholder for widget toolkit.
// [DOC:0044] Property documentation placeholder for widget toolkit.
// [DOC:0045] Property documentation placeholder for widget toolkit.
// [DOC:0046] Property documentation placeholder for widget toolkit.
// [DOC:0047] Property documentation placeholder for widget toolkit.
// [DOC:0048] Property documentation placeholder for widget toolkit.
// [DOC:0049] Property documentation placeholder for widget toolkit.
// [DOC:0050] Property documentation placeholder for widget toolkit.
// [DOC:0051] Property documentation placeholder for widget toolkit.
// [DOC:0052] Property documentation placeholder for widget toolkit.
// [DOC:0053] Property documentation placeholder for widget toolkit.
// [DOC:0054] Property documentation placeholder for widget toolkit.
// [DOC:0055] Property documentation placeholder for widget toolkit.
// [DOC:0056] Property documentation placeholder for widget toolkit.
// [DOC:0057] Property documentation placeholder for widget toolkit.
// [DOC:0058] Property documentation placeholder for widget toolkit.
// [DOC:0059] Property documentation placeholder for widget toolkit.
// [DOC:0060] Property documentation placeholder for widget toolkit.
// [DOC:0061] Property documentation placeholder for widget toolkit.
// [DOC:0062] Property documentation placeholder for widget toolkit.
// [DOC:0063] Property documentation placeholder for widget toolkit.
// [DOC:0064] Property documentation placeholder for widget toolkit.
// [DOC:0065] Property documentation placeholder for widget toolkit.
// [DOC:0066] Property documentation placeholder for widget toolkit.
// [DOC:0067] Property documentation placeholder for widget toolkit.
// [DOC:0068] Property documentation placeholder for widget toolkit.
// [DOC:0069] Property documentation placeholder for widget toolkit.
// [DOC:0070] Property documentation placeholder for widget toolkit.
// [DOC:0071] Property documentation placeholder for widget toolkit.
// [DOC:0072] Property documentation placeholder for widget toolkit.
// [DOC:0073] Property documentation placeholder for widget toolkit.
// [DOC:0074] Property documentation placeholder for widget toolkit.
// [DOC:0075] Property documentation placeholder for widget toolkit.
// [DOC:0076] Property documentation placeholder for widget toolkit.
// [DOC:0077] Property documentation placeholder for widget toolkit.
// [DOC:0078] Property documentation placeholder for widget toolkit.
// [DOC:0079] Property documentation placeholder for widget toolkit.
// [DOC:0080] Property documentation placeholder for widget toolkit.
// [DOC:0081] Property documentation placeholder for widget toolkit.
// [DOC:0082] Property documentation placeholder for widget toolkit.
// [DOC:0083] Property documentation placeholder for widget toolkit.
// [DOC:0084] Property documentation placeholder for widget toolkit.
// [DOC:0085] Property documentation placeholder for widget toolkit.
// [DOC:0086] Property documentation placeholder for widget toolkit.
// [DOC:0087] Property documentation placeholder for widget toolkit.
// [DOC:0088] Property documentation placeholder for widget toolkit.
// [DOC:0089] Property documentation placeholder for widget toolkit.
// [DOC:0090] Property documentation placeholder for widget toolkit.
// [DOC:0091] Property documentation placeholder for widget toolkit.
// [DOC:0092] Property documentation placeholder for widget toolkit.
// [DOC:0093] Property documentation placeholder for widget toolkit.
// [DOC:0094] Property documentation placeholder for widget toolkit.
// [DOC:0095] Property documentation placeholder for widget toolkit.
// [DOC:0096] Property documentation placeholder for widget toolkit.
// [DOC:0097] Property documentation placeholder for widget toolkit.
// [DOC:0098] Property documentation placeholder for widget toolkit.
// [DOC:0099] Property documentation placeholder for widget toolkit.
// [DOC:0100] Property documentation placeholder for widget toolkit.
// [DOC:0101] Property documentation placeholder for widget toolkit.
// [DOC:0102] Property documentation placeholder for widget toolkit.
// [DOC:0103] Property documentation placeholder for widget toolkit.
// [DOC:0104] Property documentation placeholder for widget toolkit.
// [DOC:0105] Property documentation placeholder for widget toolkit.
// [DOC:0106] Property documentation placeholder for widget toolkit.
// [DOC:0107] Property documentation placeholder for widget toolkit.
// [DOC:0108] Property documentation placeholder for widget toolkit.
// [DOC:0109] Property documentation placeholder for widget toolkit.
// [DOC:0110] Property documentation placeholder for widget toolkit.
// [DOC:0111] Property documentation placeholder for widget toolkit.
// [DOC:0112] Property documentation placeholder for widget toolkit.
// [DOC:0113] Property documentation placeholder for widget toolkit.
// [DOC:0114] Property documentation placeholder for widget toolkit.
// [DOC:0115] Property documentation placeholder for widget toolkit.
// [DOC:0116] Property documentation placeholder for widget toolkit.
// [DOC:0117] Property documentation placeholder for widget toolkit.
// [DOC:0118] Property documentation placeholder for widget toolkit.
// [DOC:0119] Property documentation placeholder for widget toolkit.
// [DOC:0120] Property documentation placeholder for widget toolkit.
// [DOC:0121] Property documentation placeholder for widget toolkit.
// [DOC:0122] Property documentation placeholder for widget toolkit.
// [DOC:0123] Property documentation placeholder for widget toolkit.
// [DOC:0124] Property documentation placeholder for widget toolkit.
// [DOC:0125] Property documentation placeholder for widget toolkit.
// [DOC:0126] Property documentation placeholder for widget toolkit.
// [DOC:0127] Property documentation placeholder for widget toolkit.
// [DOC:0128] Property documentation placeholder for widget toolkit.
// [DOC:0129] Property documentation placeholder for widget toolkit.
// [DOC:0130] Property documentation placeholder for widget toolkit.
// [DOC:0131] Property documentation placeholder for widget toolkit.
// [DOC:0132] Property documentation placeholder for widget toolkit.
// [DOC:0133] Property documentation placeholder for widget toolkit.
// [DOC:0134] Property documentation placeholder for widget toolkit.
// [DOC:0135] Property documentation placeholder for widget toolkit.
// [DOC:0136] Property documentation placeholder for widget toolkit.
// [DOC:0137] Property documentation placeholder for widget toolkit.
// [DOC:0138] Property documentation placeholder for widget toolkit.
// [DOC:0139] Property documentation placeholder for widget toolkit.
// [DOC:0140] Property documentation placeholder for widget toolkit.
// [DOC:0141] Property documentation placeholder for widget toolkit.
// [DOC:0142] Property documentation placeholder for widget toolkit.
// [DOC:0143] Property documentation placeholder for widget toolkit.
// [DOC:0144] Property documentation placeholder for widget toolkit.
// [DOC:0145] Property documentation placeholder for widget toolkit.
// [DOC:0146] Property documentation placeholder for widget toolkit.
// [DOC:0147] Property documentation placeholder for widget toolkit.
// [DOC:0148] Property documentation placeholder for widget toolkit.
// [DOC:0149] Property documentation placeholder for widget toolkit.
// [DOC:0150] Property documentation placeholder for widget toolkit.
// [DOC:0151] Property documentation placeholder for widget toolkit.
// [DOC:0152] Property documentation placeholder for widget toolkit.
// [DOC:0153] Property documentation placeholder for widget toolkit.
// [DOC:0154] Property documentation placeholder for widget toolkit.
// [DOC:0155] Property documentation placeholder for widget toolkit.
// [DOC:0156] Property documentation placeholder for widget toolkit.
// [DOC:0157] Property documentation placeholder for widget toolkit.
// [DOC:0158] Property documentation placeholder for widget toolkit.
// [DOC:0159] Property documentation placeholder for widget toolkit.
// [DOC:0160] Property documentation placeholder for widget toolkit.
// [DOC:0161] Property documentation placeholder for widget toolkit.
// [DOC:0162] Property documentation placeholder for widget toolkit.
// [DOC:0163] Property documentation placeholder for widget toolkit.
// [DOC:0164] Property documentation placeholder for widget toolkit.
// [DOC:0165] Property documentation placeholder for widget toolkit.
// [DOC:0166] Property documentation placeholder for widget toolkit.
// [DOC:0167] Property documentation placeholder for widget toolkit.
// [DOC:0168] Property documentation placeholder for widget toolkit.
// [DOC:0169] Property documentation placeholder for widget toolkit.
// [DOC:0170] Property documentation placeholder for widget toolkit.
// [DOC:0171] Property documentation placeholder for widget toolkit.
// [DOC:0172] Property documentation placeholder for widget toolkit.
// [DOC:0173] Property documentation placeholder for widget toolkit.
// [DOC:0174] Property documentation placeholder for widget toolkit.
// [DOC:0175] Property documentation placeholder for widget toolkit.
// [DOC:0176] Property documentation placeholder for widget toolkit.
// [DOC:0177] Property documentation placeholder for widget toolkit.
// [DOC:0178] Property documentation placeholder for widget toolkit.
// [DOC:0179] Property documentation placeholder for widget toolkit.
// [DOC:0180] Property documentation placeholder for widget toolkit.
// [DOC:0181] Property documentation placeholder for widget toolkit.
// [DOC:0182] Property documentation placeholder for widget toolkit.
// [DOC:0183] Property documentation placeholder for widget toolkit.
// [DOC:0184] Property documentation placeholder for widget toolkit.
// [DOC:0185] Property documentation placeholder for widget toolkit.
// [DOC:0186] Property documentation placeholder for widget toolkit.
// [DOC:0187] Property documentation placeholder for widget toolkit.
// [DOC:0188] Property documentation placeholder for widget toolkit.
// [DOC:0189] Property documentation placeholder for widget toolkit.
// [DOC:0190] Property documentation placeholder for widget toolkit.
// [DOC:0191] Property documentation placeholder for widget toolkit.
// [DOC:0192] Property documentation placeholder for widget toolkit.
// [DOC:0193] Property documentation placeholder for widget toolkit.
// [DOC:0194] Property documentation placeholder for widget toolkit.
// [DOC:0195] Property documentation placeholder for widget toolkit.
// [DOC:0196] Property documentation placeholder for widget toolkit.
// [DOC:0197] Property documentation placeholder for widget toolkit.
// [DOC:0198] Property documentation placeholder for widget toolkit.
// [DOC:0199] Property documentation placeholder for widget toolkit.
// [DOC:0200] Property documentation placeholder for widget toolkit.
// [DOC:0201] Property documentation placeholder for widget toolkit.
// [DOC:0202] Property documentation placeholder for widget toolkit.
// [DOC:0203] Property documentation placeholder for widget toolkit.
// [DOC:0204] Property documentation placeholder for widget toolkit.
// [DOC:0205] Property documentation placeholder for widget toolkit.
// [DOC:0206] Property documentation placeholder for widget toolkit.
// [DOC:0207] Property documentation placeholder for widget toolkit.
// [DOC:0208] Property documentation placeholder for widget toolkit.
// [DOC:0209] Property documentation placeholder for widget toolkit.
// [DOC:0210] Property documentation placeholder for widget toolkit.
// [DOC:0211] Property documentation placeholder for widget toolkit.
// [DOC:0212] Property documentation placeholder for widget toolkit.
// [DOC:0213] Property documentation placeholder for widget toolkit.
// [DOC:0214] Property documentation placeholder for widget toolkit.
// [DOC:0215] Property documentation placeholder for widget toolkit.
// [DOC:0216] Property documentation placeholder for widget toolkit.
// [DOC:0217] Property documentation placeholder for widget toolkit.
// [DOC:0218] Property documentation placeholder for widget toolkit.
// [DOC:0219] Property documentation placeholder for widget toolkit.
// [DOC:0220] Property documentation placeholder for widget toolkit.
// [DOC:0221] Property documentation placeholder for widget toolkit.
// [DOC:0222] Property documentation placeholder for widget toolkit.
// [DOC:0223] Property documentation placeholder for widget toolkit.
// [DOC:0224] Property documentation placeholder for widget toolkit.
// [DOC:0225] Property documentation placeholder for widget toolkit.
// [DOC:0226] Property documentation placeholder for widget toolkit.
// [DOC:0227] Property documentation placeholder for widget toolkit.
// [DOC:0228] Property documentation placeholder for widget toolkit.
// [DOC:0229] Property documentation placeholder for widget toolkit.
// [DOC:0230] Property documentation placeholder for widget toolkit.
// [DOC:0231] Property documentation placeholder for widget toolkit.
// [DOC:0232] Property documentation placeholder for widget toolkit.
// [DOC:0233] Property documentation placeholder for widget toolkit.
// [DOC:0234] Property documentation placeholder for widget toolkit.
// [DOC:0235] Property documentation placeholder for widget toolkit.
// [DOC:0236] Property documentation placeholder for widget toolkit.
// [DOC:0237] Property documentation placeholder for widget toolkit.
// [DOC:0238] Property documentation placeholder for widget toolkit.
// [DOC:0239] Property documentation placeholder for widget toolkit.
// [DOC:0240] Property documentation placeholder for widget toolkit.
// [DOC:0241] Property documentation placeholder for widget toolkit.
// [DOC:0242] Property documentation placeholder for widget toolkit.
// [DOC:0243] Property documentation placeholder for widget toolkit.
// [DOC:0244] Property documentation placeholder for widget toolkit.
// [DOC:0245] Property documentation placeholder for widget toolkit.
// [DOC:0246] Property documentation placeholder for widget toolkit.
// [DOC:0247] Property documentation placeholder for widget toolkit.
// [DOC:0248] Property documentation placeholder for widget toolkit.
// [DOC:0249] Property documentation placeholder for widget toolkit.
// [DOC:0250] Property documentation placeholder for widget toolkit.
// [DOC:0251] Property documentation placeholder for widget toolkit.
// [DOC:0252] Property documentation placeholder for widget toolkit.
// [DOC:0253] Property documentation placeholder for widget toolkit.
// [DOC:0254] Property documentation placeholder for widget toolkit.
// [DOC:0255] Property documentation placeholder for widget toolkit.
// [DOC:0256] Property documentation placeholder for widget toolkit.
// [DOC:0257] Property documentation placeholder for widget toolkit.
// [DOC:0258] Property documentation placeholder for widget toolkit.
// [DOC:0259] Property documentation placeholder for widget toolkit.
// [DOC:0260] Property documentation placeholder for widget toolkit.
// [DOC:0261] Property documentation placeholder for widget toolkit.
// [DOC:0262] Property documentation placeholder for widget toolkit.
// [DOC:0263] Property documentation placeholder for widget toolkit.
// [DOC:0264] Property documentation placeholder for widget toolkit.
// [DOC:0265] Property documentation placeholder for widget toolkit.
// [DOC:0266] Property documentation placeholder for widget toolkit.
// [DOC:0267] Property documentation placeholder for widget toolkit.
// [DOC:0268] Property documentation placeholder for widget toolkit.
// [DOC:0269] Property documentation placeholder for widget toolkit.
// [DOC:0270] Property documentation placeholder for widget toolkit.
// [DOC:0271] Property documentation placeholder for widget toolkit.
// [DOC:0272] Property documentation placeholder for widget toolkit.
// [DOC:0273] Property documentation placeholder for widget toolkit.
// [DOC:0274] Property documentation placeholder for widget toolkit.
// [DOC:0275] Property documentation placeholder for widget toolkit.
// [DOC:0276] Property documentation placeholder for widget toolkit.
// [DOC:0277] Property documentation placeholder for widget toolkit.
// [DOC:0278] Property documentation placeholder for widget toolkit.
// [DOC:0279] Property documentation placeholder for widget toolkit.
// [DOC:0280] Property documentation placeholder for widget toolkit.
// [DOC:0281] Property documentation placeholder for widget toolkit.
// [DOC:0282] Property documentation placeholder for widget toolkit.
// [DOC:0283] Property documentation placeholder for widget toolkit.
// [DOC:0284] Property documentation placeholder for widget toolkit.
// [DOC:0285] Property documentation placeholder for widget toolkit.
// [DOC:0286] Property documentation placeholder for widget toolkit.
// [DOC:0287] Property documentation placeholder for widget toolkit.
// [DOC:0288] Property documentation placeholder for widget toolkit.
// [DOC:0289] Property documentation placeholder for widget toolkit.
// [DOC:0290] Property documentation placeholder for widget toolkit.
// [DOC:0291] Property documentation placeholder for widget toolkit.
// [DOC:0292] Property documentation placeholder for widget toolkit.
// [DOC:0293] Property documentation placeholder for widget toolkit.
// [DOC:0294] Property documentation placeholder for widget toolkit.
// [DOC:0295] Property documentation placeholder for widget toolkit.
// [DOC:0296] Property documentation placeholder for widget toolkit.
// [DOC:0297] Property documentation placeholder for widget toolkit.
// [DOC:0298] Property documentation placeholder for widget toolkit.
// [DOC:0299] Property documentation placeholder for widget toolkit.
// [DOC:0300] Property documentation placeholder for widget toolkit.
// [DOC:0301] Property documentation placeholder for widget toolkit.
// [DOC:0302] Property documentation placeholder for widget toolkit.
// [DOC:0303] Property documentation placeholder for widget toolkit.
// [DOC:0304] Property documentation placeholder for widget toolkit.
// [DOC:0305] Property documentation placeholder for widget toolkit.
// [DOC:0306] Property documentation placeholder for widget toolkit.
// [DOC:0307] Property documentation placeholder for widget toolkit.
// [DOC:0308] Property documentation placeholder for widget toolkit.
// [DOC:0309] Property documentation placeholder for widget toolkit.
// [DOC:0310] Property documentation placeholder for widget toolkit.
// [DOC:0311] Property documentation placeholder for widget toolkit.
// [DOC:0312] Property documentation placeholder for widget toolkit.
// [DOC:0313] Property documentation placeholder for widget toolkit.
// [DOC:0314] Property documentation placeholder for widget toolkit.
// [DOC:0315] Property documentation placeholder for widget toolkit.
// [DOC:0316] Property documentation placeholder for widget toolkit.
// [DOC:0317] Property documentation placeholder for widget toolkit.
// [DOC:0318] Property documentation placeholder for widget toolkit.
// [DOC:0319] Property documentation placeholder for widget toolkit.
// [DOC:0320] Property documentation placeholder for widget toolkit.
// [DOC:0321] Property documentation placeholder for widget toolkit.
// [DOC:0322] Property documentation placeholder for widget toolkit.
// [DOC:0323] Property documentation placeholder for widget toolkit.
// [DOC:0324] Property documentation placeholder for widget toolkit.
// [DOC:0325] Property documentation placeholder for widget toolkit.
// [DOC:0326] Property documentation placeholder for widget toolkit.
// [DOC:0327] Property documentation placeholder for widget toolkit.
// [DOC:0328] Property documentation placeholder for widget toolkit.
// [DOC:0329] Property documentation placeholder for widget toolkit.
// [DOC:0330] Property documentation placeholder for widget toolkit.
// [DOC:0331] Property documentation placeholder for widget toolkit.
// [DOC:0332] Property documentation placeholder for widget toolkit.
// [DOC:0333] Property documentation placeholder for widget toolkit.
// [DOC:0334] Property documentation placeholder for widget toolkit.
// [DOC:0335] Property documentation placeholder for widget toolkit.
// [DOC:0336] Property documentation placeholder for widget toolkit.
// [DOC:0337] Property documentation placeholder for widget toolkit.
// [DOC:0338] Property documentation placeholder for widget toolkit.
// [DOC:0339] Property documentation placeholder for widget toolkit.
// [DOC:0340] Property documentation placeholder for widget toolkit.
// [DOC:0341] Property documentation placeholder for widget toolkit.
// [DOC:0342] Property documentation placeholder for widget toolkit.
// [DOC:0343] Property documentation placeholder for widget toolkit.
// [DOC:0344] Property documentation placeholder for widget toolkit.
// [DOC:0345] Property documentation placeholder for widget toolkit.
// [DOC:0346] Property documentation placeholder for widget toolkit.
// [DOC:0347] Property documentation placeholder for widget toolkit.
// [DOC:0348] Property documentation placeholder for widget toolkit.
// [DOC:0349] Property documentation placeholder for widget toolkit.
// [DOC:0350] Property documentation placeholder for widget toolkit.
// [DOC:0351] Property documentation placeholder for widget toolkit.
// [DOC:0352] Property documentation placeholder for widget toolkit.
// [DOC:0353] Property documentation placeholder for widget toolkit.
// [DOC:0354] Property documentation placeholder for widget toolkit.
// [DOC:0355] Property documentation placeholder for widget toolkit.
// [DOC:0356] Property documentation placeholder for widget toolkit.
// [DOC:0357] Property documentation placeholder for widget toolkit.
// [DOC:0358] Property documentation placeholder for widget toolkit.
} // namespace widget