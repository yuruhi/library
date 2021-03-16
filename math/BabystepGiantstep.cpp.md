---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/functions.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"./../template/functions.cpp\"\n#include <vector>\n\
    #include <unordered_map>\n#include <cmath>\nusing namespace std;\n\n// g ^ result\
    \ \u2261 h (mod mod)\nint64_t BabystepGiantstep(uint64_t g, uint64_t h, uint64_t\
    \ mod) {\n\tconst uint64_t m = ceil(sqrt(mod));\n\tunordered_map<uint64_t, uint64_t>\
    \ table;\n\tuint64_t e = 1;\n\tfor (uint64_t i = 0; i < m; ++i) {\n\t\ttable[e]\
    \ = i;\n\t\te = e * g % mod;\n\t}\n\te = h;\n\tfor (uint64_t f = Powmod(g, mod\
    \ - m - 1, mod), i = 0; i < m; ++i) {\n\t\tif (table.count(e)) {\n\t\t\treturn\
    \ i * m + table[e];\n\t\t}\n\t\te = (e * f) % mod;\n\t}\n\treturn -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/BabystepGiantstep.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/BabystepGiantstep.cpp
layout: document
redirect_from:
- /library/math/BabystepGiantstep.cpp
- /library/math/BabystepGiantstep.cpp.html
title: math/BabystepGiantstep.cpp
---
