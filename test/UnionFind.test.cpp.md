---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <iostream>\n#line 2 \"DataStructure/UnionFind.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <algorithm>\n\nclass UnionFind {\n\tstd::size_t n;\n\
    \tstd::vector<int> data_m;\n\tint count_components_m;\n\npublic:\n\tUnionFind(int\
    \ _n = 0) {\n\t\tinit(_n);\n\t}\n\tvoid init(int _n) {\n\t\tn = _n;\n\t\tdata_m.assign(n,\
    \ -1);\n\t\tcount_components_m = n;\n\t}\n\tint root(int x) {\n\t\treturn data_m[x]\
    \ < 0 ? x : data_m[x] = root(data_m[x]);\n\t}\n\tbool same(int x, int y) {\n\t\
    \treturn root(x) == root(y);\n\t}\n\tbool unite(int x, int y) {\n\t\tx = root(x);\n\
    \t\ty = root(y);\n\t\tif (x == y) {\n\t\t\treturn false;\n\t\t}\n\t\tif (data_m[x]\
    \ > data_m[y]) {\n\t\t\tstd::swap(x, y);\n\t\t}\n\t\tdata_m[x] += data_m[y];\n\
    \t\tdata_m[y] = x;\n\t\tcount_components_m--;\n\t\treturn true;\n\t}\n\tint size(int\
    \ x) {\n\t\treturn -data_m[root(x)];\n\t}\n\tint count_components() const {\n\t\
    \treturn count_components_m;\n\t}\n\tstd::vector<int> roots() {\n\t\tstd::vector<int>\
    \ result;\n\t\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\tif (root(i) == static_cast<int>(i))\
    \ result.push_back(i);\n\t\t}\n\t\treturn result;\n\t}\n\tstd::vector<std::vector<int>>\
    \ groups() {\n\t\tstd::vector<int> root_buf(n), group_size(n);\n\t\tfor (std::size_t\
    \ i = 0; i < n; i++) {\n\t\t\troot_buf[i] = root(i);\n\t\t\tgroup_size[root_buf[i]]++;\n\
    \t\t}\n\t\tstd::vector<std::vector<int>> result(n);\n\t\tfor (std::size_t i =\
    \ 0; i < n; i++) {\n\t\t\tresult[i].reserve(group_size[i]);\n\t\t}\n\t\tfor (std::size_t\
    \ i = 0; i < n; i++) {\n\t\t\tresult[root_buf[i]].push_back(i);\n\t\t}\n\t\tresult.erase(std::remove_if(result.begin(),\
    \ result.end(),\n\t\t                            [&](const std::vector<int>& v)\
    \ { return v.empty(); }),\n\t\t             result.end());\n\t\treturn result;\n\
    \t}\n};\n#line 4 \"test/UnionFind.test.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n\tint n, q;\n\tcin >> n >> q;\n\tUnionFind uf(n);\n\twhile (q--) {\n\t\t\
    int t, u, v;\n\t\tcin >> t >> u >> v;\n\t\tif (t == 0) {\n\t\t\tuf.unite(u, v);\n\
    \t\t} else {\n\t\t\tcout << uf.same(u, v) << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <iostream>\n\
    #include \"./../DataStructure/UnionFind.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n\tint n, q;\n\tcin >> n >> q;\n\tUnionFind uf(n);\n\twhile (q--) {\n\t\t\
    int t, u, v;\n\t\tcin >> t >> u >> v;\n\t\tif (t == 0) {\n\t\t\tuf.unite(u, v);\n\
    \t\t} else {\n\t\t\tcout << uf.same(u, v) << endl;\n\t\t}\n\t}\n}"
  dependsOn:
  - DataStructure/UnionFind.cpp
  isVerificationFile: true
  path: test/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-02-24 22:02:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/UnionFind.test.cpp
- /verify/test/UnionFind.test.cpp.html
title: test/UnionFind.test.cpp
---
