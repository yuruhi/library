---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/RollingHash.test.cpp
    title: test/RollingHash.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/RollingHash.cpp\"\n#include <vector>\n#include <string>\n\
    \nclass RollingHash {\npublic:\n\tusing value_type = std::uint64_t;\n\nprivate:\n\
    \tstatic constexpr value_type MASK30 = (1ul << 30) - 1;\n\tstatic constexpr value_type\
    \ MASK31 = (1ul << 31) - 1;\n\tstatic constexpr value_type MASK61 = (1ul << 61)\
    \ - 1;\n\tstatic constexpr value_type MOD = MASK61;\n\n\tstatic constexpr value_type\
    \ mul(value_type a, value_type b) {\n\t\tauto au = a >> 31, ad = a & MASK31;\n\
    \t\tauto bu = b >> 31, bd = b & MASK31;\n\t\tauto mid = ad * bu + au * bd;\n\t\
    \tauto midu = mid >> 30, midd = mid & MASK30;\n\t\treturn au * bu * 2 + midu +\
    \ (midd << 31) + ad * bd;\n\t}\n\tstatic constexpr value_type calc_mod(value_type\
    \ x) {\n\t\tauto res = (x >> 61) + (x & MASK61);\n\t\tif (res >= MOD) res -= MOD;\n\
    \t\treturn res;\n\t}\n\n\tstd::size_t n;\n\tvalue_type base;\n\tstd::vector<value_type>\
    \ pow, hash;\n\npublic:\n\tRollingHash(const std::string& s, value_type _base\
    \ = 10007)\n\t    : n(s.size()), base(_base), pow(n + 1), hash(n + 1) {\n\t\t\
    pow[0] = 1;\n\t\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tpow[i + 1] = calc_mod(mul(pow[i],\
    \ base));\n\t\t\thash[i + 1] = calc_mod(mul(hash[i], base) + s[i]);\n\t\t}\n\t\
    }\n\t// [0, right)\n\tvalue_type operator()(int right) const {\n\t\treturn hash[right];\n\
    \t}\n\t// [left, right)\n\tvalue_type operator()(int left, int right) const {\n\
    \t\treturn calc_mod(hash[right] + MOD * 4 - mul(hash[left], pow[right - left]));\n\
    \t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n\nclass RollingHash {\n\
    public:\n\tusing value_type = std::uint64_t;\n\nprivate:\n\tstatic constexpr value_type\
    \ MASK30 = (1ul << 30) - 1;\n\tstatic constexpr value_type MASK31 = (1ul << 31)\
    \ - 1;\n\tstatic constexpr value_type MASK61 = (1ul << 61) - 1;\n\tstatic constexpr\
    \ value_type MOD = MASK61;\n\n\tstatic constexpr value_type mul(value_type a,\
    \ value_type b) {\n\t\tauto au = a >> 31, ad = a & MASK31;\n\t\tauto bu = b >>\
    \ 31, bd = b & MASK31;\n\t\tauto mid = ad * bu + au * bd;\n\t\tauto midu = mid\
    \ >> 30, midd = mid & MASK30;\n\t\treturn au * bu * 2 + midu + (midd << 31) +\
    \ ad * bd;\n\t}\n\tstatic constexpr value_type calc_mod(value_type x) {\n\t\t\
    auto res = (x >> 61) + (x & MASK61);\n\t\tif (res >= MOD) res -= MOD;\n\t\treturn\
    \ res;\n\t}\n\n\tstd::size_t n;\n\tvalue_type base;\n\tstd::vector<value_type>\
    \ pow, hash;\n\npublic:\n\tRollingHash(const std::string& s, value_type _base\
    \ = 10007)\n\t    : n(s.size()), base(_base), pow(n + 1), hash(n + 1) {\n\t\t\
    pow[0] = 1;\n\t\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tpow[i + 1] = calc_mod(mul(pow[i],\
    \ base));\n\t\t\thash[i + 1] = calc_mod(mul(hash[i], base) + s[i]);\n\t\t}\n\t\
    }\n\t// [0, right)\n\tvalue_type operator()(int right) const {\n\t\treturn hash[right];\n\
    \t}\n\t// [left, right)\n\tvalue_type operator()(int left, int right) const {\n\
    \t\treturn calc_mod(hash[right] + MOD * 4 - mul(hash[left], pow[right - left]));\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/RollingHash.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:09:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/RollingHash.test.cpp
documentation_of: string/RollingHash.cpp
layout: document
redirect_from:
- /library/string/RollingHash.cpp
- /library/string/RollingHash.cpp.html
title: string/RollingHash.cpp
---
