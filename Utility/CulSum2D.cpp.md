---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/CulSum2D.cpp\"\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n\ntemplate <class T> class CulSum2D {\npublic:\n\tusing\
    \ value_type = T;\n\tusing data_type = vector<vector<value_type>>;\n\nprivate:\n\
    \tsize_t h, w;\n\tvector<vector<T>> s;\n\npublic:\n\tCulSum2D(const data_type&\
    \ a)\n\t    : h(a.size()), w(a.front().size()), s(h + 1, vector<value_type>(w\
    \ + 1)) {\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\tfor (size_t j = 0; j <\
    \ w; ++j) {\n\t\t\t\ts[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];\n\
    \t\t\t}\n\t\t}\n\t}\n\ttemplate <class F>\n\tCulSum2D(size_t _h, size_t _w, F\
    \ f)\n\t    : h(_h), w(_w), s(h + 1, vector<value_type>(w + 1)) {\n\t\tfor (size_t\
    \ i = 0; i < h; ++i) {\n\t\t\tfor (size_t j = 0; j < w; ++j) {\n\t\t\t\ts[i +\
    \ 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + f(i, j);\n\t\t\t}\n\t\t}\n\
    \t}\n\ttemplate <class U, class F>\n\tCulSum2D(const U& a, F f)\n\t    : CulSum2D(a.size(),\
    \ a.front().size(),\n\t               [a, f](size_t i, size_t j) -> value_type\
    \ { return f(a[i][j]); }) {}\n\t// [y1, y2) * [x1, x2)\n\tvalue_type operator()(size_t\
    \ y1, size_t y2, size_t x1, size_t x2) const {\n\t\ty1 = min(y1, h);\n\t\ty2 =\
    \ min(y2, h);\n\t\tx1 = min(x1, w);\n\t\tx2 = min(x2, w);\n\t\treturn (x1 > x2\
    \ || y1 > y2) ? 0 : s[y2][x2] - s[y1][x2] - s[y2][x1] + s[y1][x1];\n\t}\n\t//\
    \ [0, y) * [0, x)\n\tvalue_type operator()(size_t y, size_t x) const {\n\t\ty\
    \ = min(y, h);\n\t\tx = min(x, w);\n\t\treturn s[y][x];\n\t}\n\tconst data_type&\
    \ get_data() const {\n\t\treturn s;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\
    \ntemplate <class T> class CulSum2D {\npublic:\n\tusing value_type = T;\n\tusing\
    \ data_type = vector<vector<value_type>>;\n\nprivate:\n\tsize_t h, w;\n\tvector<vector<T>>\
    \ s;\n\npublic:\n\tCulSum2D(const data_type& a)\n\t    : h(a.size()), w(a.front().size()),\
    \ s(h + 1, vector<value_type>(w + 1)) {\n\t\tfor (size_t i = 0; i < h; ++i) {\n\
    \t\t\tfor (size_t j = 0; j < w; ++j) {\n\t\t\t\ts[i + 1][j + 1] = s[i][j + 1]\
    \ + s[i + 1][j] - s[i][j] + a[i][j];\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class F>\n\
    \tCulSum2D(size_t _h, size_t _w, F f)\n\t    : h(_h), w(_w), s(h + 1, vector<value_type>(w\
    \ + 1)) {\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\tfor (size_t j = 0; j <\
    \ w; ++j) {\n\t\t\t\ts[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + f(i,\
    \ j);\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class U, class F>\n\tCulSum2D(const U&\
    \ a, F f)\n\t    : CulSum2D(a.size(), a.front().size(),\n\t               [a,\
    \ f](size_t i, size_t j) -> value_type { return f(a[i][j]); }) {}\n\t// [y1, y2)\
    \ * [x1, x2)\n\tvalue_type operator()(size_t y1, size_t y2, size_t x1, size_t\
    \ x2) const {\n\t\ty1 = min(y1, h);\n\t\ty2 = min(y2, h);\n\t\tx1 = min(x1, w);\n\
    \t\tx2 = min(x2, w);\n\t\treturn (x1 > x2 || y1 > y2) ? 0 : s[y2][x2] - s[y1][x2]\
    \ - s[y2][x1] + s[y1][x1];\n\t}\n\t// [0, y) * [0, x)\n\tvalue_type operator()(size_t\
    \ y, size_t x) const {\n\t\ty = min(y, h);\n\t\tx = min(x, w);\n\t\treturn s[y][x];\n\
    \t}\n\tconst data_type& get_data() const {\n\t\treturn s;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CulSum2D.cpp
  requiredBy: []
  timestamp: '2020-11-20 20:10:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/CulSum2D.cpp
layout: document
redirect_from:
- /library/Utility/CulSum2D.cpp
- /library/Utility/CulSum2D.cpp.html
title: Utility/CulSum2D.cpp
---
