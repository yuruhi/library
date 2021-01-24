---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/CulSum.test.cpp
    title: test/CulSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/CulSum.cpp\"\n#include <vector>\n#include <type_traits>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class CulSum {\n\
    public:\n\tusing value_type = T;\n\tusing data_type = vector<value_type>;\n\n\
    private:\n\tsize_t n;\n\tdata_type data;\n\npublic:\n\tCulSum() = default;\n\t\
    CulSum(const data_type& a) : n(a.size()), data(n + 1) {\n\t\tfor (size_t i = 0;\
    \ i < n; ++i) {\n\t\t\tdata[i + 1] = data[i] + a[i];\n\t\t}\n\t}\n\ttemplate <class\
    \ U, class F, enable_if_t<is_integral_v<U>, nullptr_t> = nullptr>\n\tCulSum(const\
    \ U& _n, F f) : n(_n), data(n + 1) {\n\t\tfor (size_t i = 0; i < n; ++i) {\n\t\
    \t\tdata[i + 1] = data[i] + static_cast<value_type>(f(i));\n\t\t}\n\t}\n\ttemplate\
    \ <class U, class F, enable_if_t<!is_integral_v<U>, nullptr_t> = nullptr>\n\t\
    CulSum(const U& a, F f)\n\t    : CulSum(a.size(), [a, f](size_t i) -> value_type\
    \ { return f(a[i]); }) {}\n\tsize_t size() const {\n\t\treturn n;\n\t}\n\tvalue_type\
    \ at(size_t i) const {\n\t\treturn operator()(i, i + 1);\n\t}\n\t// [l, r)\n\t\
    value_type operator()(size_t l, size_t r) const {\n\t\tl = min(l, n);\n\t\tr =\
    \ min(r, n);\n\t\treturn l > r ? 0 : data[r] - data[l];\n\t}\n\t// [0, r)\n\t\
    value_type operator()(size_t r) const {\n\t\tr = min(r, n);\n\t\treturn data[r];\n\
    \t}\n\tconst data_type& get_data() const {\n\t\treturn data;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <type_traits>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class CulSum {\npublic:\n\tusing value_type\
    \ = T;\n\tusing data_type = vector<value_type>;\n\nprivate:\n\tsize_t n;\n\tdata_type\
    \ data;\n\npublic:\n\tCulSum() = default;\n\tCulSum(const data_type& a) : n(a.size()),\
    \ data(n + 1) {\n\t\tfor (size_t i = 0; i < n; ++i) {\n\t\t\tdata[i + 1] = data[i]\
    \ + a[i];\n\t\t}\n\t}\n\ttemplate <class U, class F, enable_if_t<is_integral_v<U>,\
    \ nullptr_t> = nullptr>\n\tCulSum(const U& _n, F f) : n(_n), data(n + 1) {\n\t\
    \tfor (size_t i = 0; i < n; ++i) {\n\t\t\tdata[i + 1] = data[i] + static_cast<value_type>(f(i));\n\
    \t\t}\n\t}\n\ttemplate <class U, class F, enable_if_t<!is_integral_v<U>, nullptr_t>\
    \ = nullptr>\n\tCulSum(const U& a, F f)\n\t    : CulSum(a.size(), [a, f](size_t\
    \ i) -> value_type { return f(a[i]); }) {}\n\tsize_t size() const {\n\t\treturn\
    \ n;\n\t}\n\tvalue_type at(size_t i) const {\n\t\treturn operator()(i, i + 1);\n\
    \t}\n\t// [l, r)\n\tvalue_type operator()(size_t l, size_t r) const {\n\t\tl =\
    \ min(l, n);\n\t\tr = min(r, n);\n\t\treturn l > r ? 0 : data[r] - data[l];\n\t\
    }\n\t// [0, r)\n\tvalue_type operator()(size_t r) const {\n\t\tr = min(r, n);\n\
    \t\treturn data[r];\n\t}\n\tconst data_type& get_data() const {\n\t\treturn data;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CulSum.cpp
  requiredBy: []
  timestamp: '2020-12-12 20:18:02+09:00'
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
