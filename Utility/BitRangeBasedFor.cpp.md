---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BitRangeBasedFor.test.cpp
    title: test/BitRangeBasedFor.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/BitRangeBasedFor.cpp\"\n\nclass bit_subset {\n\t\
    struct it {\n\t\tlong long sub, s;\n\t\tbool f = false;\n\t\tit(long long x) :\
    \ sub(x), s(x) {}\n\t\tlong long operator*() const {\n\t\t\treturn sub;\n\t\t\
    }\n\t\tvoid operator++() {\n\t\t\tsub = (sub - 1) & s;\n\t\t\tf |= sub == s;\n\
    \t\t}\n\t\tbool operator!=(const it& i) const {\n\t\t\treturn !f;\n\t\t}\n\t}\
    \ b, e;\n\npublic:\n\tbit_subset(long long s) : b(s), e(s) {}\n\tit begin() const\
    \ {\n\t\treturn b;\n\t}\n\tit end() const {\n\t\treturn e;\n\t}\n};\nclass bit_comb\
    \ {\n\tstruct it {\n\t\tlong long s;\n\t\tit(long long x) : s(x) {}\n\t\tlong\
    \ long operator*() const {\n\t\t\treturn s;\n\t\t}\n\t\tvoid operator++() {\n\t\
    \t\tlong long x = s & -s, y = s + x;\n\t\t\ts = ((s & ~y) / x >> 1) | y;\n\t\t\
    }\n\t\tbool operator!=(const it& i) const {\n\t\t\treturn s < i.s;\n\t\t}\n\t\
    } b, e;\n\npublic:\n\tbit_comb(int k, int n) : b((1LL << k) - 1), e(1LL << n)\
    \ {}\n\tit begin() const {\n\t\treturn b;\n\t}\n\tit end() const {\n\t\treturn\
    \ e;\n\t}\n};\n"
  code: "#pragma once\n\nclass bit_subset {\n\tstruct it {\n\t\tlong long sub, s;\n\
    \t\tbool f = false;\n\t\tit(long long x) : sub(x), s(x) {}\n\t\tlong long operator*()\
    \ const {\n\t\t\treturn sub;\n\t\t}\n\t\tvoid operator++() {\n\t\t\tsub = (sub\
    \ - 1) & s;\n\t\t\tf |= sub == s;\n\t\t}\n\t\tbool operator!=(const it& i) const\
    \ {\n\t\t\treturn !f;\n\t\t}\n\t} b, e;\n\npublic:\n\tbit_subset(long long s)\
    \ : b(s), e(s) {}\n\tit begin() const {\n\t\treturn b;\n\t}\n\tit end() const\
    \ {\n\t\treturn e;\n\t}\n};\nclass bit_comb {\n\tstruct it {\n\t\tlong long s;\n\
    \t\tit(long long x) : s(x) {}\n\t\tlong long operator*() const {\n\t\t\treturn\
    \ s;\n\t\t}\n\t\tvoid operator++() {\n\t\t\tlong long x = s & -s, y = s + x;\n\
    \t\t\ts = ((s & ~y) / x >> 1) | y;\n\t\t}\n\t\tbool operator!=(const it& i) const\
    \ {\n\t\t\treturn s < i.s;\n\t\t}\n\t} b, e;\n\npublic:\n\tbit_comb(int k, int\
    \ n) : b((1LL << k) - 1), e(1LL << n) {}\n\tit begin() const {\n\t\treturn b;\n\
    \t}\n\tit end() const {\n\t\treturn e;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/BitRangeBasedFor.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/BitRangeBasedFor.test.cpp
documentation_of: Utility/BitRangeBasedFor.cpp
layout: document
redirect_from:
- /library/Utility/BitRangeBasedFor.cpp
- /library/Utility/BitRangeBasedFor.cpp.html
title: Utility/BitRangeBasedFor.cpp
---
