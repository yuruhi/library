---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/Imos2D.cpp\"\n// description : \u3044\u3082\u3059\
    \u6CD52\u6B21\u5143\ntemplate <class T> class Imos2D {\npublic:\n\tconst int H,\
    \ W;\n\nprivate:\n\tvector<vector<T>> table;\n\tbool flag = false;\n\npublic:\n\
    \tImos2D(int _h, int _w) : H(_h), W(_w), table(_h + 1, vector<T>(_w + 1)) {}\n\
    \t// [x1, x2) * [y1, y2)\n\tvoid add(int y1, int y2, int x1, int x2, const T&\
    \ v = 1) {\n\t\tassert(0 <= x1 && x1 < x2 && x2 <= W);\n\t\tassert(0 <= y1 &&\
    \ y1 < y2 && y2 <= H);\n\t\tassert(!flag);\n\t\ttable[y1][x1] += v;\n\t\ttable[y1][x2]\
    \ -= v;\n\t\ttable[y2][x1] -= v;\n\t\ttable[y2][x2] += v;\n\t}\n\tvoid add(const\
    \ pair<int, int>& y, const pair<int, int>& x, const T& v = 1) {\n\t\tassert(!flag);\n\
    \t\tadd(y.first, y.second, x.first, x.second, v);\n\t}\n\tvoid build() {\n\t\t\
    flag = true;\n\t\tfor (int y = 0; y <= H; ++y)\n\t\t\tfor (int x = 1; x <= W;\
    \ ++x)\n\t\t\t\ttable[y][x] += table[y][x - 1];\n\t\tfor (int y = 1; y <= H; ++y)\n\
    \t\t\tfor (int x = 0; x <= W; ++x)\n\t\t\t\ttable[y][x] += table[y - 1][x];\n\t\
    }\n\tconst T& operator()(int y, int x) const {\n\t\tassert(flag);\n\t\treturn\
    \ table[y][x];\n\t}\n\tconst auto& operator*() const {\n\t\tassert(flag);\n\t\t\
    return table;\n\t}\n};\n"
  code: "// description : \u3044\u3082\u3059\u6CD52\u6B21\u5143\ntemplate <class T>\
    \ class Imos2D {\npublic:\n\tconst int H, W;\n\nprivate:\n\tvector<vector<T>>\
    \ table;\n\tbool flag = false;\n\npublic:\n\tImos2D(int _h, int _w) : H(_h), W(_w),\
    \ table(_h + 1, vector<T>(_w + 1)) {}\n\t// [x1, x2) * [y1, y2)\n\tvoid add(int\
    \ y1, int y2, int x1, int x2, const T& v = 1) {\n\t\tassert(0 <= x1 && x1 < x2\
    \ && x2 <= W);\n\t\tassert(0 <= y1 && y1 < y2 && y2 <= H);\n\t\tassert(!flag);\n\
    \t\ttable[y1][x1] += v;\n\t\ttable[y1][x2] -= v;\n\t\ttable[y2][x1] -= v;\n\t\t\
    table[y2][x2] += v;\n\t}\n\tvoid add(const pair<int, int>& y, const pair<int,\
    \ int>& x, const T& v = 1) {\n\t\tassert(!flag);\n\t\tadd(y.first, y.second, x.first,\
    \ x.second, v);\n\t}\n\tvoid build() {\n\t\tflag = true;\n\t\tfor (int y = 0;\
    \ y <= H; ++y)\n\t\t\tfor (int x = 1; x <= W; ++x)\n\t\t\t\ttable[y][x] += table[y][x\
    \ - 1];\n\t\tfor (int y = 1; y <= H; ++y)\n\t\t\tfor (int x = 0; x <= W; ++x)\n\
    \t\t\t\ttable[y][x] += table[y - 1][x];\n\t}\n\tconst T& operator()(int y, int\
    \ x) const {\n\t\tassert(flag);\n\t\treturn table[y][x];\n\t}\n\tconst auto& operator*()\
    \ const {\n\t\tassert(flag);\n\t\treturn table;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Imos2D.cpp
  requiredBy: []
  timestamp: '2020-09-28 21:38:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/Imos2D.cpp
layout: document
redirect_from:
- /library/Utility/Imos2D.cpp
- /library/Utility/Imos2D.cpp.html
title: Utility/Imos2D.cpp
---
