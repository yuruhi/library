---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/CulSum.test.cpp
    title: test/CulSum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/CulSum.cpp\"\n#include <vector>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class T> class CulSum {\n\tsize_t n;\n\tvector<T>\
    \ s;\n\npublic:\n\tCulSum(const vector<T>& a) : n(a.size()), s(n + 1) {\n\t\t\
    for (size_t i = 0; i < n; ++i)\n\t\t\ts[i + 1] = s[i] + a[i];\n\t}\n\ttemplate\
    \ <class F> CulSum(int _n, F f) : n(_n), s(n + 1) {\n\t\tfor (size_t i = 0; i\
    \ < n; ++i)\n\t\t\ts[i + 1] = s[i] + static_cast<T>(f(i));\n\t}\n\ttemplate <class\
    \ U, class F> CulSum(const U& a, F f) : n(a.size()), s(n + 1) {\n\t\tfor (size_t\
    \ i = 0; i < n; ++i)\n\t\t\ts[i + 1] = s[i] + static_cast<T>(f(a[i]));\n\t}\n\t\
    // [l, r)\n\tT operator()(size_t l, size_t r) const {\n\t\treturn l > r ? 0 :\
    \ s[r] - s[l];\n\t}\n\t// [0, r)\n\tT operator()(size_t r) const {\n\t\tassert(r\
    \ <= n);\n\t\treturn s[r];\n\t}\n\tconst vector<T>& get_s() const {\n\t\treturn\
    \ s;\n\t}\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\nusing namespace std;\n\
    \ntemplate <class T> class CulSum {\n\tsize_t n;\n\tvector<T> s;\n\npublic:\n\t\
    CulSum(const vector<T>& a) : n(a.size()), s(n + 1) {\n\t\tfor (size_t i = 0; i\
    \ < n; ++i)\n\t\t\ts[i + 1] = s[i] + a[i];\n\t}\n\ttemplate <class F> CulSum(int\
    \ _n, F f) : n(_n), s(n + 1) {\n\t\tfor (size_t i = 0; i < n; ++i)\n\t\t\ts[i\
    \ + 1] = s[i] + static_cast<T>(f(i));\n\t}\n\ttemplate <class U, class F> CulSum(const\
    \ U& a, F f) : n(a.size()), s(n + 1) {\n\t\tfor (size_t i = 0; i < n; ++i)\n\t\
    \t\ts[i + 1] = s[i] + static_cast<T>(f(a[i]));\n\t}\n\t// [l, r)\n\tT operator()(size_t\
    \ l, size_t r) const {\n\t\treturn l > r ? 0 : s[r] - s[l];\n\t}\n\t// [0, r)\n\
    \tT operator()(size_t r) const {\n\t\tassert(r <= n);\n\t\treturn s[r];\n\t}\n\
    \tconst vector<T>& get_s() const {\n\t\treturn s;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CulSum.cpp
  requiredBy: []
  timestamp: '2020-10-04 17:42:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/CulSum.test.cpp
documentation_of: Utility/CulSum.cpp
layout: document
redirect_from:
- /library/Utility/CulSum.cpp
- /library/Utility/CulSum.cpp.html
title: Utility/CulSum.cpp
---
