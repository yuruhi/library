---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/Graph/EulerTourForEdge.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_D\"\
    \n#include \"library/Graph/EulerTourForEdge.cpp\"\n#include \"library/DataStructure/BinaryIndexedTree.cpp\"\
    \n#include <iostream>\n#include <vector>\nusing namespace std;\n\nint main() {\n\
    \tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint n;\n\tcin >> n;\n\
    \tvector<vector<int>> g(n);\n\tfor (vector<int>& v : g) {\n\t\tint k;\n\t\tcin\
    \ >> k;\n\t\tv.resize(k);\n\t\tfor (int& j : v) {\n\t\t\tcin >> j;\n\t\t}\n\t\
    }\n\n\tEulerTourForEdge euler(g);\n\teuler.build();\n\n\tBinaryIndexedTree<long\
    \ long> bit(euler.size());\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint com;\n\
    \t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint v;\n\t\t\tlong long w;\n\t\t\t\
    cin >> v >> w;\n\t\t\tbit.add(euler.l(v), +w);\n\t\t\tbit.add(euler.r(v), -w);\n\
    \t\t} else if (com == 1) {\n\t\t\tint v;\n\t\t\tcin >> v;\n\t\t\tcout << bit(euler.l(v))\
    \ << endl;\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/EulerTourForEdge.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/EulerTourForEdge.test.cpp
layout: document
redirect_from:
- /verify/test/EulerTourForEdge.test.cpp
- /verify/test/EulerTourForEdge.test.cpp.html
title: test/EulerTourForEdge.test.cpp
---
