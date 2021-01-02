---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../DataStructure/RAQRSQ.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E\"\
    \n#include \"./../Graph/HeavyLightDecomposition.cpp\"\n#include \"./../DataStructure/RAQRSQ.cpp\"\
    \n#include \"./../DataStructure/LazySegmentTree.cpp\"\n#include <iostream>\n#include\
    \ <vector>\nusing namespace std;\nusing ll = long long;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\n\tint n;\n\tcin >> n;\n\tHLD hld(n);\n\t\
    for (int v = 0; v < n; ++v) {\n\t\tint k;\n\t\tcin >> k;\n\t\twhile (k--) {\n\t\
    \t\tint u;\n\t\t\tcin >> u;\n\t\t\thld.add_edge(v, u);\n\t\t}\n\t}\n\thld.build(0);\n\
    \n\tRangeAddRangeSum<ll, ll> seg(vector<S_sum<ll>>(n, 0));\n\tint q;\n\tcin >>\
    \ q;\n\twhile (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\
    \tint v;\n\t\t\tll w;\n\t\t\tcin >> v >> w;\n\t\t\thld.each_edge(0, v, [&](int\
    \ a, int b) { seg.apply(a, b + 1, w); });\n\t\t} else if (com == 1) {\n\t\t\t\
    int u;\n\t\t\tcin >> u;\n\t\t\tll ans = 0;\n\t\t\thld.each_edge(0, u, [&](int\
    \ a, int b) { ans += seg(a, b + 1).value; });\n\t\t\tcout << ans << '\\n';\n\t\
    \t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/HLD_edge.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/HLD_edge.test.cpp
layout: document
redirect_from:
- /verify/test/HLD_edge.test.cpp
- /verify/test/HLD_edge.test.cpp.html
title: test/HLD_edge.test.cpp
---
