---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/QuadraticEquation.test.cpp
    title: test/QuadraticEquation.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/QuadraticEquation.cpp\"\n#include <vector>\n#include\
    \ <optional>\n#include <cmath>\n\ntemplate <class T>\nstd::optional<std::vector<T>>\
    \ QuadraticEquation(long long a, long long b, long long c) {\n\tT A = a, B = b,\
    \ C = c;\n\tif (a == 0 && b == 0 && c == 0) {\n\t\treturn std::nullopt;\n\t} else\
    \ if (a == 0 && b == 0) {\n\t\treturn std::vector<T>();\n\t} else if (a == 0)\
    \ {\n\t\treturn std::vector{-(C / B)};\n\t} else {\n\t\tlong long d = b * b -\
    \ 4 * a * c;\n\t\tT D = static_cast<T>(d);\n\t\tif (d < 0) {\n\t\t\treturn std::vector<T>();\n\
    \t\t} else if (d == 0) {\n\t\t\treturn std::vector{-B / (2 * A)};\n\t\t} else\
    \ {\n\t\t\tT ans1 = 0, ans2 = 0;\n\t\t\tif (b > 0) {\n\t\t\t\tans1 = (-B - sqrt(D))\
    \ / (2 * A);\n\t\t\t} else {\n\t\t\t\tans1 = (-B + sqrt(D)) / (2 * A);\n\t\t\t\
    }\n\t\t\tans2 = (C / A) / ans1;\n\t\t\treturn std::vector{min(ans1, ans2), max(ans1,\
    \ ans2)};\n\t\t}\n\t}\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <cmath>\n\n\
    template <class T>\nstd::optional<std::vector<T>> QuadraticEquation(long long\
    \ a, long long b, long long c) {\n\tT A = a, B = b, C = c;\n\tif (a == 0 && b\
    \ == 0 && c == 0) {\n\t\treturn std::nullopt;\n\t} else if (a == 0 && b == 0)\
    \ {\n\t\treturn std::vector<T>();\n\t} else if (a == 0) {\n\t\treturn std::vector{-(C\
    \ / B)};\n\t} else {\n\t\tlong long d = b * b - 4 * a * c;\n\t\tT D = static_cast<T>(d);\n\
    \t\tif (d < 0) {\n\t\t\treturn std::vector<T>();\n\t\t} else if (d == 0) {\n\t\
    \t\treturn std::vector{-B / (2 * A)};\n\t\t} else {\n\t\t\tT ans1 = 0, ans2 =\
    \ 0;\n\t\t\tif (b > 0) {\n\t\t\t\tans1 = (-B - sqrt(D)) / (2 * A);\n\t\t\t} else\
    \ {\n\t\t\t\tans1 = (-B + sqrt(D)) / (2 * A);\n\t\t\t}\n\t\t\tans2 = (C / A) /\
    \ ans1;\n\t\t\treturn std::vector{min(ans1, ans2), max(ans1, ans2)};\n\t\t}\n\t\
    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/QuadraticEquation.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/QuadraticEquation.test.cpp
documentation_of: math/QuadraticEquation.cpp
layout: document
redirect_from:
- /library/math/QuadraticEquation.cpp
- /library/math/QuadraticEquation.cpp.html
title: math/QuadraticEquation.cpp
---
