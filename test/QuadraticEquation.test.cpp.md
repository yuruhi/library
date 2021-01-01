---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/QuadraticEquation.cpp
    title: Math/QuadraticEquation.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-4
    PROBLEM: https://yukicoder.me/problems/no/1179
    links:
    - https://yukicoder.me/problems/no/1179
  bundledCode: "#line 1 \"test/QuadraticEquation.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1179\"\
    \n#define ERROR \"1e-4\"\n#line 2 \"Math/QuadraticEquation.cpp\"\n#include <vector>\n\
    #include <optional>\n#include <cmath>\nusing namespace std;\n\ntemplate <class\
    \ T>\noptional<vector<T>> QuadraticEquation(long long a, long long b, long long\
    \ c) {\n\tT A = a, B = b, C = c;\n\tif (a == 0 && b == 0 && c == 0) {\n\t\treturn\
    \ nullopt;\n\t} else if (a == 0 && b == 0) {\n\t\treturn {};\n\t} else if (a ==\
    \ 0) {\n\t\treturn vector{-(C / B)};\n\t} else {\n\t\tlong long d = b * b - 4\
    \ * a * c;\n\t\tT D = static_cast<T>(d);\n\t\tif (d < 0) {\n\t\t\treturn {};\n\
    \t\t} else if (d == 0) {\n\t\t\treturn vector{-B / (2 * A)};\n\t\t} else {\n\t\
    \t\tT ans1 = 0, ans2 = 0;\n\t\t\tif (b > 0) {\n\t\t\t\tans1 = (-B - sqrt(D)) /\
    \ (2 * A);\n\t\t\t} else {\n\t\t\t\tans1 = (-B + sqrt(D)) / (2 * A);\n\t\t\t}\n\
    \t\t\tans2 = (C / A) / ans1;\n\t\t\treturn vector{min(ans1, ans2), max(ans1, ans2)};\n\
    \t\t}\n\t}\n}\n#line 4 \"test/QuadraticEquation.test.cpp\"\n#include <iostream>\n\
    #include <algorithm>\n#include <cassert>\nusing namespace std;\n\nint main() {\n\
    \tint a, b, c;\n\tcin >> a >> b >> c;\n\tauto ans = *QuadraticEquation<long double>(a,\
    \ b, c);\n\tsort(ans.begin(), ans.end());\n\tif (ans.empty()) {\n\t\tputs(\"imaginary\"\
    );\n\t} else if (ans.size() == 1) {\n\t\tprintf(\"%.6Lf\\n\", ans[0]);\n\t} else\
    \ if (ans.size() == 2) {\n\t\tprintf(\"%.6Lf %.6Lf\\n\", ans[0], ans[1]);\n\t\
    } else {\n\t\tassert(false);\n\t}\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1179\"\n#define ERROR\
    \ \"1e-4\"\n#include \"./../Math/QuadraticEquation.cpp\"\n#include <iostream>\n\
    #include <algorithm>\n#include <cassert>\nusing namespace std;\n\nint main() {\n\
    \tint a, b, c;\n\tcin >> a >> b >> c;\n\tauto ans = *QuadraticEquation<long double>(a,\
    \ b, c);\n\tsort(ans.begin(), ans.end());\n\tif (ans.empty()) {\n\t\tputs(\"imaginary\"\
    );\n\t} else if (ans.size() == 1) {\n\t\tprintf(\"%.6Lf\\n\", ans[0]);\n\t} else\
    \ if (ans.size() == 2) {\n\t\tprintf(\"%.6Lf %.6Lf\\n\", ans[0], ans[1]);\n\t\
    } else {\n\t\tassert(false);\n\t}\n}"
  dependsOn:
  - Math/QuadraticEquation.cpp
  isVerificationFile: true
  path: test/QuadraticEquation.test.cpp
  requiredBy: []
  timestamp: '2021-01-01 17:28:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/QuadraticEquation.test.cpp
layout: document
redirect_from:
- /verify/test/QuadraticEquation.test.cpp
- /verify/test/QuadraticEquation.test.cpp.html
title: test/QuadraticEquation.test.cpp
---
