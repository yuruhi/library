---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/CulSum2D.test.cpp
    title: test/CulSum2D.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/CulSum2D.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <type_traits>\n\ntemplate <class T> class CulSum2D {\n\
    public:\n\tusing value_type = T;\n\tusing data_type = std::vector<std::vector<value_type>>;\n\
    \tusing size_type = std::size_t;\n\nprivate:\n\tsize_type h, w;\n\tdata_type data;\n\
    \npublic:\n\tCulSum2D() = default;\n\tCulSum2D(const data_type& a)\n\t    : h(a.size()),\
    \ w(a.front().size()), data(h + 1, std::vector<value_type>(w + 1)) {\n\t\tfor\
    \ (size_type i = 0; i < h; ++i) {\n\t\t\tfor (size_type j = 0; j < w; ++j) {\n\
    \t\t\t\tdata[i + 1][j + 1] = data[i][j + 1] + data[i + 1][j] - data[i][j] + a[i][j];\n\
    \t\t\t}\n\t\t}\n\t}\n\ttemplate <class U, class F,\n\t          std::enable_if_t<std::is_integral_v<U>,\
    \ std::nullptr_t> = nullptr>\n\tCulSum2D(const U& _h, const U& _w, F f)\n\t  \
    \  : h(_h), w(_w), data(h + 1, std::vector<value_type>(w + 1)) {\n\t\tfor (size_type\
    \ i = 0; i < h; ++i) {\n\t\t\tfor (size_type j = 0; j < w; ++j) {\n\t\t\t\tdata[i\
    \ + 1][j + 1] = data[i][j + 1] + data[i + 1][j] - data[i][j] + f(i, j);\n\t\t\t\
    }\n\t\t}\n\t}\n\ttemplate <class U, class F,\n\t          std::enable_if_t<!std::is_integral_v<U>,\
    \ std::nullptr_t> = nullptr>\n\tCulSum2D(const U& a, F f)\n\t    : CulSum2D(a.size(),\
    \ a.front().size(),\n\t               [a, f](size_type i, size_type j) -> value_type\
    \ { return f(a[i][j]); }) {}\n\t// [y1, y2) * [x1, x2)\n\tvalue_type operator()(size_type\
    \ y1, size_type y2, size_type x1, size_type x2) const {\n\t\ty1 = std::min(y1,\
    \ h);\n\t\ty2 = std::min(y2, h);\n\t\tx1 = std::min(x1, w);\n\t\tx2 = std::min(x2,\
    \ w);\n\t\treturn (x1 > x2 || y1 > y2)\n\t\t    ? 0\n\t\t    : data[y2][x2] -\
    \ data[y1][x2] - data[y2][x1] + data[y1][x1];\n\t}\n\t// [0, y) * [0, x)\n\tvalue_type\
    \ operator()(size_type y, size_type x) const {\n\t\ty = std::min(y, h);\n\t\t\
    x = std::min(x, w);\n\t\treturn data[y][x];\n\t}\n\tconst data_type& get_data()\
    \ const {\n\t\treturn data;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <type_traits>\n\
    \ntemplate <class T> class CulSum2D {\npublic:\n\tusing value_type = T;\n\tusing\
    \ data_type = std::vector<std::vector<value_type>>;\n\tusing size_type = std::size_t;\n\
    \nprivate:\n\tsize_type h, w;\n\tdata_type data;\n\npublic:\n\tCulSum2D() = default;\n\
    \tCulSum2D(const data_type& a)\n\t    : h(a.size()), w(a.front().size()), data(h\
    \ + 1, std::vector<value_type>(w + 1)) {\n\t\tfor (size_type i = 0; i < h; ++i)\
    \ {\n\t\t\tfor (size_type j = 0; j < w; ++j) {\n\t\t\t\tdata[i + 1][j + 1] = data[i][j\
    \ + 1] + data[i + 1][j] - data[i][j] + a[i][j];\n\t\t\t}\n\t\t}\n\t}\n\ttemplate\
    \ <class U, class F,\n\t          std::enable_if_t<std::is_integral_v<U>, std::nullptr_t>\
    \ = nullptr>\n\tCulSum2D(const U& _h, const U& _w, F f)\n\t    : h(_h), w(_w),\
    \ data(h + 1, std::vector<value_type>(w + 1)) {\n\t\tfor (size_type i = 0; i <\
    \ h; ++i) {\n\t\t\tfor (size_type j = 0; j < w; ++j) {\n\t\t\t\tdata[i + 1][j\
    \ + 1] = data[i][j + 1] + data[i + 1][j] - data[i][j] + f(i, j);\n\t\t\t}\n\t\t\
    }\n\t}\n\ttemplate <class U, class F,\n\t          std::enable_if_t<!std::is_integral_v<U>,\
    \ std::nullptr_t> = nullptr>\n\tCulSum2D(const U& a, F f)\n\t    : CulSum2D(a.size(),\
    \ a.front().size(),\n\t               [a, f](size_type i, size_type j) -> value_type\
    \ { return f(a[i][j]); }) {}\n\t// [y1, y2) * [x1, x2)\n\tvalue_type operator()(size_type\
    \ y1, size_type y2, size_type x1, size_type x2) const {\n\t\ty1 = std::min(y1,\
    \ h);\n\t\ty2 = std::min(y2, h);\n\t\tx1 = std::min(x1, w);\n\t\tx2 = std::min(x2,\
    \ w);\n\t\treturn (x1 > x2 || y1 > y2)\n\t\t    ? 0\n\t\t    : data[y2][x2] -\
    \ data[y1][x2] - data[y2][x1] + data[y1][x1];\n\t}\n\t// [0, y) * [0, x)\n\tvalue_type\
    \ operator()(size_type y, size_type x) const {\n\t\ty = std::min(y, h);\n\t\t\
    x = std::min(x, w);\n\t\treturn data[y][x];\n\t}\n\tconst data_type& get_data()\
    \ const {\n\t\treturn data;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/CulSum2D.cpp
  requiredBy: []
  timestamp: '2021-03-09 16:10:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/CulSum2D.test.cpp
documentation_of: DataStructure/CulSum2D.cpp
layout: document
redirect_from:
- /library/DataStructure/CulSum2D.cpp
- /library/DataStructure/CulSum2D.cpp.html
title: DataStructure/CulSum2D.cpp
---
