---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: old/RangeAddQuery.test.cpp
    title: old/RangeAddQuery.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"old/RangeAddQuery.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class RangeAddQuery\
    \ {\n\tint n;\n\tvector<T> a;\n\tstatic int ceil2(int n) {\n\t\tint m = 1;\n\t\
    \twhile (m < n) m *= 2;\n\t\treturn m;\n\t}\n\npublic:\n\tRangeAddQuery(int _n)\
    \ : n(ceil2(_n)), a(n * 2) {}\n\tRangeAddQuery(const vector<T>& v) : n(ceil2(v.size())),\
    \ a(n * 2) {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\ta[i + n] = v[i];\n\
    \t\t}\n\t}\n\tvoid add(int l, int r, const T& x) {\n\t\tl = clamp(l, 0, n);\n\t\
    \tr = clamp(r, 0, n);\n\t\tif (l >= r) return;\n\t\tfor (l += n, r += n; l < r;\
    \ l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) a[l++] += x;\n\t\t\tif (r & 1) a[--r]\
    \ += x;\n\t\t}\n\t}\n\tvoid add(int i, const T& x) {\n\t\tadd(i, i + 1, x);\n\t\
    }\n\tT operator[](int i) const {\n\t\tassert(0 <= i && i < n);\n\t\tT res = a[i\
    \ += n];\n\t\twhile (i >>= 1) {\n\t\t\tres += a[i];\n\t\t}\n\t\treturn res;\n\t\
    }\n\tvector<T> to_a() const {\n\t\tvector<T> res(n);\n\t\tfor (int i = 0; i <\
    \ n; ++i) {\n\t\t\tres[i] = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class RangeAddQuery {\n\tint n;\n\t\
    vector<T> a;\n\tstatic int ceil2(int n) {\n\t\tint m = 1;\n\t\twhile (m < n) m\
    \ *= 2;\n\t\treturn m;\n\t}\n\npublic:\n\tRangeAddQuery(int _n) : n(ceil2(_n)),\
    \ a(n * 2) {}\n\tRangeAddQuery(const vector<T>& v) : n(ceil2(v.size())), a(n *\
    \ 2) {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\ta[i + n] = v[i];\n\t\
    \t}\n\t}\n\tvoid add(int l, int r, const T& x) {\n\t\tl = clamp(l, 0, n);\n\t\t\
    r = clamp(r, 0, n);\n\t\tif (l >= r) return;\n\t\tfor (l += n, r += n; l < r;\
    \ l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) a[l++] += x;\n\t\t\tif (r & 1) a[--r]\
    \ += x;\n\t\t}\n\t}\n\tvoid add(int i, const T& x) {\n\t\tadd(i, i + 1, x);\n\t\
    }\n\tT operator[](int i) const {\n\t\tassert(0 <= i && i < n);\n\t\tT res = a[i\
    \ += n];\n\t\twhile (i >>= 1) {\n\t\t\tres += a[i];\n\t\t}\n\t\treturn res;\n\t\
    }\n\tvector<T> to_a() const {\n\t\tvector<T> res(n);\n\t\tfor (int i = 0; i <\
    \ n; ++i) {\n\t\t\tres[i] = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/RangeAddQuery.cpp
  requiredBy: []
  timestamp: '2021-01-02 15:13:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - old/RangeAddQuery.test.cpp
documentation_of: old/RangeAddQuery.cpp
layout: document
redirect_from:
- /library/old/RangeAddQuery.cpp
- /library/old/RangeAddQuery.cpp.html
title: old/RangeAddQuery.cpp
---
