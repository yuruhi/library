---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/WeightedUnionFind.cpp
    title: DataStructure/WeightedUnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
  bundledCode: "#line 1 \"test/WeightedUnionFind.test..cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B\"\
    \n#line 2 \"DataStructure/WeightedUnionFind.cpp\"\n#include <vector>\n#include\
    \ <utility>\nusing namespace std;\n\ntemplate <class T> class WeightedUnionFind\
    \ {\n\tvector<int> par, rank;\n\tvector<T> weight_;\n\npublic:\n\tWeightedUnionFind(int\
    \ n) : par(n), rank(n, 0), weight_(n, 0) {\n\t\tfor (int i = 0; i < n; ++i)\n\t\
    \t\tpar[i] = i;\n\t}\n\tint root(int x) {\n\t\tif (par[x] == x) return x;\n\t\t\
    int r = root(par[x]);\n\t\tweight_[x] += weight_[par[x]];\n\t\treturn par[x] =\
    \ r;\n\t}\n\tT weight(int x) {\n\t\troot(x);\n\t\treturn weight_[x];\n\t}\n\t\
    bool same(int x, int y) {\n\t\treturn root(x) == root(y);\n\t}\n\tbool merge(int\
    \ x, int y, T w) {\n\t\tw += weight(x);\n\t\tw -= weight(y);\n\t\tx = root(x);\n\
    \t\ty = root(y);\n\t\tif (x == y) return false;\n\t\tif (rank[x] < rank[y]) {\n\
    \t\t\tswap(x, y);\n\t\t\tw = -w;\n\t\t}\n\t\tif (rank[x] == rank[y]) rank[x]++;\n\
    \t\tpar[y] = x;\n\t\tweight_[y] = w;\n\t\treturn true;\n\t}\n\tT diff(int x, int\
    \ y) {\n\t\treturn weight(y) - weight(x);\n\t}\n};\n#line 3 \"test/WeightedUnionFind.test..cpp\"\
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
  timestamp: '2020-10-04 16:56:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/WeightedUnionFind.test..cpp
layout: document
redirect_from:
- /verify/test/WeightedUnionFind.test..cpp
- /verify/test/WeightedUnionFind.test..cpp.html
title: test/WeightedUnionFind.test..cpp
---
