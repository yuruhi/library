---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RangeAddQuery.cpp
    title: DataStructure/RangeAddQuery.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_E
  bundledCode: "#line 1 \"test/RangeAddQuery.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_E\"\
    \n#line 2 \"DataStructure/RangeAddQuery.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class RangeAddQuery\
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
    \ n; ++i) {\n\t\t\tres[i] = operator[](i);\n\t\t}\n\t\treturn res;\n\t}\n};\n\
    #line 3 \"test/RangeAddQuery.test.cpp\"\n#include <iostream>\n#line 5 \"test/RangeAddQuery.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tRangeAddQuery<int> seg(n);\n\twhile (q--) {\n\
    \t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint l, r, x;\n\t\t\t\
    cin >> l >> r >> x;\n\t\t\tseg.add(l - 1, r, x);\n\t\t} else {\n\t\t\tint i;\n\
    \t\t\tcin >> i;\n\t\t\tcout << seg[i - 1] << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_E\"\
    \n#include \"./../DataStructure/RangeAddQuery.cpp\"\n#include <iostream>\n#include\
    \ <vector>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tRangeAddQuery<int> seg(n);\n\twhile (q--) {\n\
    \t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint l, r, x;\n\t\t\t\
    cin >> l >> r >> x;\n\t\t\tseg.add(l - 1, r, x);\n\t\t} else {\n\t\t\tint i;\n\
    \t\t\tcin >> i;\n\t\t\tcout << seg[i - 1] << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - DataStructure/RangeAddQuery.cpp
  isVerificationFile: true
  path: test/RangeAddQuery.test.cpp
  requiredBy: []
  timestamp: '2020-10-06 22:30:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/RangeAddQuery.test.cpp
layout: document
redirect_from:
- /verify/test/RangeAddQuery.test.cpp
- /verify/test/RangeAddQuery.test.cpp.html
title: test/RangeAddQuery.test.cpp
---
