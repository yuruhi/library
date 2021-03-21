---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/EnumeratePrimes.cpp
    title: math/EnumeratePrimes.cpp
  - icon: ':heavy_check_mark:'
    path: math/Eratosthenes.cpp
    title: math/Eratosthenes.cpp
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
    \n#line 2 \"math/Eratosthenes.cpp\"\n#include <vector>\n\nstd::vector<bool> Eratosthenes(size_t\
    \ n) {\n\tstd::vector<bool> result(n + 1, true);\n\tresult[0] = result[1] = false;\n\
    \tfor (size_t i = 2; i * i <= n; ++i) {\n\t\tif (result[i]) {\n\t\t\tfor (size_t\
    \ j = i * i; j <= n; j += i) result[j] = false;\n\t\t}\n\t}\n\treturn result;\n\
    }\n#line 4 \"math/EnumeratePrimes.cpp\"\n\nstd::vector<int> EnumeratePrimes(std::size_t\
    \ n) {\n\tstd::vector<int> result;\n\tauto p = Eratosthenes(n);\n\tfor (std::size_t\
    \ i = 2; i <= n; ++i) {\n\t\tif (p[i]) result.push_back(i);\n\t}\n\treturn result;\n\
    }\n#line 3 \"test/EnumeratePrimes.test.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tauto primes = EnumeratePrimes(100000000);\n\tint n;\n\tcin >> n;\n\tint ans\
    \ = 0;\n\twhile (n--) {\n\t\tint x;\n\t\tcin >> x;\n\t\tans += binary_search(primes.begin(),\
    \ primes.end(), x);\n\t}\n\tcout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C\"\
    \n#include \"./../math/EnumeratePrimes.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tauto primes = EnumeratePrimes(100000000);\n\tint n;\n\tcin >> n;\n\tint ans\
    \ = 0;\n\twhile (n--) {\n\t\tint x;\n\t\tcin >> x;\n\t\tans += binary_search(primes.begin(),\
    \ primes.end(), x);\n\t}\n\tcout << ans << '\\n';\n}"
  dependsOn:
  - math/EnumeratePrimes.cpp
  - math/Eratosthenes.cpp
  isVerificationFile: true
  path: test/EnumeratePrimes.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/EnumeratePrimes.test.cpp
layout: document
redirect_from:
- /verify/test/EnumeratePrimes.test.cpp
- /verify/test/EnumeratePrimes.test.cpp.html
title: test/EnumeratePrimes.test.cpp
---
