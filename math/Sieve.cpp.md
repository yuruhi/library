---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Sieve.test.cpp
    title: test/Sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/Sieve.cpp\"\n#include <vector>\n#include <map>\n#include\
    \ <utility>\n#include <cassert>\n\nclass Sieve {\n\tint n;\n\tstd::vector<int>\
    \ factor_m, primes_m;\n\npublic:\n\tSieve(int _n) : n(_n), factor_m(_n + 1) {\n\
    \t\tassert(1 <= n);\n\t\tfactor_m[0] = factor_m[1] = -1;\n\t\tfor (long long i\
    \ = 2; i <= n; ++i) {\n\t\t\tif (!factor_m[i]) {\n\t\t\t\tprimes_m.push_back(i);\n\
    \t\t\t\tfactor_m[i] = i;\n\t\t\t\tfor (long long j = i * i; j <= n; j += i) {\n\
    \t\t\t\t\tif (!factor_m[j]) factor_m[j] = i;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\
    \tbool is_prime(int x) const {\n\t\treturn factor_m[x] == x;\n\t}\n\tstd::vector<int>\
    \ primes() const {\n\t\treturn primes_m;\n\t}\n\tstd::vector<int> primes(int x)\
    \ const {\n\t\tstd::vector<int> result;\n\t\tfor (std::size_t i = 0; i < primes_m.size();\
    \ ++i) {\n\t\t\tif (primes_m[i] > x) break;\n\t\t\tresult.push_back(primes_m[i]);\n\
    \t\t}\n\t\treturn result;\n\t}\n\tstd::vector<std::pair<int, int>> prime_factor(int\
    \ x) const {\n\t\tassert(1 <= x);\n\t\tstd::vector<std::pair<int, int>> result;\n\
    \t\twhile (x != 1) {\n\t\t\tif (result.empty() || result.back().first != factor_m[x])\
    \ {\n\t\t\t\tresult.emplace_back(factor_m[x], 1);\n\t\t\t} else {\n\t\t\t\tresult.back().second++;\n\
    \t\t\t}\n\t\t\tx /= factor_m[x];\n\t\t}\n\t\treturn result;\n\t}\n\tstd::map<int,\
    \ int> prime_factor_map(int x) const {\n\t\tassert(1 <= x);\n\t\tstd::map<int,\
    \ int> result;\n\t\twhile (x != 1) {\n\t\t\tresult[factor_m[x]]++;\n\t\t\tx /=\
    \ factor_m[x];\n\t\t}\n\t\treturn result;\n\t}\n\tstd::vector<int> prime_factor_vec(int\
    \ x) const {\n\t\tassert(1 <= x);\n\t\tstd::vector<int> result;\n\t\twhile (x\
    \ != 1) {\n\t\t\tresult.push_back(factor_m[x]);\n\t\t\tx /= factor_m[x];\n\t\t\
    }\n\t\treturn result;\n\t}\n\tint divisors_count(int x) const {\n\t\tassert(1\
    \ <= x);\n\t\tint result = 1;\n\t\tfor (auto [elem, cnt] : prime_factor(x)) {\n\
    \t\t\tresult *= cnt + 1;\n\t\t}\n\t\treturn result;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <map>\n#include <utility>\n#include\
    \ <cassert>\n\nclass Sieve {\n\tint n;\n\tstd::vector<int> factor_m, primes_m;\n\
    \npublic:\n\tSieve(int _n) : n(_n), factor_m(_n + 1) {\n\t\tassert(1 <= n);\n\t\
    \tfactor_m[0] = factor_m[1] = -1;\n\t\tfor (long long i = 2; i <= n; ++i) {\n\t\
    \t\tif (!factor_m[i]) {\n\t\t\t\tprimes_m.push_back(i);\n\t\t\t\tfactor_m[i] =\
    \ i;\n\t\t\t\tfor (long long j = i * i; j <= n; j += i) {\n\t\t\t\t\tif (!factor_m[j])\
    \ factor_m[j] = i;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tbool is_prime(int x) const\
    \ {\n\t\treturn factor_m[x] == x;\n\t}\n\tstd::vector<int> primes() const {\n\t\
    \treturn primes_m;\n\t}\n\tstd::vector<int> primes(int x) const {\n\t\tstd::vector<int>\
    \ result;\n\t\tfor (std::size_t i = 0; i < primes_m.size(); ++i) {\n\t\t\tif (primes_m[i]\
    \ > x) break;\n\t\t\tresult.push_back(primes_m[i]);\n\t\t}\n\t\treturn result;\n\
    \t}\n\tstd::vector<std::pair<int, int>> prime_factor(int x) const {\n\t\tassert(1\
    \ <= x);\n\t\tstd::vector<std::pair<int, int>> result;\n\t\twhile (x != 1) {\n\
    \t\t\tif (result.empty() || result.back().first != factor_m[x]) {\n\t\t\t\tresult.emplace_back(factor_m[x],\
    \ 1);\n\t\t\t} else {\n\t\t\t\tresult.back().second++;\n\t\t\t}\n\t\t\tx /= factor_m[x];\n\
    \t\t}\n\t\treturn result;\n\t}\n\tstd::map<int, int> prime_factor_map(int x) const\
    \ {\n\t\tassert(1 <= x);\n\t\tstd::map<int, int> result;\n\t\twhile (x != 1) {\n\
    \t\t\tresult[factor_m[x]]++;\n\t\t\tx /= factor_m[x];\n\t\t}\n\t\treturn result;\n\
    \t}\n\tstd::vector<int> prime_factor_vec(int x) const {\n\t\tassert(1 <= x);\n\
    \t\tstd::vector<int> result;\n\t\twhile (x != 1) {\n\t\t\tresult.push_back(factor_m[x]);\n\
    \t\t\tx /= factor_m[x];\n\t\t}\n\t\treturn result;\n\t}\n\tint divisors_count(int\
    \ x) const {\n\t\tassert(1 <= x);\n\t\tint result = 1;\n\t\tfor (auto [elem, cnt]\
    \ : prime_factor(x)) {\n\t\t\tresult *= cnt + 1;\n\t\t}\n\t\treturn result;\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Sieve.cpp
  requiredBy: []
  timestamp: '2021-03-21 09:59:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Sieve.test.cpp
documentation_of: math/Sieve.cpp
layout: document
redirect_from:
- /library/math/Sieve.cpp
- /library/math/Sieve.cpp.html
title: math/Sieve.cpp
---
