---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/CulSum2D.cpp\"\n// description : \u7D2F\u7A4D\u548C\
    2\u6B21\u5143\ntemplate <class T> class CulSum2D {\n\tint h, w;\n\tvector<vector<T>>\
    \ s;\n\npublic:\n\tCulSum2D(const vector<vector<T>>& a) : h(a.size()), w(a.front().size()),\
    \ s(h + 1, vector<T>(w + 1)) {\n\t\tfor (int i = 0; i < h; ++i)\n\t\t\tfor (int\
    \ j = 0; j < w; ++j)\n\t\t\t\ts[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j]\
    \ + a[i][j];\n\t}\n\ttemplate <class U, class F>\n\tCulSum2D(const U& a, F f)\
    \ : h(a.size()), w(a.front().size()), s(h + 1, vector<T>(w + 1)) {\n\t\tfor (int\
    \ i = 0; i < h; ++i)\n\t\t\tfor (int j = 0; j < w; ++j)\n\t\t\t\ts[i + 1][j +\
    \ 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + static_cast<T>(f(a[i][j]));\n\t}\n\
    \t// [y1, y2) * [x1, x2)\n\tT operator()(int y1, int y2, int x1, int x2) const\
    \ {\n\t\tx1 = min(max(x1, 0), w);\n\t\tx2 = min(max(x2, 0), w);\n\t\ty1 = min(max(y1,\
    \ 0), h);\n\t\ty2 = min(max(y2, 0), h);\n\t\treturn (x1 > x2 || y1 > y2) ? 0 :\
    \ s[y2][x2] - s[y1][x2] - s[y2][x1] + s[y1][x1];\n\t}\n\t// [0, y) * [0, x)\n\t\
    T operator()(int y, int x) const {\n\t\tx = min(max(x, 0), w);\n\t\ty = min(max(y,\
    \ 0), h);\n\t\treturn s[y][x];\n\t}\n\tconst vector<vector<T>>& get_s() {\n\t\t\
    return s;\n\t}\n};\n"
  code: "// description : \u7D2F\u7A4D\u548C2\u6B21\u5143\ntemplate <class T> class\
    \ CulSum2D {\n\tint h, w;\n\tvector<vector<T>> s;\n\npublic:\n\tCulSum2D(const\
    \ vector<vector<T>>& a) : h(a.size()), w(a.front().size()), s(h + 1, vector<T>(w\
    \ + 1)) {\n\t\tfor (int i = 0; i < h; ++i)\n\t\t\tfor (int j = 0; j < w; ++j)\n\
    \t\t\t\ts[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];\n\t}\n\
    \ttemplate <class U, class F>\n\tCulSum2D(const U& a, F f) : h(a.size()), w(a.front().size()),\
    \ s(h + 1, vector<T>(w + 1)) {\n\t\tfor (int i = 0; i < h; ++i)\n\t\t\tfor (int\
    \ j = 0; j < w; ++j)\n\t\t\t\ts[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j]\
    \ + static_cast<T>(f(a[i][j]));\n\t}\n\t// [y1, y2) * [x1, x2)\n\tT operator()(int\
    \ y1, int y2, int x1, int x2) const {\n\t\tx1 = min(max(x1, 0), w);\n\t\tx2 =\
    \ min(max(x2, 0), w);\n\t\ty1 = min(max(y1, 0), h);\n\t\ty2 = min(max(y2, 0),\
    \ h);\n\t\treturn (x1 > x2 || y1 > y2) ? 0 : s[y2][x2] - s[y1][x2] - s[y2][x1]\
    \ + s[y1][x1];\n\t}\n\t// [0, y) * [0, x)\n\tT operator()(int y, int x) const\
    \ {\n\t\tx = min(max(x, 0), w);\n\t\ty = min(max(y, 0), h);\n\t\treturn s[y][x];\n\
    \t}\n\tconst vector<vector<T>>& get_s() {\n\t\treturn s;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CulSum2D.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/CulSum2D.cpp
layout: document
redirect_from:
- /library/Utility/CulSum2D.cpp
- /library/Utility/CulSum2D.cpp.html
title: Utility/CulSum2D.cpp
---
