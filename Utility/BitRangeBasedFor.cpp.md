---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/BitRangeBasedFor.cpp\"\n// description : \u90E8\u5206\
    \u96C6\u5408, \u30B5\u30A4\u30BAk\u306E\u90E8\u5206\u96C6\u5408\u3092\u5217\u6319\
    \nclass bit_subset {\n\tstruct it {\n\t\tlong long sub, s;\n\t\tbool f = false;\n\
    \t\tit(long long x) : sub(x), s(x) {}\n\t\tlong long operator*() const {\n\t\t\
    \treturn sub;\n\t\t}\n\t\tvoid operator++() {\n\t\t\tsub = (sub - 1) & s;\n\t\t\
    \tf |= sub == s;\n\t\t}\n\t\tbool operator!=(const it& i) const {\n\t\t\treturn\
    \ !f;\n\t\t}\n\t} b, e;\n\npublic:\n\tbit_subset(long long s) : b(s), e(s) {}\n\
    \tit begin() const {\n\t\treturn b;\n\t}\n\tit end() const {\n\t\treturn e;\n\t\
    }\n};\nclass bit_comb {\n\tstruct it {\n\t\tlong long s;\n\t\tit(long long x)\
    \ : s(x) {}\n\t\tlong long operator*() const {\n\t\t\treturn s;\n\t\t}\n\t\tvoid\
    \ operator++() {\n\t\t\tlong long x = s & -s, y = s + x;\n\t\t\ts = ((s & ~y)\
    \ / x >> 1) | y;\n\t\t}\n\t\tbool operator!=(const it& i) const {\n\t\t\treturn\
    \ s < i.s;\n\t\t}\n\t} b, e;\n\npublic:\n\tbit_comb(int k, int n) : b((1LL <<\
    \ k) - 1), e(1LL << n) {}\n\tit begin() const {\n\t\treturn b;\n\t}\n\tit end()\
    \ const {\n\t\treturn e;\n\t}\n};\n"
  code: "// description : \u90E8\u5206\u96C6\u5408, \u30B5\u30A4\u30BAk\u306E\u90E8\
    \u5206\u96C6\u5408\u3092\u5217\u6319\nclass bit_subset {\n\tstruct it {\n\t\t\
    long long sub, s;\n\t\tbool f = false;\n\t\tit(long long x) : sub(x), s(x) {}\n\
    \t\tlong long operator*() const {\n\t\t\treturn sub;\n\t\t}\n\t\tvoid operator++()\
    \ {\n\t\t\tsub = (sub - 1) & s;\n\t\t\tf |= sub == s;\n\t\t}\n\t\tbool operator!=(const\
    \ it& i) const {\n\t\t\treturn !f;\n\t\t}\n\t} b, e;\n\npublic:\n\tbit_subset(long\
    \ long s) : b(s), e(s) {}\n\tit begin() const {\n\t\treturn b;\n\t}\n\tit end()\
    \ const {\n\t\treturn e;\n\t}\n};\nclass bit_comb {\n\tstruct it {\n\t\tlong long\
    \ s;\n\t\tit(long long x) : s(x) {}\n\t\tlong long operator*() const {\n\t\t\t\
    return s;\n\t\t}\n\t\tvoid operator++() {\n\t\t\tlong long x = s & -s, y = s +\
    \ x;\n\t\t\ts = ((s & ~y) / x >> 1) | y;\n\t\t}\n\t\tbool operator!=(const it&\
    \ i) const {\n\t\t\treturn s < i.s;\n\t\t}\n\t} b, e;\n\npublic:\n\tbit_comb(int\
    \ k, int n) : b((1LL << k) - 1), e(1LL << n) {}\n\tit begin() const {\n\t\treturn\
    \ b;\n\t}\n\tit end() const {\n\t\treturn e;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Utility/BitRangeBasedFor.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/BitRangeBasedFor.cpp
layout: document
redirect_from:
- /library/Utility/BitRangeBasedFor.cpp
- /library/Utility/BitRangeBasedFor.cpp.html
title: Utility/BitRangeBasedFor.cpp
---
