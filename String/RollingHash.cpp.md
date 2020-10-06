---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/RollingHash.test.cpp
    title: test/RollingHash.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/RollingHash.cpp\"\n#include <vector>\n#include <string>\n\
    using namespace std;\n\ntemplate <uint64_t MOD> class RollingHash {\npublic:\n\
    \tusing ull = uint64_t;\n\nprivate:\n\tint n;\n\tull base;\n\tvector<ull> pow,\
    \ hash;\n\npublic:\n\tRollingHash(const string& s, ull b = 10007) : n(s.size()),\
    \ base(b), pow(n + 1), hash(n + 1) {\n\t\tpow[0] = 1;\n\t\thash[0] = 0;\n\t\t\
    for (int i = 0; i < n; ++i) {\n\t\t\tpow[i + 1] = pow[i] * base % MOD;\n\t\t\t\
    hash[i + 1] = (s[i] + hash[i] * base) % MOD;\n\t\t}\n\t}\n\t// [0, r)\n\tull operator()(int\
    \ r) const {\n\t\treturn hash[r];\n\t}\n\t// [l, r)\n\tull operator()(int l, int\
    \ r) const {\n\t\treturn (operator()(r) - operator()(l) * pow[r - l] % MOD + MOD)\
    \ % MOD;\n\t}\n};\nusing RH = RollingHash<1000000007>;\n"
  code: "#pragma once\n#include <vector>\n#include <string>\nusing namespace std;\n\
    \ntemplate <uint64_t MOD> class RollingHash {\npublic:\n\tusing ull = uint64_t;\n\
    \nprivate:\n\tint n;\n\tull base;\n\tvector<ull> pow, hash;\n\npublic:\n\tRollingHash(const\
    \ string& s, ull b = 10007) : n(s.size()), base(b), pow(n + 1), hash(n + 1) {\n\
    \t\tpow[0] = 1;\n\t\thash[0] = 0;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tpow[i\
    \ + 1] = pow[i] * base % MOD;\n\t\t\thash[i + 1] = (s[i] + hash[i] * base) % MOD;\n\
    \t\t}\n\t}\n\t// [0, r)\n\tull operator()(int r) const {\n\t\treturn hash[r];\n\
    \t}\n\t// [l, r)\n\tull operator()(int l, int r) const {\n\t\treturn (operator()(r)\
    \ - operator()(l) * pow[r - l] % MOD + MOD) % MOD;\n\t}\n};\nusing RH = RollingHash<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.cpp
  requiredBy: []
  timestamp: '2020-10-06 22:30:41+09:00'
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
