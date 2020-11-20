---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/RollingHash.test.cpp
    title: test/RollingHash.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/RollingHash.cpp\"\n#include <vector>\n#include <string>\n\
    using namespace std;\n\ntemplate <uint64_t MOD> class RollingHash {\npublic:\n\
    \tusing ull = uint64_t;\n\nprivate:\n\tint n;\n\tull base;\n\tvector<ull> pow,\
    \ hash;\n\npublic:\n\tRollingHash(const string& s, ull _base = 10007)\n\t    :\
    \ n(s.size()), base(_base), pow(n + 1), hash(n + 1) {\n\t\tpow[0] = 1;\n\t\thash[0]\
    \ = 0;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tpow[i + 1] = pow[i] * base %\
    \ MOD;\n\t\t\thash[i + 1] = (s[i] + hash[i] * base) % MOD;\n\t\t}\n\t}\n\t// [0,\
    \ r)\n\tull operator()(int r) const {\n\t\treturn hash[r];\n\t}\n\t// [l, r)\n\
    \tull operator()(int l, int r) const {\n\t\treturn (hash[r] - hash[l] * pow[r\
    \ - l] % MOD + MOD) % MOD;\n\t}\n};\nusing RH = RollingHash<1000000007>;\n"
  code: "#pragma once\n#include <vector>\n#include <string>\nusing namespace std;\n\
    \ntemplate <uint64_t MOD> class RollingHash {\npublic:\n\tusing ull = uint64_t;\n\
    \nprivate:\n\tint n;\n\tull base;\n\tvector<ull> pow, hash;\n\npublic:\n\tRollingHash(const\
    \ string& s, ull _base = 10007)\n\t    : n(s.size()), base(_base), pow(n + 1),\
    \ hash(n + 1) {\n\t\tpow[0] = 1;\n\t\thash[0] = 0;\n\t\tfor (int i = 0; i < n;\
    \ ++i) {\n\t\t\tpow[i + 1] = pow[i] * base % MOD;\n\t\t\thash[i + 1] = (s[i] +\
    \ hash[i] * base) % MOD;\n\t\t}\n\t}\n\t// [0, r)\n\tull operator()(int r) const\
    \ {\n\t\treturn hash[r];\n\t}\n\t// [l, r)\n\tull operator()(int l, int r) const\
    \ {\n\t\treturn (hash[r] - hash[l] * pow[r - l] % MOD + MOD) % MOD;\n\t}\n};\n\
    using RH = RollingHash<1000000007>;\n"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/RollingHash.test.cpp
documentation_of: String/RollingHash.cpp
layout: document
redirect_from:
- /library/String/RollingHash.cpp
- /library/String/RollingHash.cpp.html
title: String/RollingHash.cpp
---
