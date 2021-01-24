---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Fibonacci.cpp
    title: Math/Fibonacci.cpp
  - icon: ':heavy_check_mark:'
    path: Math/Matrix.cpp
    title: Math/Matrix.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A
  bundledCode: "#line 1 \"test/EnumerateFibonacci.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A\"\
    \n#line 2 \"Math/Matrix.cpp\"\n#include <vector>\n#include <cassert>\nusing namespace\
    \ std;\n\ntemplate <class T> struct Matrix {\npublic:\n\tusing value_type = T;\n\
    \tusing data_type = vector<vector<value_type>>;\n\nprivate:\n\tsize_t h, w;\n\t\
    data_type A;\n\npublic:\n\tstatic Matrix I(size_t n) {\n\t\tMatrix A(n);\n\t\t\
    for (size_t i = 0; i < n; ++i) {\n\t\t\tA[i][i] = 1;\n\t\t}\n\t\treturn A;\n\t\
    }\n\tMatrix() {}\n\tMatrix(size_t _h, size_t _w) : h(_h), w(_w), A(h, vector<T>(w,\
    \ 0)) {}\n\tMatrix(size_t _h) : h(_h), w(_h), A(h, vector<T>(w, 0)) {}\n\tMatrix(const\
    \ data_type& _A) : h(_A.size()), w(_A[0].size()), A(_A) {}\n\tsize_t height()\
    \ const {\n\t\treturn h;\n\t}\n\tsize_t width() const {\n\t\treturn w;\n\t}\n\t\
    const vector<T>& operator[](int i) const {\n\t\treturn A[i];\n\t}\n\tvector<T>&\
    \ operator[](int i) {\n\t\treturn A[i];\n\t}\n\tconst data_type& operator*() const\
    \ {\n\t\treturn A;\n\t}\n\tMatrix& operator+=(const Matrix& B) {\n\t\tassert(h\
    \ == B.height() && w == B.width());\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\
    \tfor (size_t j = 0; j < w; ++j) {\n\t\t\t\tA[i][j] += B[i][j];\n\t\t\t}\n\t\t\
    }\n\t\treturn *this;\n\t}\n\tMatrix& operator-=(const Matrix& B) {\n\t\tassert(h\
    \ == B.height() && w == B.width());\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\
    \tfor (size_t j = 0; j < w; ++j) {\n\t\t\t\tA[i][j] -= B[i][j];\n\t\t\t}\n\t\t\
    }\n\t\treturn *this;\n\t}\n\tMatrix& operator*=(const Matrix& B) {\n\t\tsize_t\
    \ n = B.width();\n\t\tassert(w == B.height());\n\t\tdata_type C(h, vector<T>(n,\
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
    };\n#line 4 \"Math/Fibonacci.cpp\"\nusing namespace std;\n\ntemplate <class value_type>\
    \ value_type Fibonacci(long long n) {\n\tMatrix<value_type> A(vector<vector<value_type>>{{1,\
    \ 1}, {1, 0}});\n\tMatrix<value_type> B(vector<vector<value_type>>{{1}, {0}});\n\
    \treturn (A.pow(n) * B)[1][0];\n}\n\ntemplate <class value_type = long long> vector<value_type>\
    \ EnumerateFibonacci(int n) {\n\tvector<value_type> result(n + 1);\n\tfor (int\
    \ i = 0; i <= n; ++i) {\n\t\tif (i < 2) {\n\t\t\tresult[i] = i;\n\t\t} else {\n\
    \t\t\tresult[i] = result[i - 1] + result[i - 2];\n\t\t}\n\t}\n\treturn result;\n\
    }\n#line 3 \"test/EnumerateFibonacci.test.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tint n;\n\tcin >> n;\n\tcout << EnumerateFibonacci<long\
    \ long>(n + 1)[n + 1] << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A\"\
    \n#include \"./../Math/Fibonacci.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint n;\n\tcin >> n;\n\tcout << EnumerateFibonacci<long long>(n\
    \ + 1)[n + 1] << '\\n';\n}"
  dependsOn:
  - Math/Fibonacci.cpp
  - Math/Matrix.cpp
  isVerificationFile: true
  path: test/EnumerateFibonacci.test.cpp
  requiredBy: []
  timestamp: '2020-12-13 11:47:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/EnumerateFibonacci.test.cpp
layout: document
redirect_from:
- /verify/test/EnumerateFibonacci.test.cpp
- /verify/test/EnumerateFibonacci.test.cpp.html
title: test/EnumerateFibonacci.test.cpp
---
