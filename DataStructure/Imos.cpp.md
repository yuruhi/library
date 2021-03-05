---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Imos.test.cpp
    title: test/Imos.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/Imos.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <algorithm>\n#include <cassert>\n\ntemplate <class T> class Imos {\n\
    public:\n\tusing value_type = T;\n\nprivate:\n\tint n;\n\tstd::vector<value_type>\
    \ table;\n\tbool builded = false;\n\npublic:\n\tImos() = default;\n\tImos(int\
    \ _n) : n(_n), table(_n + 1) {}\n\tvoid add(int l, int r, value_type v = 1) {\n\
    \t\tassert(!builded);\n\t\tl = std::clamp(l, 0, n);\n\t\tr = std::clamp(r, 0,\
    \ n);\n\t\tif (l < r) {\n\t\t\ttable[l] += v;\n\t\t\ttable[r] -= v;\n\t\t}\n\t\
    }\n\tvoid add(const std::pair<int, int>& section, value_type v = 1) {\n\t\tadd(section.first,\
    \ section.second, v);\n\t}\n\tvoid add_closed(int l, int r, value_type v = 1)\
    \ {\n\t\tadd(l, r + 1, v);\n\t}\n\tvoid add_closed(const std::pair<int, int>&\
    \ section, value_type v = 1) {\n\t\tadd_closed(section.first, section.second,\
    \ v);\n\t}\n\tvoid build() {\n\t\tbuilded = true;\n\t\tfor (int i = 1; i < n;\
    \ ++i) {\n\t\t\ttable[i] += table[i - 1];\n\t\t}\n\t}\n\tvalue_type operator[](int\
    \ i) const {\n\t\tassert(builded);\n\t\treturn table[i];\n\t}\n\tconst std::vector<value_type>&\
    \ operator*() const {\n\t\tassert(builded);\n\t\treturn table;\n\t}\n\tstd::vector<value_type>\
    \ to_a() const {\n\t\treturn std::vector(table.begin(), table.begin() + n);\n\t\
    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <cassert>\n\ntemplate <class T> class Imos {\npublic:\n\tusing value_type\
    \ = T;\n\nprivate:\n\tint n;\n\tstd::vector<value_type> table;\n\tbool builded\
    \ = false;\n\npublic:\n\tImos() = default;\n\tImos(int _n) : n(_n), table(_n +\
    \ 1) {}\n\tvoid add(int l, int r, value_type v = 1) {\n\t\tassert(!builded);\n\
    \t\tl = std::clamp(l, 0, n);\n\t\tr = std::clamp(r, 0, n);\n\t\tif (l < r) {\n\
    \t\t\ttable[l] += v;\n\t\t\ttable[r] -= v;\n\t\t}\n\t}\n\tvoid add(const std::pair<int,\
    \ int>& section, value_type v = 1) {\n\t\tadd(section.first, section.second, v);\n\
    \t}\n\tvoid add_closed(int l, int r, value_type v = 1) {\n\t\tadd(l, r + 1, v);\n\
    \t}\n\tvoid add_closed(const std::pair<int, int>& section, value_type v = 1) {\n\
    \t\tadd_closed(section.first, section.second, v);\n\t}\n\tvoid build() {\n\t\t\
    builded = true;\n\t\tfor (int i = 1; i < n; ++i) {\n\t\t\ttable[i] += table[i\
    \ - 1];\n\t\t}\n\t}\n\tvalue_type operator[](int i) const {\n\t\tassert(builded);\n\
    \t\treturn table[i];\n\t}\n\tconst std::vector<value_type>& operator*() const\
    \ {\n\t\tassert(builded);\n\t\treturn table;\n\t}\n\tstd::vector<value_type> to_a()\
    \ const {\n\t\treturn std::vector(table.begin(), table.begin() + n);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Imos.cpp
  requiredBy: []
  timestamp: '2021-03-05 15:06:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Imos.test.cpp
documentation_of: DataStructure/Imos.cpp
layout: document
redirect_from:
- /library/DataStructure/Imos.cpp
- /library/DataStructure/Imos.cpp.html
title: DataStructure/Imos.cpp
---
