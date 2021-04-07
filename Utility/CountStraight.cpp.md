---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/CountStraight.cpp\"\n#include <vector>\n#include\
    \ <tuple>\n\ntemplate <class F> auto CountLR(int n, F f) {\n\tstd::vector<int>\
    \ left(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (f(i)) left[i] = 1 + (i ?\
    \ left[i - 1] : 0);\n\t}\n\tstd::vector<int> right(n);\n\tfor (int i = n - 1;\
    \ i >= 0; --i) {\n\t\tif (f(i)) right[i] = 1 + (i != n - 1 ? right[i + 1] : 0);\n\
    \t}\n\treturn std::tuple(left, right);\n}\n\ntemplate <class F> auto CountLR(int\
    \ h, int w, F f) {\n\tstd::vector<std::vector<int>> left(h, std::vector<int>(w));\n\
    \tfor (int i = 0; i < h; ++i) {\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\tif (f(i,\
    \ j)) left[i][j] = 1 + (j ? left[i][j - 1] : 0);\n\t\t}\n\t}\n\tstd::vector<std::vector<int>>\
    \ right(h, std::vector<int>(w));\n\tfor (int i = 0; i < h; ++i) {\n\t\tfor (int\
    \ j = w - 1; j >= 0; --j) {\n\t\t\tif (f(i, j)) right[i][j] = 1 + (j != w - 1\
    \ ? right[i][j + 1] : 0);\n\t\t}\n\t}\n\treturn std::tuple(left, right);\n}\n\n\
    template <class F> auto CountUD(int h, int w, F f) {\n\tstd::vector<std::vector<int>>\
    \ up(h, std::vector<int>(w));\n\tfor (int i = 0; i < h; ++i) {\n\t\tfor (int j\
    \ = 0; j < w; ++j) {\n\t\t\tif (f(i, j)) up[i][j] = 1 + (i ? up[i - 1][j] : 0);\n\
    \t\t}\n\t}\n\tstd::vector<std::vector<int>> down(h, std::vector<int>(w));\n\t\
    for (int i = h - 1; i >= 0; --i) {\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\t\
    if (f(i, j)) down[i][j] = 1 + (i != h - 1 ? down[i + 1][j] : 0);\n\t\t}\n\t}\n\
    \treturn std::tuple(up, down);\n}\n\ntemplate <class F> auto CountTLBR(int h,\
    \ int w, F f) {\n\tstd::vector<std::vector<int>> tl(h, std::vector<int>(w));\n\
    \tfor (int i = 0; i < h; ++i) {\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\tif (f(i,\
    \ j)) tl[i][j] = 1 + (i && j ? tl[i - 1][j - 1] : 0);\n\t\t}\n\t}\n\tstd::vector<std::vector<int>>\
    \ br(h, std::vector<int>(w));\n\tfor (int i = h - 1; i >= 0; --i) {\n\t\tfor (int\
    \ j = w - 1; j >= 0; --j) {\n\t\t\tif (f(i, j)) br[i][j] = 1 + (i != h - 1 &&\
    \ j != w - 1 ? br[i + 1][j + 1] : 0);\n\t\t}\n\t}\n\treturn std::tuple(tl, br);\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n\ntemplate <class F> auto\
    \ CountLR(int n, F f) {\n\tstd::vector<int> left(n);\n\tfor (int i = 0; i < n;\
    \ ++i) {\n\t\tif (f(i)) left[i] = 1 + (i ? left[i - 1] : 0);\n\t}\n\tstd::vector<int>\
    \ right(n);\n\tfor (int i = n - 1; i >= 0; --i) {\n\t\tif (f(i)) right[i] = 1\
    \ + (i != n - 1 ? right[i + 1] : 0);\n\t}\n\treturn std::tuple(left, right);\n\
    }\n\ntemplate <class F> auto CountLR(int h, int w, F f) {\n\tstd::vector<std::vector<int>>\
    \ left(h, std::vector<int>(w));\n\tfor (int i = 0; i < h; ++i) {\n\t\tfor (int\
    \ j = 0; j < w; ++j) {\n\t\t\tif (f(i, j)) left[i][j] = 1 + (j ? left[i][j - 1]\
    \ : 0);\n\t\t}\n\t}\n\tstd::vector<std::vector<int>> right(h, std::vector<int>(w));\n\
    \tfor (int i = 0; i < h; ++i) {\n\t\tfor (int j = w - 1; j >= 0; --j) {\n\t\t\t\
    if (f(i, j)) right[i][j] = 1 + (j != w - 1 ? right[i][j + 1] : 0);\n\t\t}\n\t\
    }\n\treturn std::tuple(left, right);\n}\n\ntemplate <class F> auto CountUD(int\
    \ h, int w, F f) {\n\tstd::vector<std::vector<int>> up(h, std::vector<int>(w));\n\
    \tfor (int i = 0; i < h; ++i) {\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\tif (f(i,\
    \ j)) up[i][j] = 1 + (i ? up[i - 1][j] : 0);\n\t\t}\n\t}\n\tstd::vector<std::vector<int>>\
    \ down(h, std::vector<int>(w));\n\tfor (int i = h - 1; i >= 0; --i) {\n\t\tfor\
    \ (int j = 0; j < w; ++j) {\n\t\t\tif (f(i, j)) down[i][j] = 1 + (i != h - 1 ?\
    \ down[i + 1][j] : 0);\n\t\t}\n\t}\n\treturn std::tuple(up, down);\n}\n\ntemplate\
    \ <class F> auto CountTLBR(int h, int w, F f) {\n\tstd::vector<std::vector<int>>\
    \ tl(h, std::vector<int>(w));\n\tfor (int i = 0; i < h; ++i) {\n\t\tfor (int j\
    \ = 0; j < w; ++j) {\n\t\t\tif (f(i, j)) tl[i][j] = 1 + (i && j ? tl[i - 1][j\
    \ - 1] : 0);\n\t\t}\n\t}\n\tstd::vector<std::vector<int>> br(h, std::vector<int>(w));\n\
    \tfor (int i = h - 1; i >= 0; --i) {\n\t\tfor (int j = w - 1; j >= 0; --j) {\n\
    \t\t\tif (f(i, j)) br[i][j] = 1 + (i != h - 1 && j != w - 1 ? br[i + 1][j + 1]\
    \ : 0);\n\t\t}\n\t}\n\treturn std::tuple(tl, br);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CountStraight.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:24:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/CountStraight.cpp
layout: document
redirect_from:
- /library/Utility/CountStraight.cpp
- /library/Utility/CountStraight.cpp.html
title: Utility/CountStraight.cpp
---
