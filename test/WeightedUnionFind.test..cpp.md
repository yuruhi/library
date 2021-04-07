---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/WeightedUnionFind.cpp
    title: DataStructure/WeightedUnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
  bundledCode: "#line 1 \"test/WeightedUnionFind.test..cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B\"\
    \n#line 2 \"DataStructure/WeightedUnionFind.cpp\"\n#include <vector>\n#include\
    \ <utility>\n\ntemplate <class T> class WeightedUnionFind {\npublic:\n\tusing\
    \ value_type = T;\n\nprivate:\n\tstd::vector<int> par_m, rank_m;\n\tstd::vector<value_type>\
    \ weight_m;\n\npublic:\n\tWeightedUnionFind(std::size_t n) : par_m(n), rank_m(n,\
    \ 0), weight_m(n, 0) {\n\t\tfor (std::size_t i = 0; i < n; ++i) par_m[i] = i;\n\
    \t}\n\tint root(int x) {\n\t\tif (par_m[x] == x) {\n\t\t\treturn x;\n\t\t} else\
    \ {\n\t\t\tint r = root(par_m[x]);\n\t\t\tweight_m[x] += weight_m[par_m[x]];\n\
    \t\t\treturn par_m[x] = r;\n\t\t}\n\t}\n\tvalue_type weight(int x) {\n\t\troot(x);\n\
    \t\treturn weight_m[x];\n\t}\n\tbool same(int x, int y) {\n\t\treturn root(x)\
    \ == root(y);\n\t}\n\tbool merge(int x, int y, value_type w) {\n\t\tw += weight(x);\n\
    \t\tw -= weight(y);\n\t\tx = root(x);\n\t\ty = root(y);\n\t\tif (x == y) return\
    \ false;\n\t\tif (rank_m[x] < rank_m[y]) {\n\t\t\tstd::swap(x, y);\n\t\t\tw =\
    \ -w;\n\t\t}\n\t\tif (rank_m[x] == rank_m[y]) rank_m[x]++;\n\t\tpar_m[y] = x;\n\
    \t\tweight_m[y] = w;\n\t\treturn true;\n\t}\n\tvalue_type diff(int x, int y) {\n\
    \t\treturn weight(y) - weight(x);\n\t}\n};\n#line 3 \"test/WeightedUnionFind.test..cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n, q;\n\tcin >> n >> q;\n\tWeightedUnionFind<int>\
    \ uf(n);\n\twhile (q--) {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0) {\n\
    \t\t\tint x, y, z;\n\t\t\tcin >> x >> y >> z;\n\t\t\tuf.merge(x, y, z);\n\t\t\
    } else {\n\t\t\tint x, y;\n\t\t\tcin >> x >> y;\n\t\t\tif (uf.same(x, y)) {\n\t\
    \t\t\tcout << uf.diff(x, y) << '\\n';\n\t\t\t} else {\n\t\t\t\tcout << \"?\\n\"\
    ;\n\t\t\t}\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B\"\
    \n#include \"./../DataStructure/WeightedUnionFind.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tWeightedUnionFind<int> uf(n);\n\twhile (q--)\
    \ {\n\t\tint com;\n\t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint x, y, z;\n\t\
    \t\tcin >> x >> y >> z;\n\t\t\tuf.merge(x, y, z);\n\t\t} else {\n\t\t\tint x,\
    \ y;\n\t\t\tcin >> x >> y;\n\t\t\tif (uf.same(x, y)) {\n\t\t\t\tcout << uf.diff(x,\
    \ y) << '\\n';\n\t\t\t} else {\n\t\t\t\tcout << \"?\\n\";\n\t\t\t}\n\t\t}\n\t\
    }\n}"
  dependsOn:
  - DataStructure/WeightedUnionFind.cpp
  isVerificationFile: true
  path: test/WeightedUnionFind.test..cpp
  requiredBy: []
  timestamp: '2021-04-07 13:31:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/WeightedUnionFind.test..cpp
layout: document
redirect_from:
- /verify/test/WeightedUnionFind.test..cpp
- /verify/test/WeightedUnionFind.test..cpp.html
title: test/WeightedUnionFind.test..cpp
---
