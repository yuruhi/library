---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/BabystepGiantstep.cpp\"\n// description : g ^ res %\
    \ mod = h\nint64_t BabystepGiantstep(uint64_t g, uint64_t h,\n               \
    \           uint64_t mod) {  // g ^ res = h (mod mod)\n\tconst uint64_t m = ceil(sqrt(mod));\n\
    \tunordered_map<uint64_t, uint64_t> table;\n\tuint64_t e = 1;\n\tfor (uint64_t\
    \ i = 0; i < m; ++i) {\n\t\ttable[e] = i;\n\t\te = e * g % mod;\n\t}\n\te = h;\n\
    \tfor (uint64_t f = Powmod(g, mod - m - 1, mod), i = 0; i < m; ++i) {\n\t\tif\
    \ (table.count(e)) {\n\t\t\treturn i * m + table[e];\n\t\t}\n\t\te = (e * f) %\
    \ mod;\n\t}\n\treturn -1;\n}\n"
  code: "// description : g ^ res % mod = h\nint64_t BabystepGiantstep(uint64_t g,\
    \ uint64_t h,\n                          uint64_t mod) {  // g ^ res = h (mod\
    \ mod)\n\tconst uint64_t m = ceil(sqrt(mod));\n\tunordered_map<uint64_t, uint64_t>\
    \ table;\n\tuint64_t e = 1;\n\tfor (uint64_t i = 0; i < m; ++i) {\n\t\ttable[e]\
    \ = i;\n\t\te = e * g % mod;\n\t}\n\te = h;\n\tfor (uint64_t f = Powmod(g, mod\
    \ - m - 1, mod), i = 0; i < m; ++i) {\n\t\tif (table.count(e)) {\n\t\t\treturn\
    \ i * m + table[e];\n\t\t}\n\t\te = (e * f) % mod;\n\t}\n\treturn -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/BabystepGiantstep.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/BabystepGiantstep.cpp
layout: document
redirect_from:
- /library/Math/BabystepGiantstep.cpp
- /library/Math/BabystepGiantstep.cpp.html
title: Math/BabystepGiantstep.cpp
---
