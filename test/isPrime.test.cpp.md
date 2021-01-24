---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/isPrime.cpp
    title: Math/isPrime.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C
  bundledCode: "#line 1 \"test/isPrime.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C\"\
    \n#line 2 \"Math/isPrime.cpp\"\n\ntemplate <class T> bool isPrime(T n) {\n\tif\
    \ (n == 2) return true;\n\tif (n < 2 || n % 2 == 0) return false;\n\tfor (T i\
    \ = 3; i * i <= n; i += 2) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn\
    \ true;\n}\n#line 3 \"test/isPrime.test.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n;\n\tcin >> n;\n\tint ans = 0;\n\twhile (n--) {\n\t\tint x;\n\t\tcin >>\
    \ x;\n\t\tans += isPrime(x);\n\t}\n\tcout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C\"\n\
    #include \"./../Math/isPrime.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint\
    \ n;\n\tcin >> n;\n\tint ans = 0;\n\twhile (n--) {\n\t\tint x;\n\t\tcin >> x;\n\
    \t\tans += isPrime(x);\n\t}\n\tcout << ans << '\\n';\n}"
  dependsOn:
  - Math/isPrime.cpp
  isVerificationFile: true
  path: test/isPrime.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 16:14:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/isPrime.test.cpp
layout: document
redirect_from:
- /verify/test/isPrime.test.cpp
- /verify/test/isPrime.test.cpp.html
title: test/isPrime.test.cpp
---
