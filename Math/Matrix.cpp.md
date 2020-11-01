---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/Fibonacci.cpp
    title: Math/Fibonacci.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Fibonacci.test.cpp
    title: test/Fibonacci.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Matrix.cpp\"\n#include <vector>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> struct Matrix {\n\tsize_t h, w;\n\t\
    vector<vector<T>> A;\n\npublic:\n\tstatic Matrix I(size_t n) {\n\t\tMatrix A(n);\n\
    \t\tfor (size_t i = 0; i < n; ++i) {\n\t\t\tA[i][i] = 1;\n\t\t}\n\t\treturn A;\n\
    \t}\n\tMatrix() {}\n\tMatrix(size_t _h, size_t _w) : h(_h), w(_w), A(h, vector<T>(w,\
    \ 0)) {}\n\tMatrix(size_t _h) : h(_h), w(_h), A(h, vector<T>(w, 0)){};\n\tMatrix(const\
    \ vector<vector<T>>& _A) : h(_A.size()), w(_A[0].size()), A(_A) {}\n\tsize_t height()\
    \ const {\n\t\treturn h;\n\t}\n\tsize_t width() const {\n\t\treturn w;\n\t}\n\t\
    const vector<T>& operator[](int i) const {\n\t\treturn A[i];\n\t}\n\tvector<T>&\
    \ operator[](int i) {\n\t\treturn A[i];\n\t}\n\tconst vector<vector<T>>& operator*()\
    \ const {\n\t\treturn A;\n\t}\n\tMatrix& operator+=(const Matrix& B) {\n\t\tassert(h\
    \ == B.height() && w == B.width());\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\
    \tfor (size_t j = 0; j < w; ++j) {\n\t\t\t\tA[i][j] += B[i][j];\n\t\t\t}\n\t\t\
    }\n\t\treturn *this;\n\t}\n\tMatrix& operator-=(const Matrix& B) {\n\t\tassert(h\
    \ == B.height() && w == B.width());\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\
    \tfor (size_t j = 0; j < w; ++j) {\n\t\t\t\tA[i][j] -= B[i][j];\n\t\t\t}\n\t\t\
    }\n\t\treturn *this;\n\t}\n\tMatrix& operator*=(const Matrix& B) {\n\t\tsize_t\
    \ n = B.width();\n\t\tassert(w == B.height());\n\t\tvector<vector<T>> C(h, vector<T>(n,\
    \ 0));\n\t\tfor (size_t i = 0; i < h; i++) {\n\t\t\tfor (size_t j = 0; j < n;\
    \ j++) {\n\t\t\t\tfor (size_t k = 0; k < w; k++) {\n\t\t\t\t\tC[i][j] += A[i][k]\
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
  code: "#pragma once\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <class T> struct Matrix {\n\tsize_t h, w;\n\tvector<vector<T>> A;\n\
    \npublic:\n\tstatic Matrix I(size_t n) {\n\t\tMatrix A(n);\n\t\tfor (size_t i\
    \ = 0; i < n; ++i) {\n\t\t\tA[i][i] = 1;\n\t\t}\n\t\treturn A;\n\t}\n\tMatrix()\
    \ {}\n\tMatrix(size_t _h, size_t _w) : h(_h), w(_w), A(h, vector<T>(w, 0)) {}\n\
    \tMatrix(size_t _h) : h(_h), w(_h), A(h, vector<T>(w, 0)){};\n\tMatrix(const vector<vector<T>>&\
    \ _A) : h(_A.size()), w(_A[0].size()), A(_A) {}\n\tsize_t height() const {\n\t\
    \treturn h;\n\t}\n\tsize_t width() const {\n\t\treturn w;\n\t}\n\tconst vector<T>&\
    \ operator[](int i) const {\n\t\treturn A[i];\n\t}\n\tvector<T>& operator[](int\
    \ i) {\n\t\treturn A[i];\n\t}\n\tconst vector<vector<T>>& operator*() const {\n\
    \t\treturn A;\n\t}\n\tMatrix& operator+=(const Matrix& B) {\n\t\tassert(h == B.height()\
    \ && w == B.width());\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\tfor (size_t\
    \ j = 0; j < w; ++j) {\n\t\t\t\tA[i][j] += B[i][j];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\tMatrix& operator-=(const Matrix& B) {\n\t\tassert(h == B.height()\
    \ && w == B.width());\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\tfor (size_t\
    \ j = 0; j < w; ++j) {\n\t\t\t\tA[i][j] -= B[i][j];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\tMatrix& operator*=(const Matrix& B) {\n\t\tsize_t n = B.width();\n\
    \t\tassert(w == B.height());\n\t\tvector<vector<T>> C(h, vector<T>(n, 0));\n\t\
    \tfor (size_t i = 0; i < h; i++) {\n\t\t\tfor (size_t j = 0; j < n; j++) {\n\t\
    \t\t\tfor (size_t k = 0; k < w; k++) {\n\t\t\t\t\tC[i][j] += A[i][k] * B[k][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tA.swap(C);\n\t\treturn *this;\n\t}\n\tMatrix& operator^=(long\
    \ long k) {\n\t\tMatrix B = Matrix::I(h);\n\t\twhile (k > 0) {\n\t\t\tif (k &\
    \ 1) {\n\t\t\t\tB *= *this;\n\t\t\t}\n\t\t\t*this *= *this;\n\t\t\tk >>= 1;\n\t\
    \t}\n\t\tA.swap(B.A);\n\t\treturn *this;\n\t}\n\tMatrix operator+(const Matrix&\
    \ B) const {\n\t\treturn Matrix(*this) += B;\n\t}\n\tMatrix operator-(const Matrix&\
    \ B) const {\n\t\treturn Matrix(*this) -= B;\n\t}\n\tMatrix operator*(const Matrix&\
    \ B) const {\n\t\treturn Matrix(*this) *= B;\n\t}\n\tMatrix operator^(const long\
    \ long k) const {\n\t\treturn Matrix(*this) ^= k;\n\t}\n\tMatrix pow(long long\
    \ k) const {\n\t\treturn *this ^ k;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Matrix.cpp
  requiredBy:
  - Math/Fibonacci.cpp
  timestamp: '2020-10-28 22:10:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Fibonacci.test.cpp
documentation_of: Math/Matrix.cpp
layout: document
redirect_from:
- /library/Math/Matrix.cpp
- /library/Math/Matrix.cpp.html
title: Math/Matrix.cpp
---
