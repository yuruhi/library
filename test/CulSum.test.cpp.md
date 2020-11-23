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
    \n#line 2 \"Utility/CulSum.cpp\"\n#include <vector>\n#include <type_traits>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class CulSum {\n\
    public:\n\tusing value_type = T;\n\tusing data_type = vector<value_type>;\n\n\
    private:\n\tsize_t n;\n\tdata_type data;\n\npublic:\n\tCulSum(const data_type&\
    \ a) : n(a.size()), data(n + 1) {\n\t\tfor (size_t i = 0; i < n; ++i) {\n\t\t\t\
    data[i + 1] = data[i] + a[i];\n\t\t}\n\t}\n\ttemplate <class U, class F, enable_if_t<is_integral<U>::value,\
    \ nullptr_t> = nullptr>\n\tCulSum(const U& _n, F f) : n(_n), data(n + 1) {\n\t\
    \tfor (size_t i = 0; i < n; ++i) {\n\t\t\tdata[i + 1] = data[i] + static_cast<value_type>(f(i));\n\
    \t\t}\n\t}\n\ttemplate <class U, class F, enable_if_t<!is_integral<U>::value,\
    \ nullptr_t> = nullptr>\n\tCulSum(const U& a, F f)\n\t    : CulSum(a.size(), [a,\
    \ f](size_t i) -> value_type { return f(a[i]); }) {}\n\tsize_t size() const {\n\
    \t\treturn n;\n\t}\n\t// [l, r)\n\tvalue_type operator()(size_t l, size_t r) const\
    \ {\n\t\tl = min(l, n);\n\t\tr = min(r, n);\n\t\treturn l > r ? 0 : data[r] -\
    \ data[l];\n\t}\n\t// [0, r)\n\tvalue_type operator()(size_t r) const {\n\t\t\
    r = min(r, n);\n\t\treturn data[r];\n\t}\n\tconst data_type& get_data() const\
    \ {\n\t\treturn data;\n\t}\n};\n#line 3 \"test/CulSum.test.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tvector<long long> a(n);\n\tfor (auto& i : a)\
    \ cin >> i;\n\n\tCulSum<long long> sum(a);\n\twhile (q--) {\n\t\tint l, r;\n\t\
    \tcin >> l >> r;\n\t\tcout << sum(l, r) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"./../Utility/CulSum.cpp\"\n#include <iostream>\nusing namespace std;\n\nint\
    \ main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint n,\
    \ q;\n\tcin >> n >> q;\n\tvector<long long> a(n);\n\tfor (auto& i : a) cin >>\
    \ i;\n\n\tCulSum<long long> sum(a);\n\twhile (q--) {\n\t\tint l, r;\n\t\tcin >>\
    \ l >> r;\n\t\tcout << sum(l, r) << '\\n';\n\t}\n}"
  dependsOn:
  - Utility/CulSum.cpp
  isVerificationFile: true
  path: test/CulSum.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 10:07:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/CulSum.test.cpp
layout: document
redirect_from:
- /verify/test/CulSum.test.cpp
- /verify/test/CulSum.test.cpp.html
title: test/CulSum.test.cpp
---
