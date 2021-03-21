---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/RollingHash.test.cpp
    title: test/RollingHash.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/RollingHash.cpp\"\n#include <vector>\n#include <string>\n\
    \ntemplate <std::uint64_t MOD> class RollingHash {\npublic:\n\tusing ull = std::uint64_t;\n\
    \nprivate:\n\tint n;\n\tull base;\n\tstd::vector<ull> pow, hash;\n\npublic:\n\t\
    RollingHash(const std::string& s, ull _base = 10007)\n\t    : n(s.size()), base(_base),\
    \ pow(n + 1), hash(n + 1) {\n\t\tpow[0] = 1;\n\t\thash[0] = 0;\n\t\tfor (int i\
    \ = 0; i < n; ++i) {\n\t\t\tpow[i + 1] = pow[i] * base % MOD;\n\t\t\thash[i +\
    \ 1] = (s[i] + hash[i] * base) % MOD;\n\t\t}\n\t}\n\t// [0, r)\n\tull operator()(int\
    \ r) const {\n\t\treturn hash[r];\n\t}\n\t// [l, r)\n\tull operator()(int l, int\
    \ r) const {\n\t\treturn (hash[r] - hash[l] * pow[r - l] % MOD + MOD) % MOD;\n\
    \t}\n};\nusing RH = RollingHash<1000000007>;\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n\ntemplate <std::uint64_t\
    \ MOD> class RollingHash {\npublic:\n\tusing ull = std::uint64_t;\n\nprivate:\n\
    \tint n;\n\tull base;\n\tstd::vector<ull> pow, hash;\n\npublic:\n\tRollingHash(const\
    \ std::string& s, ull _base = 10007)\n\t    : n(s.size()), base(_base), pow(n\
    \ + 1), hash(n + 1) {\n\t\tpow[0] = 1;\n\t\thash[0] = 0;\n\t\tfor (int i = 0;\
    \ i < n; ++i) {\n\t\t\tpow[i + 1] = pow[i] * base % MOD;\n\t\t\thash[i + 1] =\
    \ (s[i] + hash[i] * base) % MOD;\n\t\t}\n\t}\n\t// [0, r)\n\tull operator()(int\
    \ r) const {\n\t\treturn hash[r];\n\t}\n\t// [l, r)\n\tull operator()(int l, int\
    \ r) const {\n\t\treturn (hash[r] - hash[l] * pow[r - l] % MOD + MOD) % MOD;\n\
    \t}\n};\nusing RH = RollingHash<1000000007>;\n"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.cpp
  requiredBy: []
  timestamp: '2021-03-21 10:20:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/RollingHash.test.cpp
documentation_of: String/RollingHash.cpp
layout: document
redirect_from:
- /library/String/RollingHash.cpp
- /library/String/RollingHash.cpp.html
title: String/RollingHash.cpp
---
