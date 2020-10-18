---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/CountStraight.cpp\"\n#include <vector>\n#include\
    \ <tuple>\nusing namespace std;\n\ntemplate <class F> tuple<vector<int>, vector<int>>\
    \ CountLR(int n, F f) {\n\tvector<int> left(n);\n\tfor (int i = 0; i < n; ++i)\
    \ {\n\t\tif (f(i)) left[i] = 1 + (i ? left[i - 1] : 0);\n\t}\n\tvector<int> right(n);\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tif (f(i)) right[i] = 1 + (i != n - 1 ? right[i\
    \ + 1] : 0);\n\t}\n\treturn make_tuple(left, right);\n}\n\ntemplate <class F>\
    \ tuple<vector<vector<int>>, vector<vector<int>>> CountLR(int h, int w, F f) {\n\
    \tvector<vector<int>> left(h, vector<int>(w));\n\tfor (int i = 0; i < h; ++i)\n\
    \t\tfor (int j = 0; j < w; ++j) {\n\t\t\tif (f(i, j)) left[i][j] = 1 + (j ? left[i][j\
    \ - 1] : 0);\n\t\t}\n\tvector<vector<int>> right(h, vector<int>(w));\n\tfor (int\
    \ i = 0; i < h; ++i)\n\t\tfor (int j = w - 1; j >= 0; --j) {\n\t\t\tif (f(i, j))\
    \ right[i][j] = 1 + (j != w - 1 ? right[i][j + 1] : 0);\n\t\t}\n\treturn make_tuple(left,\
    \ right);\n}\n\ntemplate <class F> tuple<vector<vector<int>>, vector<vector<int>>>\
    \ CountUD(int h, int w, F f) {\n\tvector<vector<int>> up(h, vector<int>(w));\n\
    \tfor (int i = 0; i < h; ++i)\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\tif (f(i,\
    \ j)) up[i][j] = 1 + (i ? up[i - 1][j] : 0);\n\t\t}\n\tvector<vector<int>> down(h,\
    \ vector<int>(w));\n\tfor (int i = h - 1; i >= 0; --i)\n\t\tfor (int j = 0; j\
    \ < w; ++j) {\n\t\t\tif (f(i, j)) down[i][j] = 1 + (i != h - 1 ? down[i + 1][j]\
    \ : 0);\n\t\t}\n\treturn make_tuple(up, down);\n}\n\ntemplate <class F> tuple<vector<vector<int>>,\
    \ vector<vector<int>>> CountTLBR(int h, int w, F f) {\n\tvector<vector<int>> tl(h,\
    \ vector<int>(w));\n\tfor (int i = 0; i < h; ++i)\n\t\tfor (int j = 0; j < w;\
    \ ++j) {\n\t\t\tif (f(i, j)) tl[i][j] = 1 + (i && j ? tl[i - 1][j - 1] : 0);\n\
    \t\t}\n\tvector<vector<int>> br(h, vector<int>(w));\n\tfor (int i = h - 1; i >=\
    \ 0; --i)\n\t\tfor (int j = w - 1; j >= 0; --j) {\n\t\t\tif (f(i, j)) br[i][j]\
    \ = 1 + (i != h - 1 && j != w - 1 ? br[i + 1][j + 1] : 0);\n\t\t}\n\treturn make_tuple(tl,\
    \ br);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\nusing namespace std;\n\
    \ntemplate <class F> tuple<vector<int>, vector<int>> CountLR(int n, F f) {\n\t\
    vector<int> left(n);\n\tfor (int i = 0; i < n; ++i) {\n\t\tif (f(i)) left[i] =\
    \ 1 + (i ? left[i - 1] : 0);\n\t}\n\tvector<int> right(n);\n\tfor (int i = 0;\
    \ i < n; ++i) {\n\t\tif (f(i)) right[i] = 1 + (i != n - 1 ? right[i + 1] : 0);\n\
    \t}\n\treturn make_tuple(left, right);\n}\n\ntemplate <class F> tuple<vector<vector<int>>,\
    \ vector<vector<int>>> CountLR(int h, int w, F f) {\n\tvector<vector<int>> left(h,\
    \ vector<int>(w));\n\tfor (int i = 0; i < h; ++i)\n\t\tfor (int j = 0; j < w;\
    \ ++j) {\n\t\t\tif (f(i, j)) left[i][j] = 1 + (j ? left[i][j - 1] : 0);\n\t\t\
    }\n\tvector<vector<int>> right(h, vector<int>(w));\n\tfor (int i = 0; i < h; ++i)\n\
    \t\tfor (int j = w - 1; j >= 0; --j) {\n\t\t\tif (f(i, j)) right[i][j] = 1 + (j\
    \ != w - 1 ? right[i][j + 1] : 0);\n\t\t}\n\treturn make_tuple(left, right);\n\
    }\n\ntemplate <class F> tuple<vector<vector<int>>, vector<vector<int>>> CountUD(int\
    \ h, int w, F f) {\n\tvector<vector<int>> up(h, vector<int>(w));\n\tfor (int i\
    \ = 0; i < h; ++i)\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\tif (f(i, j)) up[i][j]\
    \ = 1 + (i ? up[i - 1][j] : 0);\n\t\t}\n\tvector<vector<int>> down(h, vector<int>(w));\n\
    \tfor (int i = h - 1; i >= 0; --i)\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\t\
    if (f(i, j)) down[i][j] = 1 + (i != h - 1 ? down[i + 1][j] : 0);\n\t\t}\n\treturn\
    \ make_tuple(up, down);\n}\n\ntemplate <class F> tuple<vector<vector<int>>, vector<vector<int>>>\
    \ CountTLBR(int h, int w, F f) {\n\tvector<vector<int>> tl(h, vector<int>(w));\n\
    \tfor (int i = 0; i < h; ++i)\n\t\tfor (int j = 0; j < w; ++j) {\n\t\t\tif (f(i,\
    \ j)) tl[i][j] = 1 + (i && j ? tl[i - 1][j - 1] : 0);\n\t\t}\n\tvector<vector<int>>\
    \ br(h, vector<int>(w));\n\tfor (int i = h - 1; i >= 0; --i)\n\t\tfor (int j =\
    \ w - 1; j >= 0; --j) {\n\t\t\tif (f(i, j)) br[i][j] = 1 + (i != h - 1 && j !=\
    \ w - 1 ? br[i + 1][j + 1] : 0);\n\t\t}\n\treturn make_tuple(tl, br);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CountStraight.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/CountStraight.cpp
layout: document
redirect_from:
- /library/Utility/CountStraight.cpp
- /library/Utility/CountStraight.cpp.html
title: Utility/CountStraight.cpp
---
