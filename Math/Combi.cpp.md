---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Combi.cpp\"\n// description : \u524D\u51E6\u7406 O(N)\
    \ \u30AF\u30A8\u30EA\u51E6\u7406 O(1)\ntemplate <int MOD, size_t size> class Combi\
    \ {\n\tusing T = modint<MOD>;\n\tarray<T, size + 1> fac, finv, inv;\n\npublic:\n\
    \tconstexpr Combi() {\n\t\tfac[0] = fac[1] = 1;\n\t\tfinv[0] = finv[1] = 1;\n\t\
    \tinv[1] = 1;\n\t\tfor (size_t i = 2; i <= size; ++i) {\n\t\t\tfac[i] = fac[i\
    \ - 1] * i;\n\t\t\tinv[i] = -inv[MOD % i] * (MOD / i);\n\t\t\tfinv[i] = finv[i\
    \ - 1] * inv[i];\n\t\t}\n\t}\n\tconstexpr T P(int n, int r) const {\n\t\treturn\
    \ (n < r || n < 0 || r < 0) ? 0 : fac[n] * finv[n - r];\n\t}\n\tconstexpr T C(int\
    \ n, int r) const {\n\t\treturn (n < r || n < 0 || r < 0) ? 0 : fac[n] * finv[r]\
    \ * finv[n - r];\n\t}\n\tconstexpr T H(int n, int r) const {\n\t\treturn (n <\
    \ 0 || r < 0) ? 0 : r == 0 ? 1 : C(n + r - 1, r);\n\t}\n\tconstexpr T fact(int\
    \ n) const {\n\t\treturn fac[n];\n\t}\n};\n"
  code: "// description : \u524D\u51E6\u7406 O(N) \u30AF\u30A8\u30EA\u51E6\u7406 O(1)\n\
    template <int MOD, size_t size> class Combi {\n\tusing T = modint<MOD>;\n\tarray<T,\
    \ size + 1> fac, finv, inv;\n\npublic:\n\tconstexpr Combi() {\n\t\tfac[0] = fac[1]\
    \ = 1;\n\t\tfinv[0] = finv[1] = 1;\n\t\tinv[1] = 1;\n\t\tfor (size_t i = 2; i\
    \ <= size; ++i) {\n\t\t\tfac[i] = fac[i - 1] * i;\n\t\t\tinv[i] = -inv[MOD % i]\
    \ * (MOD / i);\n\t\t\tfinv[i] = finv[i - 1] * inv[i];\n\t\t}\n\t}\n\tconstexpr\
    \ T P(int n, int r) const {\n\t\treturn (n < r || n < 0 || r < 0) ? 0 : fac[n]\
    \ * finv[n - r];\n\t}\n\tconstexpr T C(int n, int r) const {\n\t\treturn (n <\
    \ r || n < 0 || r < 0) ? 0 : fac[n] * finv[r] * finv[n - r];\n\t}\n\tconstexpr\
    \ T H(int n, int r) const {\n\t\treturn (n < 0 || r < 0) ? 0 : r == 0 ? 1 : C(n\
    \ + r - 1, r);\n\t}\n\tconstexpr T fact(int n) const {\n\t\treturn fac[n];\n\t\
    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combi.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combi.cpp
layout: document
redirect_from:
- /library/Math/Combi.cpp
- /library/Math/Combi.cpp.html
title: Math/Combi.cpp
---
