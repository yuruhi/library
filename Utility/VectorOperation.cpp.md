---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/VectorOperation.cpp\"\n#include <vector>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <class T> vector<vector<T>> Rotated90(const\
    \ vector<vector<T>>& a) {\n\tsize_t h = a.size(), w = a.front().size();\n\tvector<vector<T>>\
    \ res(w, vector<T>(h));\n\tfor (size_t i = 0; i < h; ++i) {\n\t\tassert(a[i].size()\
    \ == w);\n\t\tfor (size_t j = 0; j < w; ++j) {\n\t\t\tres[j][h - 1 - i] = a[i][j];\n\
    \t\t}\n\t}\n\treturn res;\n}\ntemplate <class T> vector<vector<T>> Rotated180(const\
    \ vector<vector<T>>& a) {\n\tint h = a.size(), w = a.front().size();\n\tvector<vector<T>>\
    \ res(h, vector<T>(w));\n\tfor (size_t i = 0; i < h; ++i) {\n\t\tassert(a[i].size()\
    \ == w);\n\t\tfor (size_t j = 0; j < w; ++j) {\n\t\t\tres[h - 1 - i][w - 1 - j]\
    \ = a[i][j];\n\t\t}\n\t}\n\treturn res;\n}\ntemplate <class T> vector<vector<T>>\
    \ Rotated270(const vector<vector<T>>& a) {\n\tsize_t h = a.size(), w = a.front().size();\n\
    \tvector<vector<T>> res(w, vector<T>(h));\n\tfor (size_t i = 0; i < h; ++i) {\n\
    \t\tassert(a[i].size() == w);\n\t\tfor (size_t j = 0; j < w; ++j) {\n\t\t\tres[w\
    \ - 1 - j][i] = a[i][j];\n\t\t}\n\t}\n\treturn res;\n}\ntemplate <class T> vector<vector<T>>\
    \ Scaled(const vector<vector<T>>& a, size_t k) {\n\tsize_t h = a.size(), w = a.front().size();\n\
    \tvector<vector<T>> res(h * k, vector<T>(w * k));\n\tfor (size_t i = 0; i < h;\
    \ ++i) {\n\t\tassert(a[i].size() == w);\n\t\tfor (size_t j = 0; j < w; ++j) {\n\
    \t\t\tfor (size_t y = 0; y < k; ++y)\n\t\t\t\tfor (size_t x = 0; x < k; ++x) {\n\
    \t\t\t\t\tres[i * k + y][j * k + x] = a[i][j];\n\t\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ res;\n}\ntemplate <class T> vector<vector<T>> Chunk(const vector<T>& a, size_t\
    \ n) {\n\tvector<vector<T>> res;\n\tif (n == 0) return res;\n\tfor (size_t i =\
    \ 0; i < (a.size() + n - 1))\n\t\treturn res;\n}\ntemplate <class T> void Rotate90(vector<vector<T>>&\
    \ a) {\n\ta = Rotated90(a);\n}\ntemplate <class T> void Rotate180(vector<vector<T>>&\
    \ a) {\n\ta = Rotated180(a);\n}\ntemplate <class T> void Rotate270(vector<vector<T>>&\
    \ a) {\n\ta = Rotated270(a);\n}\ntemplate <class T> void Scale(vector<vector<T>>&\
    \ a, size_t k) {\n\ta = Scaled(a, k);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <class T> vector<vector<T>> Rotated90(const vector<vector<T>>& a) {\n\
    \tsize_t h = a.size(), w = a.front().size();\n\tvector<vector<T>> res(w, vector<T>(h));\n\
    \tfor (size_t i = 0; i < h; ++i) {\n\t\tassert(a[i].size() == w);\n\t\tfor (size_t\
    \ j = 0; j < w; ++j) {\n\t\t\tres[j][h - 1 - i] = a[i][j];\n\t\t}\n\t}\n\treturn\
    \ res;\n}\ntemplate <class T> vector<vector<T>> Rotated180(const vector<vector<T>>&\
    \ a) {\n\tint h = a.size(), w = a.front().size();\n\tvector<vector<T>> res(h,\
    \ vector<T>(w));\n\tfor (size_t i = 0; i < h; ++i) {\n\t\tassert(a[i].size() ==\
    \ w);\n\t\tfor (size_t j = 0; j < w; ++j) {\n\t\t\tres[h - 1 - i][w - 1 - j] =\
    \ a[i][j];\n\t\t}\n\t}\n\treturn res;\n}\ntemplate <class T> vector<vector<T>>\
    \ Rotated270(const vector<vector<T>>& a) {\n\tsize_t h = a.size(), w = a.front().size();\n\
    \tvector<vector<T>> res(w, vector<T>(h));\n\tfor (size_t i = 0; i < h; ++i) {\n\
    \t\tassert(a[i].size() == w);\n\t\tfor (size_t j = 0; j < w; ++j) {\n\t\t\tres[w\
    \ - 1 - j][i] = a[i][j];\n\t\t}\n\t}\n\treturn res;\n}\ntemplate <class T> vector<vector<T>>\
    \ Scaled(const vector<vector<T>>& a, size_t k) {\n\tsize_t h = a.size(), w = a.front().size();\n\
    \tvector<vector<T>> res(h * k, vector<T>(w * k));\n\tfor (size_t i = 0; i < h;\
    \ ++i) {\n\t\tassert(a[i].size() == w);\n\t\tfor (size_t j = 0; j < w; ++j) {\n\
    \t\t\tfor (size_t y = 0; y < k; ++y)\n\t\t\t\tfor (size_t x = 0; x < k; ++x) {\n\
    \t\t\t\t\tres[i * k + y][j * k + x] = a[i][j];\n\t\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ res;\n}\ntemplate <class T> vector<vector<T>> Chunk(const vector<T>& a, size_t\
    \ n) {\n\tvector<vector<T>> res;\n\tif (n == 0) return res;\n\tfor (size_t i =\
    \ 0; i < (a.size() + n - 1))\n\t\treturn res;\n}\ntemplate <class T> void Rotate90(vector<vector<T>>&\
    \ a) {\n\ta = Rotated90(a);\n}\ntemplate <class T> void Rotate180(vector<vector<T>>&\
    \ a) {\n\ta = Rotated180(a);\n}\ntemplate <class T> void Rotate270(vector<vector<T>>&\
    \ a) {\n\ta = Rotated270(a);\n}\ntemplate <class T> void Scale(vector<vector<T>>&\
    \ a, size_t k) {\n\ta = Scaled(a, k);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/VectorOperation.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/VectorOperation.cpp
layout: document
redirect_from:
- /library/Utility/VectorOperation.cpp
- /library/Utility/VectorOperation.cpp.html
title: Utility/VectorOperation.cpp
---
