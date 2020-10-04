---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Sieve.cpp\"\n// description : \u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9 O(N log log N)\u3001\u7D20\u56E0\u6570\u5206\u89E3\
    \ O(\u7D20\u56E0\u6570\u306E\u500B\u6570)\nstruct Sieve {\n\tint n;\n\tvector<int>\
    \ f, primes;\n\tSieve(int _n) : n(_n), f(_n + 1) {\n\t\tassert(1 <= n);\n\t\t\
    f[0] = f[1] = -1;\n\t\tfor (long long i = 2; i <= n; ++i)\n\t\t\tif (!f[i]) {\n\
    \t\t\t\tprimes.push_back(i);\n\t\t\t\tf[i] = i;\n\t\t\t\tfor (long long j = i\
    \ * i; j <= n; j += i)\n\t\t\t\t\tif (!f[j]) f[j] = i;\n\t\t\t}\n\t}\n\tbool is_prime(int\
    \ x) const {\n\t\treturn f[x] == x;\n\t}\n\tvector<pair<int, int>> factor(int\
    \ x) const {\n\t\tassert(1 <= x);\n\t\tvector<pair<int, int>> res;\n\t\twhile\
    \ (x != 1) {\n\t\t\tif (res.empty() || res.back().first != f[x]) {\n\t\t\t\tres.emplace_back(f[x],\
    \ 1);\n\t\t\t} else {\n\t\t\t\tres.back().second++;\n\t\t\t}\n\t\t\tx /= f[x];\n\
    \t\t}\n\t\treturn res;\n\t}\n\tmap<int, int> factor_map(int x) const {\n\t\tassert(1\
    \ <= x);\n\t\tmap<int, int> res;\n\t\twhile (x != 1) {\n\t\t\tres[f[x]]++;\n\t\
    \t\tx /= f[x];\n\t\t}\n\t\treturn res;\n\t}\n\tvector<int> factor_vec(int x) const\
    \ {\n\t\tassert(1 <= x);\n\t\tvector<int> res;\n\t\twhile (x != 1) {\n\t\t\tres.push_back(f[x]);\n\
    \t\t\tx /= f[x];\n\t\t}\n\t\treturn res;\n\t}\n\tint diviser_count(int x) const\
    \ {\n\t\tassert(1 <= x);\n\t\tint res = 1;\n\t\tfor (auto [elem, cnt] : factor(x))\
    \ {\n\t\t\tres *= cnt + 1;\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "// description : \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9 O(N\
    \ log log N)\u3001\u7D20\u56E0\u6570\u5206\u89E3 O(\u7D20\u56E0\u6570\u306E\u500B\
    \u6570)\nstruct Sieve {\n\tint n;\n\tvector<int> f, primes;\n\tSieve(int _n) :\
    \ n(_n), f(_n + 1) {\n\t\tassert(1 <= n);\n\t\tf[0] = f[1] = -1;\n\t\tfor (long\
    \ long i = 2; i <= n; ++i)\n\t\t\tif (!f[i]) {\n\t\t\t\tprimes.push_back(i);\n\
    \t\t\t\tf[i] = i;\n\t\t\t\tfor (long long j = i * i; j <= n; j += i)\n\t\t\t\t\
    \tif (!f[j]) f[j] = i;\n\t\t\t}\n\t}\n\tbool is_prime(int x) const {\n\t\treturn\
    \ f[x] == x;\n\t}\n\tvector<pair<int, int>> factor(int x) const {\n\t\tassert(1\
    \ <= x);\n\t\tvector<pair<int, int>> res;\n\t\twhile (x != 1) {\n\t\t\tif (res.empty()\
    \ || res.back().first != f[x]) {\n\t\t\t\tres.emplace_back(f[x], 1);\n\t\t\t}\
    \ else {\n\t\t\t\tres.back().second++;\n\t\t\t}\n\t\t\tx /= f[x];\n\t\t}\n\t\t\
    return res;\n\t}\n\tmap<int, int> factor_map(int x) const {\n\t\tassert(1 <= x);\n\
    \t\tmap<int, int> res;\n\t\twhile (x != 1) {\n\t\t\tres[f[x]]++;\n\t\t\tx /= f[x];\n\
    \t\t}\n\t\treturn res;\n\t}\n\tvector<int> factor_vec(int x) const {\n\t\tassert(1\
    \ <= x);\n\t\tvector<int> res;\n\t\twhile (x != 1) {\n\t\t\tres.push_back(f[x]);\n\
    \t\t\tx /= f[x];\n\t\t}\n\t\treturn res;\n\t}\n\tint diviser_count(int x) const\
    \ {\n\t\tassert(1 <= x);\n\t\tint res = 1;\n\t\tfor (auto [elem, cnt] : factor(x))\
    \ {\n\t\t\tres *= cnt + 1;\n\t\t}\n\t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/Sieve.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Sieve.cpp
layout: document
redirect_from:
- /library/Math/Sieve.cpp
- /library/Math/Sieve.cpp.html
title: Math/Sieve.cpp
---
