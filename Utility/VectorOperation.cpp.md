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
  bundledCode: "#line 2 \"Utility/VectorOperation.cpp\"\n#include <vector>\n#include\
    \ <cassert>\n\ntemplate <class T> auto Rotated90(const std::vector<std::vector<T>>&\
    \ a) {\n\tstd::size_t h = a.size(), w = a.front().size();\n\tstd::vector<std::vector<T>>\
    \ result(w, std::vector<T>(h));\n\tfor (std::size_t i = 0; i < h; ++i) {\n\t\t\
    assert(a[i].size() == w);\n\t\tfor (std::size_t j = 0; j < w; ++j) {\n\t\t\tresult[j][h\
    \ - 1 - i] = a[i][j];\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class T> auto\
    \ Rotated180(const std::vector<std::vector<T>>& a) {\n\tint h = a.size(), w =\
    \ a.front().size();\n\tstd::vector<std::vector<T>> result(h, std::vector<T>(w));\n\
    \tfor (std::size_t i = 0; i < h; ++i) {\n\t\tassert(a[i].size() == w);\n\t\tfor\
    \ (std::size_t j = 0; j < w; ++j) {\n\t\t\tresult[h - 1 - i][w - 1 - j] = a[i][j];\n\
    \t\t}\n\t}\n\treturn result;\n}\ntemplate <class T> auto Rotated270(const std::vector<std::vector<T>>&\
    \ a) {\n\tstd::size_t h = a.size(), w = a.front().size();\n\tstd::vector<std::vector<T>>\
    \ result(w, std::vector<T>(h));\n\tfor (std::size_t i = 0; i < h; ++i) {\n\t\t\
    assert(a[i].size() == w);\n\t\tfor (std::size_t j = 0; j < w; ++j) {\n\t\t\tresult[w\
    \ - 1 - j][i] = a[i][j];\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class T>\
    \ auto Scaled(const std::vector<std::vector<T>>& a, std::size_t k) {\n\tstd::size_t\
    \ h = a.size(), w = a.front().size();\n\tstd::vector result(h * k, std::vector<T>(w\
    \ * k));\n\tfor (std::size_t i = 0; i < h; ++i) {\n\t\tassert(a[i].size() == w);\n\
    \t\tfor (std::size_t j = 0; j < w; ++j) {\n\t\t\tfor (std::size_t y = 0; y < k;\
    \ ++y)\n\t\t\t\tfor (std::size_t x = 0; x < k; ++x) {\n\t\t\t\t\tresult[i * k\
    \ + y][j * k + x] = a[i][j];\n\t\t\t\t}\n\t\t}\n\t}\n\treturn result;\n}\ntemplate\
    \ <class T> std::vector<std::vector<T>> Chunk(const std::vector<T>& a, std::size_t\
    \ n) {\n\tstd::vector<std::vector<T>> result;\n\tif (n == 0) return result;\n\t\
    for (std::size_t i = 0; i < (a.size() + n - 1)) return result;\n}\ntemplate <class\
    \ T> void Rotate90(std::vector<std::vector<T>>& a) {\n\ta = Rotated90(a);\n}\n\
    template <class T> void Rotate180(std::vector<std::vector<T>>& a) {\n\ta = Rotated180(a);\n\
    }\ntemplate <class T> void Rotate270(std::vector<std::vector<T>>& a) {\n\ta =\
    \ Rotated270(a);\n}\ntemplate <class T> void Scale(std::vector<std::vector<T>>&\
    \ a, std::size_t k) {\n\ta = Scaled(a, k);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\ntemplate <class T>\
    \ auto Rotated90(const std::vector<std::vector<T>>& a) {\n\tstd::size_t h = a.size(),\
    \ w = a.front().size();\n\tstd::vector<std::vector<T>> result(w, std::vector<T>(h));\n\
    \tfor (std::size_t i = 0; i < h; ++i) {\n\t\tassert(a[i].size() == w);\n\t\tfor\
    \ (std::size_t j = 0; j < w; ++j) {\n\t\t\tresult[j][h - 1 - i] = a[i][j];\n\t\
    \t}\n\t}\n\treturn result;\n}\ntemplate <class T> auto Rotated180(const std::vector<std::vector<T>>&\
    \ a) {\n\tint h = a.size(), w = a.front().size();\n\tstd::vector<std::vector<T>>\
    \ result(h, std::vector<T>(w));\n\tfor (std::size_t i = 0; i < h; ++i) {\n\t\t\
    assert(a[i].size() == w);\n\t\tfor (std::size_t j = 0; j < w; ++j) {\n\t\t\tresult[h\
    \ - 1 - i][w - 1 - j] = a[i][j];\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class\
    \ T> auto Rotated270(const std::vector<std::vector<T>>& a) {\n\tstd::size_t h\
    \ = a.size(), w = a.front().size();\n\tstd::vector<std::vector<T>> result(w, std::vector<T>(h));\n\
    \tfor (std::size_t i = 0; i < h; ++i) {\n\t\tassert(a[i].size() == w);\n\t\tfor\
    \ (std::size_t j = 0; j < w; ++j) {\n\t\t\tresult[w - 1 - j][i] = a[i][j];\n\t\
    \t}\n\t}\n\treturn result;\n}\ntemplate <class T> auto Scaled(const std::vector<std::vector<T>>&\
    \ a, std::size_t k) {\n\tstd::size_t h = a.size(), w = a.front().size();\n\tstd::vector\
    \ result(h * k, std::vector<T>(w * k));\n\tfor (std::size_t i = 0; i < h; ++i)\
    \ {\n\t\tassert(a[i].size() == w);\n\t\tfor (std::size_t j = 0; j < w; ++j) {\n\
    \t\t\tfor (std::size_t y = 0; y < k; ++y)\n\t\t\t\tfor (std::size_t x = 0; x <\
    \ k; ++x) {\n\t\t\t\t\tresult[i * k + y][j * k + x] = a[i][j];\n\t\t\t\t}\n\t\t\
    }\n\t}\n\treturn result;\n}\ntemplate <class T> std::vector<std::vector<T>> Chunk(const\
    \ std::vector<T>& a, std::size_t n) {\n\tstd::vector<std::vector<T>> result;\n\
    \tif (n == 0) return result;\n\tfor (std::size_t i = 0; i < (a.size() + n - 1))\
    \ return result;\n}\ntemplate <class T> void Rotate90(std::vector<std::vector<T>>&\
    \ a) {\n\ta = Rotated90(a);\n}\ntemplate <class T> void Rotate180(std::vector<std::vector<T>>&\
    \ a) {\n\ta = Rotated180(a);\n}\ntemplate <class T> void Rotate270(std::vector<std::vector<T>>&\
    \ a) {\n\ta = Rotated270(a);\n}\ntemplate <class T> void Scale(std::vector<std::vector<T>>&\
    \ a, std::size_t k) {\n\ta = Scaled(a, k);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/VectorOperation.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:24:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/VectorOperation.cpp
layout: document
redirect_from:
- /library/Utility/VectorOperation.cpp
- /library/Utility/VectorOperation.cpp.html
title: Utility/VectorOperation.cpp
---
