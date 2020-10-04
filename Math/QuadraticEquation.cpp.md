---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/QuadraticEquation.cpp\"\n// description : y = ax^2\
    \ + bx + c\noptional<vector<long double>> QuadraticEquation(long long a, long\
    \ long b, long long c) {\n\tlong double A = a, B = b, C = c;\n\tif (a == 0 &&\
    \ b == 0 && c == 0) {\n\t\treturn nullopt;\n\t} else if (a == 0 && b == 0) {\n\
    \t\treturn vector<long double>{};\n\t} else if (a == 0) {\n\t\treturn vector{-(C\
    \ / B)};\n\t} else {\n\t\tlong long d = b * b - 4 * a * c;\n\t\tlong double D\
    \ = static_cast<long double>(d);\n\t\tif (d < 0) {\n\t\t\treturn vector<long double>{};\n\
    \t\t} else if (d == 0) {\n\t\t\treturn vector{-B / (2 * A)};\n\t\t} else {\n\t\
    \t\tlong double ans1 = 0, ans2 = 0;\n\t\t\tif (b > 0) {\n\t\t\t\tans1 = (-B -\
    \ sqrt(D)) / (2 * A);\n\t\t\t} else {\n\t\t\t\tans1 = (-B + sqrt(D)) / (2 * A);\n\
    \t\t\t}\n\t\t\tans2 = (C / A) / ans1;\n\t\t\treturn vector{min(ans1, ans2), max(ans1,\
    \ ans2)};\n\t\t}\n\t}\n}\n"
  code: "// description : y = ax^2 + bx + c\noptional<vector<long double>> QuadraticEquation(long\
    \ long a, long long b, long long c) {\n\tlong double A = a, B = b, C = c;\n\t\
    if (a == 0 && b == 0 && c == 0) {\n\t\treturn nullopt;\n\t} else if (a == 0 &&\
    \ b == 0) {\n\t\treturn vector<long double>{};\n\t} else if (a == 0) {\n\t\treturn\
    \ vector{-(C / B)};\n\t} else {\n\t\tlong long d = b * b - 4 * a * c;\n\t\tlong\
    \ double D = static_cast<long double>(d);\n\t\tif (d < 0) {\n\t\t\treturn vector<long\
    \ double>{};\n\t\t} else if (d == 0) {\n\t\t\treturn vector{-B / (2 * A)};\n\t\
    \t} else {\n\t\t\tlong double ans1 = 0, ans2 = 0;\n\t\t\tif (b > 0) {\n\t\t\t\t\
    ans1 = (-B - sqrt(D)) / (2 * A);\n\t\t\t} else {\n\t\t\t\tans1 = (-B + sqrt(D))\
    \ / (2 * A);\n\t\t\t}\n\t\t\tans2 = (C / A) / ans1;\n\t\t\treturn vector{min(ans1,\
    \ ans2), max(ans1, ans2)};\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/QuadraticEquation.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/QuadraticEquation.cpp
layout: document
redirect_from:
- /library/Math/QuadraticEquation.cpp
- /library/Math/QuadraticEquation.cpp.html
title: Math/QuadraticEquation.cpp
---
