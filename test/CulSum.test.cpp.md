---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/CulSum.cpp
    title: Utility/CulSum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/CulSum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n#line 2 \"Utility/CulSum.cpp\"\n#include <vector>\n#include <cassert>\nusing\
    \ namespace std;\n\ntemplate <class T> class CulSum {\n\tsize_t n;\n\tvector<T>\
    \ s;\n\npublic:\n\tCulSum(const vector<T>& a) : n(a.size()), s(n + 1) {\n\t\t\
    for (size_t i = 0; i < n; ++i)\n\t\t\ts[i + 1] = s[i] + a[i];\n\t}\n\ttemplate\
    \ <class F> CulSum(int _n, F f) : n(_n), s(n + 1) {\n\t\tfor (size_t i = 0; i\
    \ < n; ++i)\n\t\t\ts[i + 1] = s[i] + static_cast<T>(f(i));\n\t}\n\ttemplate <class\
    \ U, class F> CulSum(const U& a, F f) : n(a.size()), s(n + 1) {\n\t\tfor (size_t\
    \ i = 0; i < n; ++i)\n\t\t\ts[i + 1] = s[i] + static_cast<T>(f(a[i]));\n\t}\n\t\
    // [l, r)\n\tT operator()(size_t l, size_t r) const {\n\t\treturn l > r ? 0 :\
    \ s[r] - s[l];\n\t}\n\t// [0, r)\n\tT operator()(size_t r) const {\n\t\tassert(r\
    \ <= n);\n\t\treturn s[r];\n\t}\n\tconst vector<T>& get_s() const {\n\t\treturn\
    \ s;\n\t}\n};\n#line 3 \"test/CulSum.test.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tvector<long long> a(n);\n\tfor (auto& i : a)\n\
    \t\tcin >> i;\n\n\tCulSum<long long> sum(a);\n\twhile (q--) {\n\t\tint l, r;\n\
    \t\tcin >> l >> r;\n\t\tcout << sum(l, r) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"./../Utility/CulSum.cpp\"\n#include <iostream>\nusing namespace std;\n\nint\
    \ main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint n,\
    \ q;\n\tcin >> n >> q;\n\tvector<long long> a(n);\n\tfor (auto& i : a)\n\t\tcin\
    \ >> i;\n\n\tCulSum<long long> sum(a);\n\twhile (q--) {\n\t\tint l, r;\n\t\tcin\
    \ >> l >> r;\n\t\tcout << sum(l, r) << '\\n';\n\t}\n}"
  dependsOn:
  - Utility/CulSum.cpp
  isVerificationFile: true
  path: test/CulSum.test.cpp
  requiredBy: []
  timestamp: '2020-10-04 17:42:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/CulSum.test.cpp
layout: document
redirect_from:
- /verify/test/CulSum.test.cpp
- /verify/test/CulSum.test.cpp.html
title: test/CulSum.test.cpp
---
