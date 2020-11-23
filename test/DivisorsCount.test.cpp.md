---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/Divisors.cpp
    title: Math/Divisors.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/1562
  bundledCode: "#line 1 \"test/DivisorsCount.test.cpp\"\n#define IGNORE\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/1562\"\n#line 2 \"Math/Divisors.cpp\"\
    \n#include <vector>\n#include <cmath>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <class T> vector<T> Divisors(T n) {\n\tassert(0 < n);\n\tvector<T>\
    \ result;\n\tT i = 1;\n\tfor (; i * i < n; ++i) {\n\t\tif (n % i == 0) result.push_back(i);\n\
    \t}\n\tbool flag = i * i == n;\n\tif (flag) result.push_back(i);\n\tfor (i = (int)result.size()\
    \ - 1 - flag; i >= 0; --i) {\n\t\tresult.push_back(n / result[i]);\n\t}\n\treturn\
    \ result;\n}\ntemplate <class T> int DivisorsCount(T n) {\n\tassert(0 < n);\n\t\
    int cnt = 0;\n\tT sq = sqrt(n);\n\tfor (T i = 1; i <= sq; ++i) {\n\t\tcnt += n\
    \ % i == 0;\n\t}\n\treturn cnt * 2 - (sq * sq == n);\n}\ntemplate <class T> T\
    \ DivisorsSum(T n) {\n\tassert(0 < n);\n\tT i = 1, result = 0;\n\tfor (; i * i\
    \ < n; ++i) {\n\t\tif (n % i == 0) result += i + n / i;\n\t}\n\treturn result\
    \ + i * (i * i == n);\n}\n#line 4 \"test/DivisorsCount.test.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\tint n;\n\tcin >> n;\n\tfor (int i = 1;;\
    \ ++i) {\n\t\tif (DivisorsCount(i) == n) {\n\t\t\tcout << i << '\\n';\n\t\t\t\
    return 0;\n\t\t}\n\t}\n}\n"
  code: "#define IGNORE\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/1562\"\
    \n#include \"./../Math/Divisors.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint n;\n\tcin >> n;\n\tfor (int i = 1;; ++i) {\n\t\tif (DivisorsCount(i)\
    \ == n) {\n\t\t\tcout << i << '\\n';\n\t\t\treturn 0;\n\t\t}\n\t}\n}"
  dependsOn:
  - Math/Divisors.cpp
  isVerificationFile: true
  path: test/DivisorsCount.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 16:58:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/DivisorsCount.test.cpp
layout: document
redirect_from:
- /verify/test/DivisorsCount.test.cpp
- /verify/test/DivisorsCount.test.cpp.html
title: test/DivisorsCount.test.cpp
---
