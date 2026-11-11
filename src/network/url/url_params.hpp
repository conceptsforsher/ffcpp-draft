/* MPL 2.0 - network/url
 *
 * C++ translation of mozilla::URLParams:
 *   - netwerk/base/nsURLHelper.h  (class URLParams, static Parse template)
 *   - netwerk/base/nsURLHelper.cpp (the member definitions)
 *
 * The class handles form-urlencoded query strings: it manages an ordered list
 * of name-value pairs and converts between them and their string form.
 *
 * Deviations, all forced by the absence of Gecko's string library:
 *   - nsTArray<Param> becomes std::vector<Param>.
 *   - Get() reports "no such parameter" by clearing the out-parameter, where
 *     Gecko marks the string void.
 *   - AssignMaybeInvalidUTF8String() validates/repairs invalid UTF-8; here the
 *     bytes are passed through unchanged.
 *   - Sort() compares the keys as UTF-8 bytes.  Gecko converts them to UTF-16
 *     first, so key ordering can differ for non-ASCII keys outside the BMP.
 */

#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace network::url {

// A class for handling form-urlencoded query strings.
//
// Manages an ordered list of name-value pairs, and allows conversion from and
// to the string representation.
//
// In addition, there are static functions for handling one-shot use cases.
class UrlParams {
 public:
  // Parses a query string and calls a parameter handler for each name/value
  // pair. The parameter handler can stop processing early by returning false.
  //
  // Returns false if the parameter handler returned false for any parameter,
  // true otherwise.
  template <typename ParamHandler>
  static bool Parse(std::string_view input, bool shouldDecode,
                    ParamHandler paramHandler) {
    const char* start = input.data();
    const char* const end = input.data() + input.size();

    while (start != end) {
      std::string name;
      std::string value;

      if (!ParseNextInternal(start, end, shouldDecode, &name, &value)) {
        continue;
      }

      if (!paramHandler(std::move(name), std::move(value))) {
        return false;
      }
    }
    return true;
  }

  // Parses a query string and returns the value of a single parameter
  // specified by name.
  //
  // If there are multiple parameters with the same name, the value of the
  // first is returned.  `value` is cleared when there is no match; returns
  // true iff there was a parameter with the name.
  static bool Extract(std::string_view input, std::string_view name,
                      std::string& value);

  // Resets the state of this instance and parses a new query string.
  void ParseInput(std::string_view input);

  // Serializes the current state to a query string.  When `encode` is true the
  // serialization will encode the strings.
  void Serialize(std::string& value, bool encode) const;

  static void SerializeString(std::string_view input, std::string& value);

  void Get(std::string_view name, std::string& retval);

  void GetAll(std::string_view name, std::vector<std::string>& retval);

  // Sets the value of a given parameter.
  //
  // If one or more parameters of the name exist, the value of the first is
  // replaced, and all further parameters of the name are deleted.  Otherwise,
  // the behaviour is the same as Append().
  void Set(std::string_view name, std::string_view value);

  void Append(std::string_view name, std::string_view value);

  bool Has(std::string_view name) const;

  bool Has(std::string_view name, std::string_view value) const;

  // Deletes all parameters with the given name.
  void Delete(std::string_view name);

  void Delete(std::string_view name, std::string_view value);

  void DeleteAll() { params_.clear(); }

  uint32_t Length() const {
    return static_cast<uint32_t>(params_.size());
  }

  static void DecodeString(std::string_view input, std::string& output);

  const std::string& GetKeyAtIndex(uint32_t index) const {
    return params_[index].key;
  }

  const std::string& GetValueAtIndex(uint32_t index) const {
    return params_[index].value;
  }

  // Performs a stable sort of the parameters, maintaining the order of
  // multiple parameters with the same name.
  void Sort();

 private:
  static bool ParseNextInternal(const char*& start, const char* end,
                                bool shouldDecode, std::string* outputName,
                                std::string* outputValue);

  struct Param {
    std::string key;
    std::string value;
  };

  std::vector<Param> params_;
};

}  // namespace network::url
