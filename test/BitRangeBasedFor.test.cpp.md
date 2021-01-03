---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/BitRangeBasedFor.cpp
    title: Utility/BitRangeBasedFor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_11_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_11_D
  bundledCode: "#line 1 \"test/BitRangeBasedFor.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_11_D\"\
    \n#line 2 \"Utility/BitRangeBasedFor.cpp\"\n\nclass bit_subset {\n\tstruct it\
    \ {\n\t\tlong long sub, s;\n\t\tbool f = false;\n\t\tit(long long x) : sub(x),\
    \ s(x) {}\n\t\tlong long operator*() const {\n\t\t\treturn sub;\n\t\t}\n\t\tvoid\
    \ operator++() {\n\t\t\tsub = (sub - 1) & s;\n\t\t\tf |= sub == s;\n\t\t}\n\t\t\
    bool operator!=([[maybe_unused]] const it& i) const {\n\t\t\treturn !f;\n\t\t\
    }\n\t} b, e;\n\npublic:\n\tbit_subset(long long s) : b(s), e(s) {}\n\tit begin()\
    \ const {\n\t\treturn b;\n\t}\n\tit end() const {\n\t\treturn e;\n\t}\n};\nclass\
    \ bit_comb {\n\tstruct it {\n\t\tlong long s;\n\t\tit(long long x) : s(x) {}\n\
    \t\tlong long operator*() const {\n\t\t\treturn s;\n\t\t}\n\t\tvoid operator++()\
    \ {\n\t\t\tlong long x = s & -s, y = s + x;\n\t\t\ts = ((s & ~y) / x >> 1) | y;\n\
    \t\t}\n\t\tbool operator!=(const it& i) const {\n\t\t\treturn s < i.s;\n\t\t}\n\
    \t} b, e;\n\npublic:\n\tbit_comb(int k, int n) : b((1LL << k) - 1), e(1LL << n)\
    \ {}\n\tit begin() const {\n\t\treturn b;\n\t}\n\tit end() const {\n\t\treturn\
    \ e;\n\t}\n};\n#line 3 \"test/BitRangeBasedFor.test.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, k;\n\tcin >> n >> k;\n\tfor (long long bit : bit_comb(k, n)) {\n\t\t\
    cout << bit << ':';\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (bit & (1 <<\
    \ i)) cout << ' ' << i;\n\t\t}\n\t\tcout << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_11_D\"\
    \n#include \"./../Utility/BitRangeBasedFor.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, k;\n\tcin >> n >> k;\n\tfor (long long bit : bit_comb(k, n)) {\n\t\t\
    cout << bit << ':';\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (bit & (1 <<\
    \ i)) cout << ' ' << i;\n\t\t}\n\t\tcout << '\\n';\n\t}\n}"
  dependsOn:
  - Utility/BitRangeBasedFor.cpp
  isVerificationFile: true
  path: test/BitRangeBasedFor.test.cpp
  requiredBy: []
  timestamp: '2021-01-02 22:23:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BitRangeBasedFor.test.cpp
layout: document
redirect_from:
- /verify/test/BitRangeBasedFor.test.cpp
- /verify/test/BitRangeBasedFor.test.cpp.html
title: test/BitRangeBasedFor.test.cpp
---
