#pragma once

#include <string>
#include <unordered_map>
#include "gc_cpp.h"
#include "gc_allocator.h"

namespace yuzu {
namespace symbol {

using ::std::string;
using ::std::unordered_map;
using ::std::hash;
using ::std::equal_to;
using ::std::pair;
using ::std::make_pair;

class Symbol;
typedef unordered_map<
  string,
  Symbol const *,
  hash<string>,
  equal_to<string>,
  gc_allocator<pair<string const, Symbol const *>>
  > SymbolTable;

class Symbol final : public gc {
public:
  ~Symbol() = default;

  static Symbol const *Intern(char const *str) {
    static SymbolTable symbol_table;
    SymbolTable::const_iterator got = symbol_table.find(str);
    if (got == symbol_table.end()) {
      Symbol const *new_symbol = new Symbol(str);
      symbol_table.insert(make_pair(str, new_symbol));
      return new_symbol;
    }
    return got->second;
  }
  
private:
  explicit Symbol(char const *str) : m_str(str) {}
  Symbol(Symbol const &) = delete;
  Symbol(Symbol &&) = delete;
  Symbol &operator=(Symbol const &) = delete;
  Symbol &operator=(Symbol &&) = delete;

  char const *const m_str;
};

} // namespace symbol
} // namespace yuzu
