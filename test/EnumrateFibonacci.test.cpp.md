---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/EnumrateFibonacci.cpp
    title: Math/EnumrateFibonacci.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A
  bundledCode: "#line 1 \"test/EnumrateFibonacci.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A\"\
    \n#line 2 \"Math/EnumrateFibonacci.cpp\"\n#include <vector>\nusing namespace std;\n\
    \ntemplate <class value_type = long long> vector<value_type> EnumrateFibonacci(int\
    \ n) {\n\tvector<value_type> result(n + 1);\n\tfor (int i = 0; i <= n; ++i) {\n\
    \t\tif (i < 2) {\n\t\t\tresult[i] = i;\n\t\t} else {\n\t\t\tresult[i] = result[i\
    \ - 1] + result[i - 2];\n\t\t}\n\t}\n\treturn result;\n}\n#line 3 \"test/EnumrateFibonacci.test.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tint n;\n\tcin >>\
    \ n;\n\tcout << EnumrateFibonacci<long long>(n + 1)[n + 1] << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A\"\
    \n#include \"./../Math/EnumrateFibonacci.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tint n;\n\tcin >> n;\n\tcout << EnumrateFibonacci<long\
    \ long>(n + 1)[n + 1] << '\\n';\n}"
  dependsOn:
  - Math/EnumrateFibonacci.cpp
  isVerificationFile: true
  path: test/EnumrateFibonacci.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 16:47:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/EnumrateFibonacci.test.cpp
layout: document
redirect_from:
- /verify/test/EnumrateFibonacci.test.cpp
- /verify/test/EnumrateFibonacci.test.cpp.html
title: test/EnumrateFibonacci.test.cpp
---
