---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Sieve.test.cpp
    title: test/Sieve.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/Sieve.cpp\"\n#include <vector>\n#include <map>\n#include\
    \ <utility>\n#include <cassert>\nusing namespace std;\n\nclass Sieve {\n\tint\
    \ n;\n\tvector<int> factor, primes;\n\npublic:\n\tSieve(int _n) : n(_n), factor(_n\
    \ + 1) {\n\t\tassert(1 <= n);\n\t\tfactor[0] = factor[1] = -1;\n\t\tfor (long\
    \ long i = 2; i <= n; ++i) {\n\t\t\tif (!factor[i]) {\n\t\t\t\tprimes.push_back(i);\n\
    \t\t\t\tfactor[i] = i;\n\t\t\t\tfor (long long j = i * i; j <= n; j += i) {\n\t\
    \t\t\t\tif (!factor[j]) factor[j] = i;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tbool\
    \ is_prime(int x) const {\n\t\treturn factor[x] == x;\n\t}\n\tconst vector<int>&\
    \ get_primes() const {\n\t\treturn primes;\n\t}\n\tvector<pair<int, int>> prime_factor(int\
    \ x) const {\n\t\tassert(1 <= x);\n\t\tvector<pair<int, int>> result;\n\t\twhile\
    \ (x != 1) {\n\t\t\tif (result.empty() || result.back().first != factor[x]) {\n\
    \t\t\t\tresult.emplace_back(factor[x], 1);\n\t\t\t} else {\n\t\t\t\tresult.back().second++;\n\
    \t\t\t}\n\t\t\tx /= factor[x];\n\t\t}\n\t\treturn result;\n\t}\n\tmap<int, int>\
    \ prime_factor_map(int x) const {\n\t\tassert(1 <= x);\n\t\tmap<int, int> result;\n\
    \t\twhile (x != 1) {\n\t\t\tresult[factor[x]]++;\n\t\t\tx /= factor[x];\n\t\t\
    }\n\t\treturn result;\n\t}\n\tvector<int> prime_factor_vec(int x) const {\n\t\t\
    assert(1 <= x);\n\t\tvector<int> result;\n\t\twhile (x != 1) {\n\t\t\tresult.push_back(factor[x]);\n\
    \t\t\tx /= factor[x];\n\t\t}\n\t\treturn result;\n\t}\n\tint divisors_count(int\
    \ x) const {\n\t\tassert(1 <= x);\n\t\tint result = 1;\n\t\tfor (auto [elem, cnt]\
    \ : prime_factor(x)) {\n\t\t\tresult *= cnt + 1;\n\t\t}\n\t\treturn result;\n\t\
    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <map>\n#include <utility>\n#include\
    \ <cassert>\nusing namespace std;\n\nclass Sieve {\n\tint n;\n\tvector<int> factor,\
    \ primes;\n\npublic:\n\tSieve(int _n) : n(_n), factor(_n + 1) {\n\t\tassert(1\
    \ <= n);\n\t\tfactor[0] = factor[1] = -1;\n\t\tfor (long long i = 2; i <= n; ++i)\
    \ {\n\t\t\tif (!factor[i]) {\n\t\t\t\tprimes.push_back(i);\n\t\t\t\tfactor[i]\
    \ = i;\n\t\t\t\tfor (long long j = i * i; j <= n; j += i) {\n\t\t\t\t\tif (!factor[j])\
    \ factor[j] = i;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tbool is_prime(int x) const\
    \ {\n\t\treturn factor[x] == x;\n\t}\n\tconst vector<int>& get_primes() const\
    \ {\n\t\treturn primes;\n\t}\n\tvector<pair<int, int>> prime_factor(int x) const\
    \ {\n\t\tassert(1 <= x);\n\t\tvector<pair<int, int>> result;\n\t\twhile (x !=\
    \ 1) {\n\t\t\tif (result.empty() || result.back().first != factor[x]) {\n\t\t\t\
    \tresult.emplace_back(factor[x], 1);\n\t\t\t} else {\n\t\t\t\tresult.back().second++;\n\
    \t\t\t}\n\t\t\tx /= factor[x];\n\t\t}\n\t\treturn result;\n\t}\n\tmap<int, int>\
    \ prime_factor_map(int x) const {\n\t\tassert(1 <= x);\n\t\tmap<int, int> result;\n\
    \t\twhile (x != 1) {\n\t\t\tresult[factor[x]]++;\n\t\t\tx /= factor[x];\n\t\t\
    }\n\t\treturn result;\n\t}\n\tvector<int> prime_factor_vec(int x) const {\n\t\t\
    assert(1 <= x);\n\t\tvector<int> result;\n\t\twhile (x != 1) {\n\t\t\tresult.push_back(factor[x]);\n\
    \t\t\tx /= factor[x];\n\t\t}\n\t\treturn result;\n\t}\n\tint divisors_count(int\
    \ x) const {\n\t\tassert(1 <= x);\n\t\tint result = 1;\n\t\tfor (auto [elem, cnt]\
    \ : prime_factor(x)) {\n\t\t\tresult *= cnt + 1;\n\t\t}\n\t\treturn result;\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Sieve.cpp
  requiredBy: []
  timestamp: '2020-11-23 16:14:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Sieve.test.cpp
documentation_of: Math/Sieve.cpp
layout: document
redirect_from:
- /library/Math/Sieve.cpp
- /library/Math/Sieve.cpp.html
title: Math/Sieve.cpp
---
