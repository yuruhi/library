---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/QuadraticEquation.test.cpp
    title: test/QuadraticEquation.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/QuadraticEquation.cpp\"\n#include <vector>\n#include\
    \ <optional>\n#include <cmath>\nusing namespace std;\n\ntemplate<class T>\noptional<vector<T>>\
    \ QuadraticEquation(long long a, long long b, long long c) {\n\tT A = a, B = b,\
    \ C = c;\n\tif (a == 0 && b == 0 && c == 0) {\n\t\treturn nullopt;\n\t} else if\
    \ (a == 0 && b == 0) {\n\t\treturn {};\n\t} else if (a == 0) {\n\t\treturn vector{-(C\
    \ / B)};\n\t} else {\n\t\tlong long d = b * b - 4 * a * c;\n\t\tT D = static_cast<T>(d);\n\
    \t\tif (d < 0) {\n\t\t\treturn {};\n\t\t} else if (d == 0) {\n\t\t\treturn vector{-B\
    \ / (2 * A)};\n\t\t} else {\n\t\t\tT ans1 = 0, ans2 = 0;\n\t\t\tif (b > 0) {\n\
    \t\t\t\tans1 = (-B - sqrt(D)) / (2 * A);\n\t\t\t} else {\n\t\t\t\tans1 = (-B +\
    \ sqrt(D)) / (2 * A);\n\t\t\t}\n\t\t\tans2 = (C / A) / ans1;\n\t\t\treturn vector{min(ans1,\
    \ ans2), max(ans1, ans2)};\n\t\t}\n\t}\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <cmath>\n\
    using namespace std;\n\ntemplate<class T>\noptional<vector<T>> QuadraticEquation(long\
    \ long a, long long b, long long c) {\n\tT A = a, B = b, C = c;\n\tif (a == 0\
    \ && b == 0 && c == 0) {\n\t\treturn nullopt;\n\t} else if (a == 0 && b == 0)\
    \ {\n\t\treturn {};\n\t} else if (a == 0) {\n\t\treturn vector{-(C / B)};\n\t\
    } else {\n\t\tlong long d = b * b - 4 * a * c;\n\t\tT D = static_cast<T>(d);\n\
    \t\tif (d < 0) {\n\t\t\treturn {};\n\t\t} else if (d == 0) {\n\t\t\treturn vector{-B\
    \ / (2 * A)};\n\t\t} else {\n\t\t\tT ans1 = 0, ans2 = 0;\n\t\t\tif (b > 0) {\n\
    \t\t\t\tans1 = (-B - sqrt(D)) / (2 * A);\n\t\t\t} else {\n\t\t\t\tans1 = (-B +\
    \ sqrt(D)) / (2 * A);\n\t\t\t}\n\t\t\tans2 = (C / A) / ans1;\n\t\t\treturn vector{min(ans1,\
    \ ans2), max(ans1, ans2)};\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/QuadraticEquation.cpp
  requiredBy: []
  timestamp: '2020-11-23 17:08:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/QuadraticEquation.test.cpp
documentation_of: Math/QuadraticEquation.cpp
layout: document
redirect_from:
- /library/Math/QuadraticEquation.cpp
- /library/Math/QuadraticEquation.cpp.html
title: Math/QuadraticEquation.cpp
---
