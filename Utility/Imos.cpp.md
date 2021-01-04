---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Imos.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <algorithm>\n#include <cassert>\nusing namespace std;\n\ntemplate <class\
    \ T> class Imos {\npublic:\n\tusing value_type = T;\n\nprivate:\n\tint N;\n\t\
    vector<value_type> table;\n\tbool builded = false;\n\npublic:\n\tImos() = default;\n\
    \tImos(int _n) : N(_n), table(_n + 1) {}\n\tvoid add(int l, int r, value_type\
    \ v = 1) {\n\t\tassert(!builded);\n\t\tl = clamp(l, 0, N);\n\t\tr = clamp(r, 0,\
    \ N);\n\t\tif (l < r) {\n\t\t\ttable[l] += v;\n\t\t\ttable[r] -= v;\n\t\t}\n\t\
    }\n\tvoid add(const pair<int, int>& section, value_type v = 1) {\n\t\tadd(section.first,\
    \ section.second, v);\n\t}\n\tvoid add_closed(int l, int r, value_type v = 1)\
    \ {\n\t\tadd(l, r + 1, v);\n\t}\n\tvoid add_closed(const pair<int, int>& section,\
    \ value_type v = 1) {\n\t\tadd_closed(section.first, section.second, v);\n\t}\n\
    \tvoid build() {\n\t\tbuilded = true;\n\t\tfor (int i = 1; i < N; ++i) {\n\t\t\
    \ttable[i] += table[i - 1];\n\t\t}\n\t}\n\tvalue_type operator[](int i) const\
    \ {\n\t\tassert(builded);\n\t\treturn table[i];\n\t}\n\tconst vector<value_type>&\
    \ operator*() const {\n\t\tassert(builded);\n\t\treturn table;\n\t}\n\tvector<value_type>\
    \ to_a() const {\n\t\treturn vector(table.begin(), table.begin() + N);\n\t}\n\
    };\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class Imos {\n\
    public:\n\tusing value_type = T;\n\nprivate:\n\tint N;\n\tvector<value_type> table;\n\
    \tbool builded = false;\n\npublic:\n\tImos() = default;\n\tImos(int _n) : N(_n),\
    \ table(_n + 1) {}\n\tvoid add(int l, int r, value_type v = 1) {\n\t\tassert(!builded);\n\
    \t\tl = clamp(l, 0, N);\n\t\tr = clamp(r, 0, N);\n\t\tif (l < r) {\n\t\t\ttable[l]\
    \ += v;\n\t\t\ttable[r] -= v;\n\t\t}\n\t}\n\tvoid add(const pair<int, int>& section,\
    \ value_type v = 1) {\n\t\tadd(section.first, section.second, v);\n\t}\n\tvoid\
    \ add_closed(int l, int r, value_type v = 1) {\n\t\tadd(l, r + 1, v);\n\t}\n\t\
    void add_closed(const pair<int, int>& section, value_type v = 1) {\n\t\tadd_closed(section.first,\
    \ section.second, v);\n\t}\n\tvoid build() {\n\t\tbuilded = true;\n\t\tfor (int\
    \ i = 1; i < N; ++i) {\n\t\t\ttable[i] += table[i - 1];\n\t\t}\n\t}\n\tvalue_type\
    \ operator[](int i) const {\n\t\tassert(builded);\n\t\treturn table[i];\n\t}\n\
    \tconst vector<value_type>& operator*() const {\n\t\tassert(builded);\n\t\treturn\
    \ table;\n\t}\n\tvector<value_type> to_a() const {\n\t\treturn vector(table.begin(),\
    \ table.begin() + N);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Imos.cpp
  requiredBy: []
  timestamp: '2020-11-23 22:18:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Imos.cpp
layout: document
redirect_from:
- /library/Utility/Imos.cpp
- /library/Utility/Imos.cpp.html
title: Utility/Imos.cpp
---