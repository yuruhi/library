---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Fibonacci.cpp
    title: Math/Fibonacci.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A
  bundledCode: "#line 1 \"test/Fibonacci.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A\"\
    \n#line 2 \"Math/Fibonacci.cpp\"\n#include <vector>\nusing namespace std;\n\n\
    vector<long long> Fibonacci(int n) {\n\tvector<long long> res(n + 1);\n\tfor (int\
    \ i = 0; i <= n; ++i) {\n\t\tif (i < 2) {\n\t\t\tres[i] = i;\n\t\t} else {\n\t\
    \t\tres[i] = res[i - 1] + res[i - 2];\n\t\t}\n\t}\n\treturn res;\n}\n#line 3 \"\
    test/Fibonacci.test.cpp\"\n#include <iostream>\nusing namespace std;\n\nint main()\
    \ {\n\tint n;\n\tcin >> n;\n\tcout << Fibonacci(n + 1)[n + 1] << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A\"\
    \n#include \"./../Math/Fibonacci.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint n;\n\tcin >> n;\n\tcout << Fibonacci(n + 1)[n + 1] << '\\\
    n';\n}"
  dependsOn:
  - Math/Fibonacci.cpp
  isVerificationFile: true
  path: test/Fibonacci.test.cpp
  requiredBy: []
  timestamp: '2020-10-06 22:30:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Fibonacci.test.cpp
layout: document
redirect_from:
- /verify/test/Fibonacci.test.cpp
- /verify/test/Fibonacci.test.cpp.html
title: test/Fibonacci.test.cpp
---
