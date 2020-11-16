---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/ImosLinear.cpp
    title: Utility/ImosLinear.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1008
    links:
    - https://yukicoder.me/problems/no/1008
  bundledCode: "#line 1 \"test/ImosLinear.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1008\"\
    \n#line 2 \"Utility/ImosLinear.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T> class ImosLinear\
    \ {\npublic:\n\tusing value_type = T;\n\nprivate:\n\tconst int N;\n\tvector<value_type>\
    \ X, A, B;\n\tbool builded = false;\n\npublic:\n\tImosLinear(int _n) : N(_n),\
    \ X(_n), A(_n + 1), B(_n + 1) {}\n\tvoid add(int l, int r, value_type a, value_type\
    \ b) {  // [l, r) += a + (i - l) * b\n\t\tif (l >= r) return;\n\t\tassert(!builded);\n\
    \t\tl = max(min(l, N), 0);\n\t\tr = max(min(r, N), 0);\n\t\tA[l] += a - b * l;\n\
    \t\tB[l] += b;\n\t\tA[r] -= a - b * l;\n\t\tB[r] -= b;\n\t}\n\tvoid build() {\n\
    \t\tbuilded = true;\n\t\tfor (int i = 0; i < N; ++i) {\n\t\t\tX[i] = A[i] + B[i]\
    \ * i;\n\t\t\tA[i + 1] += A[i];\n\t\t\tB[i + 1] += B[i];\n\t\t}\n\t}\n\tvalue_type\
    \ operator[](int i) const {\n\t\tassert(builded);\n\t\treturn X[i];\n\t}\n\tconst\
    \ vector<value_type>& to_a() const {\n\t\tassert(builded);\n\t\treturn X;\n\t\
    }\n};\n#line 3 \"test/ImosLinear.test.cpp\"\n#include <iostream>\n#line 5 \"test/ImosLinear.test.cpp\"\
    \n#include <utility>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tusing ll = long long;\n\n\tint n, m;\n\t\
    cin >> n >> m;\n\tvector<ll> a(n);\n\tfor (ll& i : a) {\n\t\tcin >> i;\n\t}\n\t\
    vector<pair<int, ll>> xw(m);\n\tfor (auto& [x, w] : xw) {\n\t\tcin >> x >> w;\n\
    \t\tx--;\n\t}\n\n\tauto check = [&](ll c) {\n\t\tImosLinear<ll> imos(n);\n\t\t\
    for (auto [x, w] : xw) {\n\t\t\timos.add(x, x + 1, w, 0);\n\t\t\tint left = min<ll>(x,\
    \ w / c);\n\t\t\timos.add(x - left, x, w - c * left, c);\n\t\t\tint right = min<ll>(n\
    \ - 1 - x, w / c);\n\t\t\timos.add(x + 1, x + 1 + right, w - c, -c);\n\t\t}\n\t\
    \timos.build();\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (imos[i] >= a[i])\
    \ {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t}\n\t\treturn true;\n\t};\n\n\tll sum_w\
    \ = 0, min_a = 10000000000;\n\tfor (ll i : a) {\n\t\tmin_a = min(min_a, i);\n\t\
    }\n\tfor (auto [x, w] : xw) {\n\t\tsum_w += w;\n\t}\n\n\tif (sum_w < min_a) {\n\
    \t\tcout << 0 << '\\n';\n\t} else if (!check(1000000099)) {\n\t\tcout << -1 <<\
    \ '\\n';\n\t} else {\n\t\tll ng = 0, ok = 1000000099;\n\t\twhile (ok - ng > 1)\
    \ {\n\t\t\tll mid = (ok + ng) / 2;\n\t\t\t(check(mid) ? ok : ng) = mid;\n\t\t\
    }\n\t\tcout << ok << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1008\"\n#include \"./../Utility/ImosLinear.cpp\"\
    \n#include <iostream>\n#include <vector>\n#include <utility>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tusing ll = long long;\n\n\tint n, m;\n\tcin >> n >> m;\n\tvector<ll> a(n);\n\
    \tfor (ll& i : a) {\n\t\tcin >> i;\n\t}\n\tvector<pair<int, ll>> xw(m);\n\tfor\
    \ (auto& [x, w] : xw) {\n\t\tcin >> x >> w;\n\t\tx--;\n\t}\n\n\tauto check = [&](ll\
    \ c) {\n\t\tImosLinear<ll> imos(n);\n\t\tfor (auto [x, w] : xw) {\n\t\t\timos.add(x,\
    \ x + 1, w, 0);\n\t\t\tint left = min<ll>(x, w / c);\n\t\t\timos.add(x - left,\
    \ x, w - c * left, c);\n\t\t\tint right = min<ll>(n - 1 - x, w / c);\n\t\t\timos.add(x\
    \ + 1, x + 1 + right, w - c, -c);\n\t\t}\n\t\timos.build();\n\t\tfor (int i =\
    \ 0; i < n; ++i) {\n\t\t\tif (imos[i] >= a[i]) {\n\t\t\t\treturn false;\n\t\t\t\
    }\n\t\t}\n\t\treturn true;\n\t};\n\n\tll sum_w = 0, min_a = 10000000000;\n\tfor\
    \ (ll i : a) {\n\t\tmin_a = min(min_a, i);\n\t}\n\tfor (auto [x, w] : xw) {\n\t\
    \tsum_w += w;\n\t}\n\n\tif (sum_w < min_a) {\n\t\tcout << 0 << '\\n';\n\t} else\
    \ if (!check(1000000099)) {\n\t\tcout << -1 << '\\n';\n\t} else {\n\t\tll ng =\
    \ 0, ok = 1000000099;\n\t\twhile (ok - ng > 1) {\n\t\t\tll mid = (ok + ng) / 2;\n\
    \t\t\t(check(mid) ? ok : ng) = mid;\n\t\t}\n\t\tcout << ok << '\\n';\n\t}\n}"
  dependsOn:
  - Utility/ImosLinear.cpp
  isVerificationFile: true
  path: test/ImosLinear.test.cpp
  requiredBy: []
  timestamp: '2020-11-16 21:01:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ImosLinear.test.cpp
layout: document
redirect_from:
- /verify/test/ImosLinear.test.cpp
- /verify/test/ImosLinear.test.cpp.html
title: test/ImosLinear.test.cpp
---
