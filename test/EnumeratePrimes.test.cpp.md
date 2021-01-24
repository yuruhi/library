---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/EnumeratePrimes.cpp
    title: Math/EnumeratePrimes.cpp
  - icon: ':heavy_check_mark:'
    path: Math/Eratosthenes.cpp
    title: Math/Eratosthenes.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C
  bundledCode: "#line 1 \"test/EnumeratePrimes.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C\"\
    \n#line 2 \"Math/Eratosthenes.cpp\"\n#include <vector>\nusing namespace std;\n\
    \nvector<bool> Eratosthenes(size_t n) {\n\tvector<bool> result(n + 1, true);\n\
    \tresult[0] = result[1] = false;\n\tfor (size_t i = 2; i * i <= n; ++i) {\n\t\t\
    if (result[i]) {\n\t\t\tfor (size_t j = i * i; j <= n; j += i) result[j] = false;\n\
    \t\t}\n\t}\n\treturn result;\n}\n#line 4 \"Math/EnumeratePrimes.cpp\"\nusing namespace\
    \ std;\n\nvector<int> EnumeratePrimes(int n) {\n\tvector<int> result;\n\tauto\
    \ p = Eratosthenes(n);\n\tfor (int i = 0; i <= n; ++i) {\n\t\tif (p[i]) result.push_back(i);\n\
    \t}\n\treturn result;\n}\n#line 3 \"test/EnumeratePrimes.test.cpp\"\n#include\
    \ <iostream>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\n\tauto primes = EnumeratePrimes(100000000);\n\
    \tint n;\n\tcin >> n;\n\tint ans = 0;\n\twhile (n--) {\n\t\tint x;\n\t\tcin >>\
    \ x;\n\t\tans += binary_search(primes.begin(), primes.end(), x);\n\t}\n\tcout\
    \ << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C\"\
    \n#include \"./../Math/EnumeratePrimes.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tauto primes = EnumeratePrimes(100000000);\n\tint n;\n\tcin >> n;\n\tint ans\
    \ = 0;\n\twhile (n--) {\n\t\tint x;\n\t\tcin >> x;\n\t\tans += binary_search(primes.begin(),\
    \ primes.end(), x);\n\t}\n\tcout << ans << '\\n';\n}"
  dependsOn:
  - Math/EnumeratePrimes.cpp
  - Math/Eratosthenes.cpp
  isVerificationFile: true
  path: test/EnumeratePrimes.test.cpp
  requiredBy: []
  timestamp: '2020-12-13 11:47:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/EnumeratePrimes.test.cpp
layout: document
redirect_from:
- /verify/test/EnumeratePrimes.test.cpp
- /verify/test/EnumeratePrimes.test.cpp.html
title: test/EnumeratePrimes.test.cpp
---
