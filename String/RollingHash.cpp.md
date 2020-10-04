---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/RollingHash.cpp\"\n// description : \u30ED\u30FC\u30EA\
    \u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\nusing ull = unsigned long long;\ntemplate\
    \ <ull MOD> class RollingHash {\n\tint n;\n\tull base;\n\tvector<ull> pow, hash;\n\
    \npublic:\n\tRollingHash(const string& s, ull b = 10007) : n(s.size()), base(b),\
    \ pow(n + 1), hash(n + 1) {\n\t\tpow[0] = 1;\n\t\thash[0] = 0;\n\t\tfor (int i\
    \ = 0; i < n; ++i) {\n\t\t\tpow[i + 1] = pow[i] * base % MOD;\n\t\t\thash[i +\
    \ 1] = (s[i] + hash[i] * base) % MOD;\n\t\t}\n\t}\n\t// [0, r)\n\tull operator()(int\
    \ r) const {\n\t\treturn hash[r];\n\t}\n\t// [l, r)\n\tull operator()(int l, int\
    \ r) const {\n\t\treturn (operator()(r) - operator()(l) * pow[r - l] % MOD + MOD)\
    \ % MOD;\n\t}\n};\nusing RH = RollingHash<1000000007>;\n"
  code: "// description : \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n\
    using ull = unsigned long long;\ntemplate <ull MOD> class RollingHash {\n\tint\
    \ n;\n\tull base;\n\tvector<ull> pow, hash;\n\npublic:\n\tRollingHash(const string&\
    \ s, ull b = 10007) : n(s.size()), base(b), pow(n + 1), hash(n + 1) {\n\t\tpow[0]\
    \ = 1;\n\t\thash[0] = 0;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tpow[i + 1]\
    \ = pow[i] * base % MOD;\n\t\t\thash[i + 1] = (s[i] + hash[i] * base) % MOD;\n\
    \t\t}\n\t}\n\t// [0, r)\n\tull operator()(int r) const {\n\t\treturn hash[r];\n\
    \t}\n\t// [l, r)\n\tull operator()(int l, int r) const {\n\t\treturn (operator()(r)\
    \ - operator()(l) * pow[r - l] % MOD + MOD) % MOD;\n\t}\n};\nusing RH = RollingHash<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/RollingHash.cpp
layout: document
redirect_from:
- /library/String/RollingHash.cpp
- /library/String/RollingHash.cpp.html
title: String/RollingHash.cpp
---
