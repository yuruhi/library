---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extGcd.cpp
    title: math/extGcd.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E
  bundledCode: "#line 1 \"test/extGcd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E\"\
    \n#line 2 \"math/extGcd.cpp\"\n#include <tuple>\n\ntemplate <class T> T extGcd(T\
    \ a, T b, T& x, T& y) {\n\tT d = a;\n\tif (b != 0) {\n\t\td = extGcd(b, a % b,\
    \ y, x);\n\t\ty -= (a / b) * x;\n\t} else {\n\t\tx = 1;\n\t\ty = 0;\n\t}\n\treturn\
    \ d;\n}\n\ntemplate <class T> std::tuple<T, T, T> extGcd(T a, T b) {\n\tT x, y;\n\
    \tT gcd = extGcd(a, b, x, y);\n\treturn {gcd, x, y};\n}\n#line 3 \"test/extGcd.test.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tlong long x, y;\n\
    \tcin >> x >> y;\n\tlong long a, b;\n\textGcd(x, y, a, b);\n\tcout << a << ' '\
    \ << b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E\"\
    \n#include \"./../math/extGcd.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tlong long x, y;\n\tcin >> x >> y;\n\tlong long a, b;\n\textGcd(x,\
    \ y, a, b);\n\tcout << a << ' ' << b << '\\n';\n}"
  dependsOn:
  - math/extGcd.cpp
  isVerificationFile: true
  path: test/extGcd.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 15:45:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/extGcd.test.cpp
layout: document
redirect_from:
- /verify/test/extGcd.test.cpp
- /verify/test/extGcd.test.cpp.html
title: test/extGcd.test.cpp
---
