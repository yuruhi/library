---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/Fibonacci.cpp
    title: math/Fibonacci.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/EnumerateFibonacci.test.cpp
    title: test/EnumerateFibonacci.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Fibonacci.test.cpp
    title: test/Fibonacci.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/Matrix.cpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate <class T> struct Matrix {\npublic:\n\tusing value_type = T;\n\tusing\
    \ data_type = std::vector<std::vector<value_type>>;\n\nprivate:\n\tstd::size_t\
    \ h, w;\n\tdata_type A;\n\npublic:\n\tstatic Matrix I(std::size_t n) {\n\t\tMatrix\
    \ A(n);\n\t\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tA[i][i] = 1;\n\t\t}\n\
    \t\treturn A;\n\t}\n\tMatrix() {}\n\tMatrix(std::size_t _h, std::size_t _w) :\
    \ h(_h), w(_w), A(h, std::vector<T>(w, 0)) {}\n\tMatrix(std::size_t _h) : h(_h),\
    \ w(_h), A(h, std::vector<T>(w, 0)) {}\n\tMatrix(const data_type& _A) : h(_A.size()),\
    \ w(_A[0].size()), A(_A) {}\n\tstd::size_t height() const {\n\t\treturn h;\n\t\
    }\n\tstd::size_t width() const {\n\t\treturn w;\n\t}\n\tconst std::vector<T>&\
    \ operator[](int i) const {\n\t\treturn A[i];\n\t}\n\tstd::vector<T>& operator[](int\
    \ i) {\n\t\treturn A[i];\n\t}\n\tconst data_type& operator*() const {\n\t\treturn\
    \ A;\n\t}\n\tMatrix& operator+=(const Matrix& B) {\n\t\tassert(h == B.height()\
    \ && w == B.width());\n\t\tfor (std::size_t i = 0; i < h; ++i) {\n\t\t\tfor (std::size_t\
    \ j = 0; j < w; ++j) {\n\t\t\t\tA[i][j] += B[i][j];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\tMatrix& operator-=(const Matrix& B) {\n\t\tassert(h == B.height()\
    \ && w == B.width());\n\t\tfor (std::size_t i = 0; i < h; ++i) {\n\t\t\tfor (std::size_t\
    \ j = 0; j < w; ++j) {\n\t\t\t\tA[i][j] -= B[i][j];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\tMatrix& operator*=(const Matrix& B) {\n\t\tstd::size_t n = B.width();\n\
    \t\tassert(w == B.height());\n\t\tdata_type C(h, std::vector<T>(n, 0));\n\t\t\
    for (std::size_t i = 0; i < h; i++) {\n\t\t\tfor (std::size_t j = 0; j < n; j++)\
    \ {\n\t\t\t\tfor (std::size_t k = 0; k < w; k++) {\n\t\t\t\t\tC[i][j] += A[i][k]\
    \ * B[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tA.swap(C);\n\t\treturn *this;\n\t\
    }\n\tMatrix& operator^=(long long k) {\n\t\tMatrix B = Matrix::I(h);\n\t\twhile\
    \ (k > 0) {\n\t\t\tif (k & 1) {\n\t\t\t\tB *= *this;\n\t\t\t}\n\t\t\t*this *=\
    \ *this;\n\t\t\tk >>= 1;\n\t\t}\n\t\tA.swap(B.A);\n\t\treturn *this;\n\t}\n\t\
    Matrix operator+(const Matrix& B) const {\n\t\treturn Matrix(*this) += B;\n\t\
    }\n\tMatrix operator-(const Matrix& B) const {\n\t\treturn Matrix(*this) -= B;\n\
    \t}\n\tMatrix operator*(const Matrix& B) const {\n\t\treturn Matrix(*this) *=\
    \ B;\n\t}\n\tMatrix operator^(const long long k) const {\n\t\treturn Matrix(*this)\
    \ ^= k;\n\t}\n\tMatrix pow(long long k) const {\n\t\treturn *this ^ k;\n\t}\n\
    };\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\ntemplate <class T>\
    \ struct Matrix {\npublic:\n\tusing value_type = T;\n\tusing data_type = std::vector<std::vector<value_type>>;\n\
    \nprivate:\n\tstd::size_t h, w;\n\tdata_type A;\n\npublic:\n\tstatic Matrix I(std::size_t\
    \ n) {\n\t\tMatrix A(n);\n\t\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tA[i][i]\
    \ = 1;\n\t\t}\n\t\treturn A;\n\t}\n\tMatrix() {}\n\tMatrix(std::size_t _h, std::size_t\
    \ _w) : h(_h), w(_w), A(h, std::vector<T>(w, 0)) {}\n\tMatrix(std::size_t _h)\
    \ : h(_h), w(_h), A(h, std::vector<T>(w, 0)) {}\n\tMatrix(const data_type& _A)\
    \ : h(_A.size()), w(_A[0].size()), A(_A) {}\n\tstd::size_t height() const {\n\t\
    \treturn h;\n\t}\n\tstd::size_t width() const {\n\t\treturn w;\n\t}\n\tconst std::vector<T>&\
    \ operator[](int i) const {\n\t\treturn A[i];\n\t}\n\tstd::vector<T>& operator[](int\
    \ i) {\n\t\treturn A[i];\n\t}\n\tconst data_type& operator*() const {\n\t\treturn\
    \ A;\n\t}\n\tMatrix& operator+=(const Matrix& B) {\n\t\tassert(h == B.height()\
    \ && w == B.width());\n\t\tfor (std::size_t i = 0; i < h; ++i) {\n\t\t\tfor (std::size_t\
    \ j = 0; j < w; ++j) {\n\t\t\t\tA[i][j] += B[i][j];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\tMatrix& operator-=(const Matrix& B) {\n\t\tassert(h == B.height()\
    \ && w == B.width());\n\t\tfor (std::size_t i = 0; i < h; ++i) {\n\t\t\tfor (std::size_t\
    \ j = 0; j < w; ++j) {\n\t\t\t\tA[i][j] -= B[i][j];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\tMatrix& operator*=(const Matrix& B) {\n\t\tstd::size_t n = B.width();\n\
    \t\tassert(w == B.height());\n\t\tdata_type C(h, std::vector<T>(n, 0));\n\t\t\
    for (std::size_t i = 0; i < h; i++) {\n\t\t\tfor (std::size_t j = 0; j < n; j++)\
    \ {\n\t\t\t\tfor (std::size_t k = 0; k < w; k++) {\n\t\t\t\t\tC[i][j] += A[i][k]\
    \ * B[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tA.swap(C);\n\t\treturn *this;\n\t\
    }\n\tMatrix& operator^=(long long k) {\n\t\tMatrix B = Matrix::I(h);\n\t\twhile\
    \ (k > 0) {\n\t\t\tif (k & 1) {\n\t\t\t\tB *= *this;\n\t\t\t}\n\t\t\t*this *=\
    \ *this;\n\t\t\tk >>= 1;\n\t\t}\n\t\tA.swap(B.A);\n\t\treturn *this;\n\t}\n\t\
    Matrix operator+(const Matrix& B) const {\n\t\treturn Matrix(*this) += B;\n\t\
    }\n\tMatrix operator-(const Matrix& B) const {\n\t\treturn Matrix(*this) -= B;\n\
    \t}\n\tMatrix operator*(const Matrix& B) const {\n\t\treturn Matrix(*this) *=\
    \ B;\n\t}\n\tMatrix operator^(const long long k) const {\n\t\treturn Matrix(*this)\
    \ ^= k;\n\t}\n\tMatrix pow(long long k) const {\n\t\treturn *this ^ k;\n\t}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Matrix.cpp
  requiredBy:
  - math/Fibonacci.cpp
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/EnumerateFibonacci.test.cpp
  - test/Fibonacci.test.cpp
documentation_of: math/Matrix.cpp
layout: document
redirect_from:
- /library/math/Matrix.cpp
- /library/math/Matrix.cpp.html
title: math/Matrix.cpp
---
