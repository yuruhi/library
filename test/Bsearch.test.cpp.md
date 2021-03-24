---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/Bsearch.cpp
    title: Utility/Bsearch.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_6_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_6_C
  bundledCode: "#line 1 \"test/Bsearch.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_6_C\"\
    \n#line 2 \"Utility/Bsearch.cpp\"\n#include <optional>\n#include <type_traits>\n\
    #include <cassert>\n\ntemplate <class T, class F, std::enable_if_t<std::is_integral_v<T>,\
    \ std::nullptr_t> = nullptr>\nstd::optional<T> Bsearch(T left, T right, F f) {\n\
    \tif (left > right || !f(right)) {\n\t\treturn std::nullopt;\n\t} else if (f(left))\
    \ {\n\t\treturn left;\n\t}\n\twhile (right - left > 1) {\n\t\tT middle = (left\
    \ + right) / 2;\n\t\t(f(middle) ? right : left) = middle;\n\t}\n\tassert(!f(left));\n\
    \tassert(f(right));\n\treturn right;\n}\n#line 3 \"test/Bsearch.test.cpp\"\n#include\
    \ <iostream>\n#include <vector>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\n\tint n;\n\tcin >> n;\n\tvector<int> a(n);\n\
    \tfor (int& i : a) cin >> i;\n\tint q;\n\tfor (cin >> q; q--;) {\n\t\tint x;\n\
    \t\tcin >> x;\n\t\tcout << Bsearch(0, n - 1, [&](int i) { return a[i] >= x; }).value_or(n)\
    \ << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_6_C\"\
    \n#include \"./../Utility/Bsearch.cpp\"\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint n;\n\tcin >> n;\n\tvector<int> a(n);\n\tfor (int& i : a) cin >> i;\n\t\
    int q;\n\tfor (cin >> q; q--;) {\n\t\tint x;\n\t\tcin >> x;\n\t\tcout << Bsearch(0,\
    \ n - 1, [&](int i) { return a[i] >= x; }).value_or(n) << '\\n';\n\t}\n}"
  dependsOn:
  - Utility/Bsearch.cpp
  isVerificationFile: true
  path: test/Bsearch.test.cpp
  requiredBy: []
  timestamp: '2021-03-24 15:18:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Bsearch.test.cpp
layout: document
redirect_from:
- /verify/test/Bsearch.test.cpp
- /verify/test/Bsearch.test.cpp.html
title: test/Bsearch.test.cpp
---
