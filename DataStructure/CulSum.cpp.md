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
  bundledCode: "#line 2 \"DataStructure/CulSum.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <type_traits>\n\ntemplate <class T> class CulSum {\npublic:\n\
    \tusing value_type = T;\n\tusing data_type = std::vector<value_type>;\n\tusing\
    \ size_type = std::size_t;\n\nprivate:\n\tsize_type n;\n\tdata_type data;\n\n\
    public:\n\tCulSum() = default;\n\tCulSum(const data_type& a) : n(a.size()), data(n\
    \ + 1) {\n\t\tfor (size_type i = 0; i < n; ++i) {\n\t\t\tdata[i + 1] = data[i]\
    \ + a[i];\n\t\t}\n\t}\n\ttemplate <class U, class F,\n\t          std::enable_if_t<std::is_integral_v<U>,\
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
    \ get_data() const {\n\t\treturn data;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <type_traits>\n\
    \ntemplate <class T> class CulSum {\npublic:\n\tusing value_type = T;\n\tusing\
    \ data_type = std::vector<value_type>;\n\tusing size_type = std::size_t;\n\nprivate:\n\
    \tsize_type n;\n\tdata_type data;\n\npublic:\n\tCulSum() = default;\n\tCulSum(const\
    \ data_type& a) : n(a.size()), data(n + 1) {\n\t\tfor (size_type i = 0; i < n;\
    \ ++i) {\n\t\t\tdata[i + 1] = data[i] + a[i];\n\t\t}\n\t}\n\ttemplate <class U,\
    \ class F,\n\t          std::enable_if_t<std::is_integral_v<U>, std::nullptr_t>\
    \ = nullptr>\n\tCulSum(const U& _n, F f) : n(_n), data(n + 1) {\n\t\tfor (size_type\
    \ i = 0; i < n; ++i) {\n\t\t\tdata[i + 1] = data[i] + static_cast<value_type>(f(i));\n\
    \t\t}\n\t}\n\ttemplate <class U, class F,\n\t          std::enable_if_t<!std::is_integral_v<U>,\
    \ std::nullptr_t> = nullptr>\n\tCulSum(const U& a, F f)\n\t    : CulSum(a.size(),\
    \ [a, f](size_type i) -> value_type { return f(a[i]); }) {}\n\tsize_type size()\
    \ const {\n\t\treturn n;\n\t}\n\tvalue_type at(size_type i) const {\n\t\treturn\
    \ operator()(i, i + 1);\n\t}\n\t// [l, r)\n\tvalue_type operator()(size_type l,\
    \ size_type r) const {\n\t\tl = std::min(l, n);\n\t\tr = std::min(r, n);\n\t\t\
    return l > r ? 0 : data[r] - data[l];\n\t}\n\t// [0, r)\n\tvalue_type operator()(size_type\
    \ r) const {\n\t\tr = std::min(r, n);\n\t\treturn data[r];\n\t}\n\tconst data_type&\
    \ get_data() const {\n\t\treturn data;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/CulSum.cpp
  requiredBy: []
  timestamp: '2021-03-09 16:10:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/CulSum.test.cpp
documentation_of: DataStructure/CulSum.cpp
layout: document
redirect_from:
- /library/DataStructure/CulSum.cpp
- /library/DataStructure/CulSum.cpp.html
title: DataStructure/CulSum.cpp
---
