---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/RangeUpdateQuery.cpp\"\n#include <vector>\n\
    #include <utility>\nusing namespace std;\n\ntemplate <class T> class RangeUpdateQuery\
    \ {\n\tint n;\n\tvector<pair<size_t, T>> a;\n\tsize_t update_count = 1;\n\tstatic\
    \ int ceil2(int n) {\n\t\tint m = 1;\n\t\twhile (m < n)\n\t\t\tm *= 2;\n\t\treturn\
    \ m;\n\t}\n\npublic:\n\tRangeUpdateQuery(int _n, const T& init) : n(ceil2(_n)),\
    \ a(n * 2, make_pair(0, init)) {}\n\tRangeUpdateQuery(const vector<T>& v) : n(ceil2(v.size())),\
    \ a(n * 2) {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\ta[i + n] = make_pair(0,\
    \ v[i]);\n\t\t}\n\t}\n\tvoid update(int l, int r, const T& x) {\n\t\tfor (l +=\
    \ n, r += n; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) a[l++] = make_pair(update_count,\
    \ x);\n\t\t\tif (r & 1) a[--r] = make_pair(update_count, x);\n\t\t}\n\t\tupdate_count++;\n\
    \t}\n\tT operator[](int i) {\n\t\tauto [max_count, res] = a[i += n];\n\t\twhile\
    \ (i >>= 1) {\n\t\t\tif (max_count < a[i].first) {\n\t\t\t\tmax_count = a[i].first;\n\
    \t\t\t\tres = a[i].second;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tvector<T>\
    \ to_a() {\n\t\tvector<T> res(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i]\
    \ = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\nusing namespace std;\n\
    \ntemplate <class T> class RangeUpdateQuery {\n\tint n;\n\tvector<pair<size_t,\
    \ T>> a;\n\tsize_t update_count = 1;\n\tstatic int ceil2(int n) {\n\t\tint m =\
    \ 1;\n\t\twhile (m < n)\n\t\t\tm *= 2;\n\t\treturn m;\n\t}\n\npublic:\n\tRangeUpdateQuery(int\
    \ _n, const T& init) : n(ceil2(_n)), a(n * 2, make_pair(0, init)) {}\n\tRangeUpdateQuery(const\
    \ vector<T>& v) : n(ceil2(v.size())), a(n * 2) {\n\t\tfor (size_t i = 0; i < v.size();\
    \ ++i) {\n\t\t\ta[i + n] = make_pair(0, v[i]);\n\t\t}\n\t}\n\tvoid update(int\
    \ l, int r, const T& x) {\n\t\tfor (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n\
    \t\t\tif (l & 1) a[l++] = make_pair(update_count, x);\n\t\t\tif (r & 1) a[--r]\
    \ = make_pair(update_count, x);\n\t\t}\n\t\tupdate_count++;\n\t}\n\tT operator[](int\
    \ i) {\n\t\tauto [max_count, res] = a[i += n];\n\t\twhile (i >>= 1) {\n\t\t\t\
    if (max_count < a[i].first) {\n\t\t\t\tmax_count = a[i].first;\n\t\t\t\tres =\
    \ a[i].second;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tvector<T> to_a() {\n\t\
    \tvector<T> res(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i] = operator[](i);\n\
    \t\t}\n\t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RangeUpdateQuery.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/RangeUpdateQuery.cpp
layout: document
redirect_from:
- /library/DataStructure/RangeUpdateQuery.cpp
- /library/DataStructure/RangeUpdateQuery.cpp.html
title: DataStructure/RangeUpdateQuery.cpp
---
