---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/Divisors.cpp
    title: math/Divisors.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D
  bundledCode: "#line 1 \"test/Divisors.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D\"\
    \n#line 2 \"math/Divisors.cpp\"\n#include <vector>\n#include <cmath>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <class T> vector<T> Divisors(T n)\
    \ {\n\tassert(0 < n);\n\tvector<T> result;\n\tT i = 1;\n\tfor (; i * i < n; ++i)\
    \ {\n\t\tif (n % i == 0) result.push_back(i);\n\t}\n\tbool flag = i * i == n;\n\
    \tif (flag) result.push_back(i);\n\tfor (i = (int)result.size() - 1 - flag; i\
    \ >= 0; --i) {\n\t\tresult.push_back(n / result[i]);\n\t}\n\treturn result;\n\
    }\ntemplate <class T> int DivisorsCount(T n) {\n\tassert(0 < n);\n\tint cnt =\
    \ 0;\n\tT sq = sqrt(n);\n\tfor (T i = 1; i <= sq; ++i) {\n\t\tcnt += n % i ==\
    \ 0;\n\t}\n\treturn cnt * 2 - (sq * sq == n);\n}\ntemplate <class T> T DivisorsSum(T\
    \ n) {\n\tassert(0 < n);\n\tT i = 1, result = 0;\n\tfor (; i * i < n; ++i) {\n\
    \t\tif (n % i == 0) result += i + n / i;\n\t}\n\treturn result + i * (i * i ==\
    \ n);\n}\n#line 3 \"test/Divisors.test.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tint a, b, c;\n\tcin >> a >> b >> c;\n\tint ans = 0;\n\
    \tfor (int d : Divisors(c)) {\n\t\tans += a <= d && d <= b;\n\t}\n\tcout << ans\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D\"\n\
    #include \"./../math/Divisors.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint a, b, c;\n\tcin >> a >> b >> c;\n\tint ans = 0;\n\tfor (int\
    \ d : Divisors(c)) {\n\t\tans += a <= d && d <= b;\n\t}\n\tcout << ans << '\\\
    n';\n}"
  dependsOn:
  - math/Divisors.cpp
  isVerificationFile: true
  path: test/Divisors.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 15:45:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Divisors.test.cpp
layout: document
redirect_from:
- /verify/test/Divisors.test.cpp
- /verify/test/Divisors.test.cpp.html
title: test/Divisors.test.cpp
---
