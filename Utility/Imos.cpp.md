---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/Imos.cpp\"\n// description : \u3044\u3082\u3059\u6CD5\
    \ntemplate <class T> class Imos {\n\tconst int N;\n\tvector<T> table;\n\tbool\
    \ flag = false;\n\npublic:\n\tImos(int _n) : N(_n), table(_n + 1) {}\n\tvoid add(int\
    \ l, int r, T v = 1) {  // [l, r)\n\t\tassert(l < r && r <= N);\n\t\tassert(!flag);\n\
    \t\ttable[l] += v;\n\t\ttable[r] -= v;\n\t}\n\tvoid add(const pair<int, int>&\
    \ section, T v = 1) {\n\t\tadd(section.first, section.second, v);\n\t}\n\tvoid\
    \ add_closed(int l, int r, T v = 1) {\n\t\tadd(l, r + 1, v);\n\t}\n\tvoid add_closed(const\
    \ pair<int, int>& section, T v = 1) {\n\t\tadd_closed(section.first, section.second,\
    \ v);\n\t}\n\tvoid build() {\n\t\tflag = true;\n\t\tfor (int i = 1; i < N; ++i)\
    \ {\n\t\t\ttable[i] += table[i - 1];\n\t\t}\n\t}\n\tT operator[](int i) const\
    \ {\n\t\tassert(flag);\n\t\treturn table[i];\n\t}\n\tconst vector<T>& operator*()\
    \ const {\n\t\tassert(flag);\n\t\treturn table;\n\t}\n\tvector<T> to_a() const\
    \ {\n\t\treturn vector<T>(table.begin(), table.begin() + N);\n\t}\n};\n"
  code: "// description : \u3044\u3082\u3059\u6CD5\ntemplate <class T> class Imos\
    \ {\n\tconst int N;\n\tvector<T> table;\n\tbool flag = false;\n\npublic:\n\tImos(int\
    \ _n) : N(_n), table(_n + 1) {}\n\tvoid add(int l, int r, T v = 1) {  // [l, r)\n\
    \t\tassert(l < r && r <= N);\n\t\tassert(!flag);\n\t\ttable[l] += v;\n\t\ttable[r]\
    \ -= v;\n\t}\n\tvoid add(const pair<int, int>& section, T v = 1) {\n\t\tadd(section.first,\
    \ section.second, v);\n\t}\n\tvoid add_closed(int l, int r, T v = 1) {\n\t\tadd(l,\
    \ r + 1, v);\n\t}\n\tvoid add_closed(const pair<int, int>& section, T v = 1) {\n\
    \t\tadd_closed(section.first, section.second, v);\n\t}\n\tvoid build() {\n\t\t\
    flag = true;\n\t\tfor (int i = 1; i < N; ++i) {\n\t\t\ttable[i] += table[i - 1];\n\
    \t\t}\n\t}\n\tT operator[](int i) const {\n\t\tassert(flag);\n\t\treturn table[i];\n\
    \t}\n\tconst vector<T>& operator*() const {\n\t\tassert(flag);\n\t\treturn table;\n\
    \t}\n\tvector<T> to_a() const {\n\t\treturn vector<T>(table.begin(), table.begin()\
    \ + N);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Imos.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Imos.cpp
layout: document
redirect_from:
- /library/Utility/Imos.cpp
- /library/Utility/Imos.cpp.html
title: Utility/Imos.cpp
---
