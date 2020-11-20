---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/CulSum.test.cpp
    title: test/CulSum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/CulSum.cpp\"\n#include <vector>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class CulSum {\npublic:\n\tusing value_type\
    \ = T;\n\tusing data_type = vector<value_type>;\n\nprivate:\n\tsize_t n;\n\tdata_type\
    \ s;\n\npublic:\n\tCulSum(const data_type& a) : n(a.size()), s(n + 1) {\n\t\t\
    for (size_t i = 0; i < n; ++i) {\n\t\t\ts[i + 1] = s[i] + a[i];\n\t\t}\n\t}\n\t\
    template <class F> CulSum(int _n, F f) : n(_n), s(n + 1) {\n\t\tfor (size_t i\
    \ = 0; i < n; ++i) {\n\t\t\ts[i + 1] = s[i] + static_cast<value_type>(f(i));\n\
    \t\t}\n\t}\n\ttemplate <class U, class F>\n\tCulSum(const U& a, F f)\n\t    :\
    \ CulSum(a.size(), [a, f](size_t i, size_t j) -> value_type { return f(a[i]);\
    \ }) {\n\t}\n\t// [l, r)\n\tvalue_type operator()(size_t l, size_t r) const {\n\
    \t\tl = min(l, n);\n\t\tr = min(r, n);\n\t\treturn l > r ? 0 : s[r] - s[l];\n\t\
    }\n\t// [0, r)\n\tvalue_type operator()(size_t r) const {\n\t\tr = min(r, n);\n\
    \t\treturn s[r];\n\t}\n\tconst data_type& get_data() const {\n\t\treturn s;\n\t\
    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <class T> class CulSum {\npublic:\n\tusing value_type = T;\n\tusing\
    \ data_type = vector<value_type>;\n\nprivate:\n\tsize_t n;\n\tdata_type s;\n\n\
    public:\n\tCulSum(const data_type& a) : n(a.size()), s(n + 1) {\n\t\tfor (size_t\
    \ i = 0; i < n; ++i) {\n\t\t\ts[i + 1] = s[i] + a[i];\n\t\t}\n\t}\n\ttemplate\
    \ <class F> CulSum(int _n, F f) : n(_n), s(n + 1) {\n\t\tfor (size_t i = 0; i\
    \ < n; ++i) {\n\t\t\ts[i + 1] = s[i] + static_cast<value_type>(f(i));\n\t\t}\n\
    \t}\n\ttemplate <class U, class F>\n\tCulSum(const U& a, F f)\n\t    : CulSum(a.size(),\
    \ [a, f](size_t i, size_t j) -> value_type { return f(a[i]); }) {\n\t}\n\t// [l,\
    \ r)\n\tvalue_type operator()(size_t l, size_t r) const {\n\t\tl = min(l, n);\n\
    \t\tr = min(r, n);\n\t\treturn l > r ? 0 : s[r] - s[l];\n\t}\n\t// [0, r)\n\t\
    value_type operator()(size_t r) const {\n\t\tr = min(r, n);\n\t\treturn s[r];\n\
    \t}\n\tconst data_type& get_data() const {\n\t\treturn s;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CulSum.cpp
  requiredBy: []
  timestamp: '2020-11-21 07:08:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/CulSum.test.cpp
documentation_of: Utility/CulSum.cpp
layout: document
redirect_from:
- /library/Utility/CulSum.cpp
- /library/Utility/CulSum.cpp.html
title: Utility/CulSum.cpp
---
