---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/CulSum.cpp
    title: DataStructure/CulSum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/CulSum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n#line 2 \"DataStructure/CulSum.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <type_traits>\n\ntemplate <class T> class CulSum {\npublic:\n\tusing\
    \ value_type = T;\n\tusing data_type = std::vector<value_type>;\n\tusing size_type\
    \ = std::size_t;\n\nprivate:\n\tsize_type n;\n\tdata_type data;\n\npublic:\n\t\
    CulSum() = default;\n\tCulSum(const data_type& a) : n(a.size()), data(n + 1) {\n\
    \t\tfor (size_type i = 0; i < n; ++i) {\n\t\t\tdata[i + 1] = data[i] + a[i];\n\
    \t\t}\n\t}\n\ttemplate <class U, class F,\n\t          std::enable_if_t<std::is_integral_v<U>,\
    \ std::nullptr_t> = nullptr>\n\tCulSum(const U& _n, F f) : n(_n), data(n + 1)\
    \ {\n\t\tfor (size_type i = 0; i < n; ++i) {\n\t\t\tdata[i + 1] = data[i] + static_cast<value_type>(f(i));\n\
    \t\t}\n\t}\n\ttemplate <class U, class F,\n\t          std::enable_if_t<!std::is_integral_v<U>,\
    \ std::nullptr_t> = nullptr>\n\tCulSum(const U& a, F f)\n\t    : CulSum(a.size(),\
    \ [a, f](size_type i) -> value_type { return f(a[i]); }) {}\n\tsize_type size()\
    \ const {\n\t\treturn n;\n\t}\n\tvalue_type at(size_type i) const {\n\t\treturn\
    \ operator()(i, i + 1);\n\t}\n\t// [l, r)\n\tvalue_type operator()(size_type l,\
    \ size_type r) const {\n\t\tl = std::min(l, n);\n\t\tr = std::min(r, n);\n\t\t\
    return l > r ? 0 : data[r] - data[l];\n\t}\n\t// [0, r)\n\tvalue_type operator()(size_type\
    \ r) const {\n\t\tr = std::min(r, n);\n\t\treturn data[r];\n\t}\n\tconst data_type&\
    \ get_data() const {\n\t\treturn data;\n\t}\n};\n#line 3 \"test/CulSum.test.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n, q;\n\tcin >> n >> q;\n\tvector<long\
    \ long> a(n);\n\tfor (auto& i : a) cin >> i;\n\n\tCulSum<long long> sum(a);\n\t\
    while (q--) {\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tcout << sum(l, r) << '\\\
    n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"./../DataStructure/CulSum.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint\
    \ n, q;\n\tcin >> n >> q;\n\tvector<long long> a(n);\n\tfor (auto& i : a) cin\
    \ >> i;\n\n\tCulSum<long long> sum(a);\n\twhile (q--) {\n\t\tint l, r;\n\t\tcin\
    \ >> l >> r;\n\t\tcout << sum(l, r) << '\\n';\n\t}\n}"
  dependsOn:
  - DataStructure/CulSum.cpp
  isVerificationFile: true
  path: test/CulSum.test.cpp
  requiredBy: []
  timestamp: '2021-03-09 16:10:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/CulSum.test.cpp
layout: document
redirect_from:
- /verify/test/CulSum.test.cpp
- /verify/test/CulSum.test.cpp.html
title: test/CulSum.test.cpp
---
