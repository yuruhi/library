---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Sieve.cpp
    title: Math/Sieve.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C
  bundledCode: "#line 1 \"test/Sieve.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C\"\
    \n#line 2 \"Math/Sieve.cpp\"\n#include <vector>\n#include <map>\n#include <utility>\n\
    #include <cassert>\nusing namespace std;\n\nclass Sieve {\n\tint n;\n\tvector<int>\
    \ factor_m, primes_m;\n\npublic:\n\tSieve(int _n) : n(_n), factor_m(_n + 1) {\n\
    \t\tassert(1 <= n);\n\t\tfactor_m[0] = factor_m[1] = -1;\n\t\tfor (long long i\
    \ = 2; i <= n; ++i) {\n\t\t\tif (!factor_m[i]) {\n\t\t\t\tprimes_m.push_back(i);\n\
    \t\t\t\tfactor_m[i] = i;\n\t\t\t\tfor (long long j = i * i; j <= n; j += i) {\n\
    \t\t\t\t\tif (!factor_m[j]) factor_m[j] = i;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\
    \tbool is_prime(int x) const {\n\t\treturn factor_m[x] == x;\n\t}\n\tvector<int>\
    \ primes() const {\n\t\treturn primes_m;\n\t}\n\tvector<int> primes(int x) const\
    \ {\n\t\tvector<int> result;\n\t\tfor (size_t i = 0; i < primes_m.size(); ++i)\
    \ {\n\t\t\tif (primes_m[i] > x) break;\n\t\t\tresult.push_back(primes_m[i]);\n\
    \t\t}\n\t\treturn result;\n\t}\n\tvector<pair<int, int>> prime_factor(int x) const\
    \ {\n\t\tassert(1 <= x);\n\t\tvector<pair<int, int>> result;\n\t\twhile (x !=\
    \ 1) {\n\t\t\tif (result.empty() || result.back().first != factor_m[x]) {\n\t\t\
    \t\tresult.emplace_back(factor_m[x], 1);\n\t\t\t} else {\n\t\t\t\tresult.back().second++;\n\
    \t\t\t}\n\t\t\tx /= factor_m[x];\n\t\t}\n\t\treturn result;\n\t}\n\tmap<int, int>\
    \ prime_factor_map(int x) const {\n\t\tassert(1 <= x);\n\t\tmap<int, int> result;\n\
    \t\twhile (x != 1) {\n\t\t\tresult[factor_m[x]]++;\n\t\t\tx /= factor_m[x];\n\t\
    \t}\n\t\treturn result;\n\t}\n\tvector<int> prime_factor_vec(int x) const {\n\t\
    \tassert(1 <= x);\n\t\tvector<int> result;\n\t\twhile (x != 1) {\n\t\t\tresult.push_back(factor_m[x]);\n\
    \t\t\tx /= factor_m[x];\n\t\t}\n\t\treturn result;\n\t}\n\tint divisors_count(int\
    \ x) const {\n\t\tassert(1 <= x);\n\t\tint result = 1;\n\t\tfor (auto [elem, cnt]\
    \ : prime_factor(x)) {\n\t\t\tresult *= cnt + 1;\n\t\t}\n\t\treturn result;\n\t\
    }\n};\n#line 3 \"test/Sieve.test.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    #line 6 \"test/Sieve.test.cpp\"\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\n\tSieve sieve(100000000);\n\tconst auto&\
    \ primes = sieve.primes();\n\tint n;\n\tcin >> n;\n\tint ans = 0;\n\twhile (n--)\
    \ {\n\t\tint x;\n\t\tcin >> x;\n\t\tans += sieve.is_prime(x);\n\t\tassert(sieve.is_prime(x)\
    \ == binary_search(primes.begin(), primes.end(), x));\n\t}\n\tcout << ans << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C\"\
    \n#include \"./../Math/Sieve.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\n\tSieve sieve(100000000);\n\tconst auto&\
    \ primes = sieve.primes();\n\tint n;\n\tcin >> n;\n\tint ans = 0;\n\twhile (n--)\
    \ {\n\t\tint x;\n\t\tcin >> x;\n\t\tans += sieve.is_prime(x);\n\t\tassert(sieve.is_prime(x)\
    \ == binary_search(primes.begin(), primes.end(), x));\n\t}\n\tcout << ans << '\\\
    n';\n}"
  dependsOn:
  - Math/Sieve.cpp
  isVerificationFile: true
  path: test/Sieve.test.cpp
  requiredBy: []
  timestamp: '2020-12-31 12:10:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Sieve.test.cpp
layout: document
redirect_from:
- /verify/test/Sieve.test.cpp
- /verify/test/Sieve.test.cpp.html
title: test/Sieve.test.cpp
---
