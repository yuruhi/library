---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: old/RangeUpdateQuery.cpp
    title: old/RangeUpdateQuery.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D
  bundledCode: "#line 1 \"old/RangeUpdateQuery.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D\"\
    \n#line 2 \"old/RangeUpdateQuery.cpp\"\n#include <vector>\n#include <utility>\n\
    using namespace std;\n\ntemplate <class T> class RangeUpdateQuery {\n\tint n;\n\
    \tvector<pair<size_t, T>> a;\n\tsize_t update_count = 1;\n\tstatic int ceil2(int\
    \ n) {\n\t\tint m = 1;\n\t\twhile (m < n) m *= 2;\n\t\treturn m;\n\t}\n\npublic:\n\
    \tRangeUpdateQuery(int _n, const T& init) : n(ceil2(_n)), a(n * 2, make_pair(0,\
    \ init)) {}\n\tRangeUpdateQuery(const vector<T>& v) : n(ceil2(v.size())), a(n\
    \ * 2) {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\ta[i + n] = make_pair(0,\
    \ v[i]);\n\t\t}\n\t}\n\tvoid update(int l, int r, const T& x) {\n\t\tfor (l +=\
    \ n, r += n; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) a[l++] = make_pair(update_count,\
    \ x);\n\t\t\tif (r & 1) a[--r] = make_pair(update_count, x);\n\t\t}\n\t\tupdate_count++;\n\
    \t}\n\tT operator[](int i) const {\n\t\tauto [max_count, res] = a[i += n];\n\t\
    \twhile (i >>= 1) {\n\t\t\tif (max_count < a[i].first) {\n\t\t\t\tmax_count =\
    \ a[i].first;\n\t\t\t\tres = a[i].second;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t\
    }\n\tvector<T> to_a() const {\n\t\tvector<T> res(n);\n\t\tfor (int i = 0; i <\
    \ n; ++i) {\n\t\t\tres[i] = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};\n\
    #line 3 \"old/RangeUpdateQuery.test.cpp\"\n#include <iostream>\n#include <limits>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tRangeUpdateQuery<int> seg(n, numeric_limits<int>::max());\n\
    \twhile (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint\
    \ l, r, x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tseg.update(l, r + 1, x);\n\t\t} else\
    \ {\n\t\t\tint i;\n\t\t\tcin >> i;\n\t\t\tcout << seg[i] << '\\n';\n\t\t}\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D\"\
    \n#include \"./../old/RangeUpdateQuery.cpp\"\n#include <iostream>\n#include <limits>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tRangeUpdateQuery<int> seg(n, numeric_limits<int>::max());\n\
    \twhile (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint\
    \ l, r, x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tseg.update(l, r + 1, x);\n\t\t} else\
    \ {\n\t\t\tint i;\n\t\t\tcin >> i;\n\t\t\tcout << seg[i] << '\\n';\n\t\t}\n\t\
    }\n}"
  dependsOn:
  - old/RangeUpdateQuery.cpp
  isVerificationFile: true
  path: old/RangeUpdateQuery.test.cpp
  requiredBy: []
  timestamp: '2021-01-02 15:13:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: old/RangeUpdateQuery.test.cpp
layout: document
redirect_from:
- /verify/old/RangeUpdateQuery.test.cpp
- /verify/old/RangeUpdateQuery.test.cpp.html
title: old/RangeUpdateQuery.test.cpp
---
