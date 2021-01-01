---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/CulSum2D.cpp
    title: Utility/CulSum2D.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/0560
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/0560
  bundledCode: "#line 1 \"test/CulSum2D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\
    \n#line 2 \"Utility/CulSum2D.cpp\"\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n\ntemplate <class T> class CulSum2D {\npublic:\n\tusing\
    \ value_type = T;\n\tusing data_type = vector<vector<value_type>>;\n\nprivate:\n\
    \tsize_t h, w;\n\tvector<vector<T>> data;\n\npublic:\n\tCulSum2D() = default;\n\
    \tCulSum2D(const data_type& a)\n\t    : h(a.size()), w(a.front().size()), data(h\
    \ + 1, vector<value_type>(w + 1)) {\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\
    \tfor (size_t j = 0; j < w; ++j) {\n\t\t\t\tdata[i + 1][j + 1] = data[i][j + 1]\
    \ + data[i + 1][j] - data[i][j] + a[i][j];\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class\
    \ U, class F, enable_if_t<is_integral_v<U>, nullptr_t> = nullptr>\n\tCulSum2D(const\
    \ U& _h, const U& _w, F f)\n\t    : h(_h), w(_w), data(h + 1, vector<value_type>(w\
    \ + 1)) {\n\t\tfor (size_t i = 0; i < h; ++i) {\n\t\t\tfor (size_t j = 0; j <\
    \ w; ++j) {\n\t\t\t\tdata[i + 1][j + 1] = data[i][j + 1] + data[i + 1][j] - data[i][j]\
    \ + f(i, j);\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class U, class F, enable_if_t<!is_integral_v<U>,\
    \ nullptr_t> = nullptr>\n\tCulSum2D(const U& a, F f)\n\t    : CulSum2D(a.size(),\
    \ a.front().size(),\n\t               [a, f](size_t i, size_t j) -> value_type\
    \ { return f(a[i][j]); }) {}\n\t// [y1, y2) * [x1, x2)\n\tvalue_type operator()(size_t\
    \ y1, size_t y2, size_t x1, size_t x2) const {\n\t\ty1 = min(y1, h);\n\t\ty2 =\
    \ min(y2, h);\n\t\tx1 = min(x1, w);\n\t\tx2 = min(x2, w);\n\t\treturn (x1 > x2\
    \ || y1 > y2)\n\t\t    ? 0\n\t\t    : data[y2][x2] - data[y1][x2] - data[y2][x1]\
    \ + data[y1][x1];\n\t}\n\t// [0, y) * [0, x)\n\tvalue_type operator()(size_t y,\
    \ size_t x) const {\n\t\ty = min(y, h);\n\t\tx = min(x, w);\n\t\treturn data[y][x];\n\
    \t}\n\tconst data_type& get_data() const {\n\t\treturn data;\n\t}\n};\n#line 3\
    \ \"test/CulSum2D.test.cpp\"\n#include <iostream>\n#line 5 \"test/CulSum2D.test.cpp\"\
    \n#include <string>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\n\tint h, w, n;\n\tcin >> h >> w >> n;\n\
    \tvector<string> s(h);\n\tfor (auto& i : s) cin >> i;\n\n\tCulSum2D<int> cnt_J(s,\
    \ [](char c) { return c == 'J'; });\n\tCulSum2D<int> cnt_O(s, [](char c) { return\
    \ c == 'O'; });\n\tCulSum2D<int> cnt_I(s, [](char c) { return c == 'I'; });\n\n\
    \twhile (n--) {\n\t\tint y1, x1, y2, x2;\n\t\tcin >> y1 >> x1 >> y2 >> x2;\n\t\
    \ty1--;\n\t\tx1--;\n\t\tcout << cnt_J(y1, y2, x1, x2) << ' ' << cnt_O(y1, y2,\
    \ x1, x2) << ' '\n\t\t     << cnt_I(y1, y2, x1, x2) << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\n#include\
    \ \"./../Utility/CulSum2D.cpp\"\n#include <iostream>\n#include <vector>\n#include\
    \ <string>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint h, w, n;\n\tcin >> h >> w >> n;\n\tvector<string> s(h);\n\tfor (auto&\
    \ i : s) cin >> i;\n\n\tCulSum2D<int> cnt_J(s, [](char c) { return c == 'J'; });\n\
    \tCulSum2D<int> cnt_O(s, [](char c) { return c == 'O'; });\n\tCulSum2D<int> cnt_I(s,\
    \ [](char c) { return c == 'I'; });\n\n\twhile (n--) {\n\t\tint y1, x1, y2, x2;\n\
    \t\tcin >> y1 >> x1 >> y2 >> x2;\n\t\ty1--;\n\t\tx1--;\n\t\tcout << cnt_J(y1,\
    \ y2, x1, x2) << ' ' << cnt_O(y1, y2, x1, x2) << ' '\n\t\t     << cnt_I(y1, y2,\
    \ x1, x2) << '\\n';\n\t}\n}"
  dependsOn:
  - Utility/CulSum2D.cpp
  isVerificationFile: true
  path: test/CulSum2D.test.cpp
  requiredBy: []
  timestamp: '2021-01-01 17:28:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/CulSum2D.test.cpp
layout: document
redirect_from:
- /verify/test/CulSum2D.test.cpp
- /verify/test/CulSum2D.test.cpp.html
title: test/CulSum2D.test.cpp
---
