---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.cpp
    title: string/RollingHash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
  bundledCode: "#line 1 \"test/RollingHash.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B\"\
    \n#line 2 \"string/RollingHash.cpp\"\n#include <vector>\n#include <string>\n\n\
    class RollingHash {\npublic:\n\tusing value_type = std::uint64_t;\n\nprivate:\n\
    \tstatic constexpr value_type MASK30 = (1ul << 30) - 1;\n\tstatic constexpr value_type\
    \ MASK31 = (1ul << 31) - 1;\n\tstatic constexpr value_type MASK61 = (1ul << 61)\
    \ - 1;\n\tstatic constexpr value_type MOD = MASK61;\n\n\tstatic constexpr value_type\
    \ mul(value_type a, value_type b) {\n\t\tauto au = a >> 31, ad = a & MASK31;\n\
    \t\tauto bu = b >> 31, bd = b & MASK31;\n\t\tauto mid = ad * bu + au * bd;\n\t\
    \tauto midu = mid >> 30, midd = mid & MASK30;\n\t\treturn au * bu * 2 + midu +\
    \ (midd << 31) + ad * bd;\n\t}\n\tstatic constexpr value_type calc_mod(value_type\
    \ x) {\n\t\tauto res = (x >> 61) + (x & MASK61);\n\t\tif (res >= MOD) res -= MOD;\n\
    \t\treturn res;\n\t}\n\n\tstd::size_t n;\n\tvalue_type base;\n\tstd::vector<value_type>\
    \ pow, hash;\n\npublic:\n\tRollingHash(const std::string& s, value_type _base\
    \ = 10007)\n\t    : n(s.size()), base(_base), pow(n + 1), hash(n + 1) {\n\t\t\
    pow[0] = 1;\n\t\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tpow[i + 1] = calc_mod(mul(pow[i],\
    \ base));\n\t\t\thash[i + 1] = calc_mod(mul(hash[i], base) + s[i]);\n\t\t}\n\t\
    }\n\t// [0, right)\n\tvalue_type operator()(int right) const {\n\t\treturn hash[right];\n\
    \t}\n\t// [left, right)\n\tvalue_type operator()(int left, int right) const {\n\
    \t\treturn calc_mod(hash[right] + MOD * 4 - mul(hash[left], pow[right - left]));\n\
    \t}\n};\n#line 3 \"test/RollingHash.test.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tstring s, t;\n\tcin >> s >> t;\n\tint n = s.size(), m = t.size();\n\n\tRollingHash\
    \ rh_s(s), rh_t(t);\n\tfor (int i = 0; i <= n - m; ++i) {\n\t\tif (rh_s(i, i +\
    \ m) == rh_t(m)) {\n\t\t\tcout << i << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B\"\
    \n#include \"./../string/RollingHash.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tstring s, t;\n\tcin >> s >> t;\n\tint n = s.size(), m = t.size();\n\n\tRollingHash\
    \ rh_s(s), rh_t(t);\n\tfor (int i = 0; i <= n - m; ++i) {\n\t\tif (rh_s(i, i +\
    \ m) == rh_t(m)) {\n\t\t\tcout << i << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - string/RollingHash.cpp
  isVerificationFile: true
  path: test/RollingHash.test.cpp
  requiredBy: []
  timestamp: '2021-04-07 13:31:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/RollingHash.test.cpp
layout: document
redirect_from:
- /verify/test/RollingHash.test.cpp
- /verify/test/RollingHash.test.cpp.html
title: test/RollingHash.test.cpp
---
