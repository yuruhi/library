---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Imos.cpp
    title: DataStructure/Imos.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2013
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2013
  bundledCode: "#line 1 \"test/Imos.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2013\"\
    \n#line 2 \"DataStructure/Imos.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <algorithm>\n#include <cassert>\n\ntemplate <class T> class Imos {\n\
    public:\n\tusing value_type = T;\n\nprivate:\n\tint n;\n\tstd::vector<value_type>\
    \ table;\n\tbool builded = false;\n\npublic:\n\tImos() = default;\n\tImos(int\
    \ _n) : n(_n), table(_n + 1) {}\n\tvoid add(int l, int r, value_type v = 1) {\n\
    \t\tassert(!builded);\n\t\tl = std::clamp(l, 0, n);\n\t\tr = std::clamp(r, 0,\
    \ n);\n\t\tif (l < r) {\n\t\t\ttable[l] += v;\n\t\t\ttable[r] -= v;\n\t\t}\n\t\
    }\n\tvoid add(const std::pair<int, int>& section, value_type v = 1) {\n\t\tadd(section.first,\
    \ section.second, v);\n\t}\n\tvoid add_closed(int l, int r, value_type v = 1)\
    \ {\n\t\tadd(l, r + 1, v);\n\t}\n\tvoid add_closed(const std::pair<int, int>&\
    \ section, value_type v = 1) {\n\t\tadd_closed(section.first, section.second,\
    \ v);\n\t}\n\tvoid build() {\n\t\tbuilded = true;\n\t\tfor (int i = 1; i < n;\
    \ ++i) {\n\t\t\ttable[i] += table[i - 1];\n\t\t}\n\t}\n\tvalue_type operator[](int\
    \ i) const {\n\t\tassert(builded);\n\t\treturn table[i];\n\t}\n\tconst std::vector<value_type>&\
    \ operator*() const {\n\t\tassert(builded);\n\t\treturn table;\n\t}\n\tstd::vector<value_type>\
    \ to_a() const {\n\t\treturn std::vector(table.begin(), table.begin() + n);\n\t\
    }\n};\n#line 3 \"test/Imos.test.cpp\"\n#include <iostream>\n#line 5 \"test/Imos.test.cpp\"\
    \nusing namespace std;\n\nint input_time() {\n\tint h, m, s;\n\tchar c;\n\tcin\
    \ >> h >> c >> m >> c >> s;\n\treturn h * 3600 + m * 60 + s;\n}\n\nint main()\
    \ {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\n\twhile (true)\
    \ {\n\t\tint n;\n\t\tcin >> n;\n\t\tif (n == 0) break;\n\t\tImos<int> imos(24\
    \ * 60 * 60);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tint s = input_time(),\
    \ t = input_time();\n\t\t\timos.add(s, t);\n\t\t}\n\t\timos.build();\n\t\tauto\
    \ a = imos.to_a();\n\t\tcout << *max_element(a.begin(), a.end()) << '\\n';\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2013\"\n#include\
    \ \"./../DataStructure/Imos.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    using namespace std;\n\nint input_time() {\n\tint h, m, s;\n\tchar c;\n\tcin >>\
    \ h >> c >> m >> c >> s;\n\treturn h * 3600 + m * 60 + s;\n}\n\nint main() {\n\
    \tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\n\twhile (true) {\n\
    \t\tint n;\n\t\tcin >> n;\n\t\tif (n == 0) break;\n\t\tImos<int> imos(24 * 60\
    \ * 60);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tint s = input_time(), t = input_time();\n\
    \t\t\timos.add(s, t);\n\t\t}\n\t\timos.build();\n\t\tauto a = imos.to_a();\n\t\
    \tcout << *max_element(a.begin(), a.end()) << '\\n';\n\t}\n}"
  dependsOn:
  - DataStructure/Imos.cpp
  isVerificationFile: true
  path: test/Imos.test.cpp
  requiredBy: []
  timestamp: '2021-03-05 15:06:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Imos.test.cpp
layout: document
redirect_from:
- /verify/test/Imos.test.cpp
- /verify/test/Imos.test.cpp.html
title: test/Imos.test.cpp
---
