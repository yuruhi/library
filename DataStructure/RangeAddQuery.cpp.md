---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/RangeAddQuery.cpp\"\n// description : \u533A\
    \u9593\u52A0\u7B97\u3001\u4E00\u70B9\u53D6\u5F97\ntemplate <class T> class RangeAddQuery\
    \ {\n\tint n;\n\tvector<T> a;\n\tstatic int ceil2(int n) {\n\t\tint m = 1;\n\t\
    \twhile (m < n)\n\t\t\tm *= 2;\n\t\treturn m;\n\t}\n\npublic:\n\tRangeAddQuery(int\
    \ _n) : n(ceil2(_n)), a(n * 2) {}\n\tRangeAddQuery(const vector<T>& v) : n(ceil2(v.size())),\
    \ a(n * 2) {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\ta[i + n] = v[i];\n\
    \t\t}\n\t}\n\tvoid add(int l, int r, const T& x) {\n\t\tl = clamp(l, 0, n);\n\t\
    \tr = clamp(r, 0, n);\n\t\tif (l >= r) return;\n\t\tfor (l += n, r += n; l < r;\
    \ l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) a[l++] += x;\n\t\t\tif (r & 1) a[--r]\
    \ += x;\n\t\t}\n\t}\n\tvoid add(int i, const T& x) {\n\t\tadd(i, i + 1, x);\n\t\
    }\n\tT operator[](int i) const {\n\t\tassert(0 <= i && i < n);\n\t\tT res = a[i\
    \ += n];\n\t\twhile (i >>= 1) {\n\t\t\tres += a[i];\n\t\t}\n\t\treturn res;\n\t\
    }\n\tvector<T> to_a() const {\n\t\tvector<T> res(n);\n\t\tfor (int i = 0; i <\
    \ n; ++i) {\n\t\t\tres[i] = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "// description : \u533A\u9593\u52A0\u7B97\u3001\u4E00\u70B9\u53D6\u5F97\n\
    template <class T> class RangeAddQuery {\n\tint n;\n\tvector<T> a;\n\tstatic int\
    \ ceil2(int n) {\n\t\tint m = 1;\n\t\twhile (m < n)\n\t\t\tm *= 2;\n\t\treturn\
    \ m;\n\t}\n\npublic:\n\tRangeAddQuery(int _n) : n(ceil2(_n)), a(n * 2) {}\n\t\
    RangeAddQuery(const vector<T>& v) : n(ceil2(v.size())), a(n * 2) {\n\t\tfor (size_t\
    \ i = 0; i < v.size(); ++i) {\n\t\t\ta[i + n] = v[i];\n\t\t}\n\t}\n\tvoid add(int\
    \ l, int r, const T& x) {\n\t\tl = clamp(l, 0, n);\n\t\tr = clamp(r, 0, n);\n\t\
    \tif (l >= r) return;\n\t\tfor (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n\t\
    \t\tif (l & 1) a[l++] += x;\n\t\t\tif (r & 1) a[--r] += x;\n\t\t}\n\t}\n\tvoid\
    \ add(int i, const T& x) {\n\t\tadd(i, i + 1, x);\n\t}\n\tT operator[](int i)\
    \ const {\n\t\tassert(0 <= i && i < n);\n\t\tT res = a[i += n];\n\t\twhile (i\
    \ >>= 1) {\n\t\t\tres += a[i];\n\t\t}\n\t\treturn res;\n\t}\n\tvector<T> to_a()\
    \ const {\n\t\tvector<T> res(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i]\
    \ = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RangeAddQuery.cpp
  requiredBy: []
  timestamp: '2020-09-22 22:26:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/RangeAddQuery.cpp
layout: document
redirect_from:
- /library/DataStructure/RangeAddQuery.cpp
- /library/DataStructure/RangeAddQuery.cpp.html
title: DataStructure/RangeAddQuery.cpp
---
