---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/CulSum2D.test.cpp
    title: test/CulSum2D.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/CulSum2D.cpp\"\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n\ntemplate <class T> class CulSum2D {\npublic:\n\tusing\
    \ value_type = T;\n\tusing data_type = vector<vector<value_type>>;\n\nprivate:\n\
    \tsize_t h, w;\n\tvector<vector<T>> data;\n\npublic:\n\tCulSum2D(const data_type&\
    \ a)\n\t    : h(a.size()), w(a.front().size()), data(h + 1, vector<value_type>(w\
    \ + 1)) {\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\tfor (size_t j = 0; j <\
    \ w; ++j) {\n\t\t\t\tdata[i + 1][j + 1] =\n\t\t\t\t    data[i][j + 1] + data[i\
    \ + 1][j] - data[i][j] + a[i][j];\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class U, class\
    \ F, enable_if_t<is_integral_v<U>, nullptr_t> = nullptr>\n\tCulSum2D(const U&\
    \ _h, const U& _w, F f)\n\t    : h(_h), w(_w), data(h + 1, vector<value_type>(w\
    \ + 1)) {\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\tfor (size_t j = 0; j <\
    \ w; ++j) {\n\t\t\t\tdata[i + 1][j + 1] =\n\t\t\t\t    data[i][j + 1] + data[i\
    \ + 1][j] - data[i][j] + f(i, j);\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class U, class\
    \ F, enable_if_t<!is_integral_v<U>, nullptr_t> = nullptr>\n\tCulSum2D(const U&\
    \ a, F f)\n\t    : CulSum2D(a.size(), a.front().size(),\n\t               [a,\
    \ f](size_t i, size_t j) -> value_type { return f(a[i][j]); }) {}\n\t// [y1, y2)\
    \ * [x1, x2)\n\tvalue_type operator()(size_t y1, size_t y2, size_t x1, size_t\
    \ x2) const {\n\t\ty1 = min(y1, h);\n\t\ty2 = min(y2, h);\n\t\tx1 = min(x1, w);\n\
    \t\tx2 = min(x2, w);\n\t\treturn (x1 > x2 || y1 > y2)\n\t\t    ? 0\n\t\t    :\
    \ data[y2][x2] - data[y1][x2] - data[y2][x1] + data[y1][x1];\n\t}\n\t// [0, y)\
    \ * [0, x)\n\tvalue_type operator()(size_t y, size_t x) const {\n\t\ty = min(y,\
    \ h);\n\t\tx = min(x, w);\n\t\treturn data[y][x];\n\t}\n\tconst data_type& get_data()\
    \ const {\n\t\treturn data;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\
    \ntemplate <class T> class CulSum2D {\npublic:\n\tusing value_type = T;\n\tusing\
    \ data_type = vector<vector<value_type>>;\n\nprivate:\n\tsize_t h, w;\n\tvector<vector<T>>\
    \ data;\n\npublic:\n\tCulSum2D(const data_type& a)\n\t    : h(a.size()), w(a.front().size()),\
    \ data(h + 1, vector<value_type>(w + 1)) {\n\t\tfor (size_t i = 0; i < h; ++i)\
    \ {\n\t\t\tfor (size_t j = 0; j < w; ++j) {\n\t\t\t\tdata[i + 1][j + 1] =\n\t\t\
    \t\t    data[i][j + 1] + data[i + 1][j] - data[i][j] + a[i][j];\n\t\t\t}\n\t\t\
    }\n\t}\n\ttemplate <class U, class F, enable_if_t<is_integral_v<U>, nullptr_t>\
    \ = nullptr>\n\tCulSum2D(const U& _h, const U& _w, F f)\n\t    : h(_h), w(_w),\
    \ data(h + 1, vector<value_type>(w + 1)) {\n\t\tfor (size_t i = 0; i < h; ++i)\
    \ {\n\t\t\tfor (size_t j = 0; j < w; ++j) {\n\t\t\t\tdata[i + 1][j + 1] =\n\t\t\
    \t\t    data[i][j + 1] + data[i + 1][j] - data[i][j] + f(i, j);\n\t\t\t}\n\t\t\
    }\n\t}\n\ttemplate <class U, class F, enable_if_t<!is_integral_v<U>, nullptr_t>\
    \ = nullptr>\n\tCulSum2D(const U& a, F f)\n\t    : CulSum2D(a.size(), a.front().size(),\n\
    \t               [a, f](size_t i, size_t j) -> value_type { return f(a[i][j]);\
    \ }) {}\n\t// [y1, y2) * [x1, x2)\n\tvalue_type operator()(size_t y1, size_t y2,\
    \ size_t x1, size_t x2) const {\n\t\ty1 = min(y1, h);\n\t\ty2 = min(y2, h);\n\t\
    \tx1 = min(x1, w);\n\t\tx2 = min(x2, w);\n\t\treturn (x1 > x2 || y1 > y2)\n\t\t\
    \    ? 0\n\t\t    : data[y2][x2] - data[y1][x2] - data[y2][x1] + data[y1][x1];\n\
    \t}\n\t// [0, y) * [0, x)\n\tvalue_type operator()(size_t y, size_t x) const {\n\
    \t\ty = min(y, h);\n\t\tx = min(x, w);\n\t\treturn data[y][x];\n\t}\n\tconst data_type&\
    \ get_data() const {\n\t\treturn data;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CulSum2D.cpp
  requiredBy: []
  timestamp: '2020-12-12 20:18:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/CulSum2D.test.cpp
documentation_of: Utility/CulSum2D.cpp
layout: document
redirect_from:
- /library/Utility/CulSum2D.cpp
- /library/Utility/CulSum2D.cpp.html
title: Utility/CulSum2D.cpp
---
