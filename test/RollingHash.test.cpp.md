---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: String/RollingHash.cpp
    title: String/RollingHash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
  bundledCode: "#line 1 \"test/RollingHash.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B\"\
    \n#line 2 \"String/RollingHash.cpp\"\n#include <vector>\n#include <string>\nusing\
    \ namespace std;\n\ntemplate <uint64_t MOD> class RollingHash {\npublic:\n\tusing\
    \ ull = uint64_t;\n\nprivate:\n\tint n;\n\tull base;\n\tvector<ull> pow, hash;\n\
    \npublic:\n\tRollingHash(const string& s, ull _base = 10007)\n\t    : n(s.size()),\
    \ base(_base), pow(n + 1), hash(n + 1) {\n\t\tpow[0] = 1;\n\t\thash[0] = 0;\n\t\
    \tfor (int i = 0; i < n; ++i) {\n\t\t\tpow[i + 1] = pow[i] * base % MOD;\n\t\t\
    \thash[i + 1] = (s[i] + hash[i] * base) % MOD;\n\t\t}\n\t}\n\t// [0, r)\n\tull\
    \ operator()(int r) const {\n\t\treturn hash[r];\n\t}\n\t// [l, r)\n\tull operator()(int\
    \ l, int r) const {\n\t\treturn (hash[r] - hash[l] * pow[r - l] % MOD + MOD) %\
    \ MOD;\n\t}\n};\nusing RH = RollingHash<1000000007>;\n#line 3 \"test/RollingHash.test.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tstring s, t;\n\tcin >> s >> t;\n\tint n\
    \ = s.size(), m = t.size();\n\n\tRH rh_s(s), rh_t(t);\n\tfor (int i = 0; i <=\
    \ n - m; ++i) {\n\t\tif (rh_s(i, i + m) == rh_t(m)) {\n\t\t\tcout << i << '\\\
    n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B\"\
    \n#include \"./../String/RollingHash.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tstring s, t;\n\tcin >> s >> t;\n\tint n = s.size(), m = t.size();\n\n\tRH rh_s(s),\
    \ rh_t(t);\n\tfor (int i = 0; i <= n - m; ++i) {\n\t\tif (rh_s(i, i + m) == rh_t(m))\
    \ {\n\t\t\tcout << i << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - String/RollingHash.cpp
  isVerificationFile: true
  path: test/RollingHash.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/RollingHash.test.cpp
layout: document
redirect_from:
- /verify/test/RollingHash.test.cpp
- /verify/test/RollingHash.test.cpp.html
title: test/RollingHash.test.cpp
---
