---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.cpp
    title: DataStructure/BinaryIndexedTree.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/EulerTourForEdge.cpp
    title: Graph/EulerTourForEdge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_D
  bundledCode: "#line 1 \"test/EulerTourForEdge.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_D\"\
    \n#line 2 \"Graph/EulerTourForEdge.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <cassert>\n#include <functional>\nusing namespace std;\n\nclass EulerTourForEdge\
    \ {\n\tvector<vector<int>> graph;\n\tvector<int> ls, rs;\n\tint pos = 0;\n\tbool\
    \ flag = false;\n\tvoid dfs(int v, int p = -1) {\n\t\tls[v] = pos++;\n\t\tfor\
    \ (int u : graph[v])\n\t\t\tif (u != p) {\n\t\t\t\tdfs(u, v);\n\t\t\t}\n\t\trs[v]\
    \ = pos++;\n\t}\n\npublic:\n\tEulerTourForEdge(int n) : graph(n), ls(n), rs(n)\
    \ {}\n\tEulerTourForEdge(const vector<vector<int>>& _graph) : graph(_graph), ls(graph.size()),\
    \ rs(graph.size()) {}\n\tvoid add_edge(int u, int v) {\n\t\tgraph[u].push_back(v);\n\
    \t\tgraph[v].push_back(u);\n\t}\n\tvoid build(int root = 0) {\n\t\tflag = true;\n\
    \t\tpos = 0;\n\t\tdfs(root);\n\t}\n\tint size() const {\n\t\tassert(flag);\n\t\
    \treturn pos;\n\t}\n\tint l(int i) const {\n\t\tassert(flag);\n\t\treturn ls[i];\n\
    \t}\n\tint r(int i) const {\n\t\tassert(flag);\n\t\treturn rs[i];\n\t}\n\tpair<int,\
    \ int> operator()(int i) {\n\t\tassert(flag);\n\t\treturn make_pair(ls[i], rs[i]);\n\
    \t}\n\tconst vector<int>& get_ls() const {\n\t\treturn ls;\n\t}\n\tconst vector<int>&\
    \ get_rs() const {\n\t\treturn rs;\n\t}\n\tint operator[](int i) {\n\t\tassert(flag);\n\
    \t\treturn ls[i];\n\t}\n\ttemplate <class T> auto call(int v, function<T(int,\
    \ int)>&& f) {\n\t\tassert(flag);\n\t\treturn f(ls[v], rs[v]);\n\t}\n};\n#line\
    \ 4 \"DataStructure/BinaryIndexedTree.cpp\"\nusing namespace std;\n\ntemplate\
    \ <class T> class BinaryIndexedTree {\npublic:\n\tusing value_type = T;\n\nprivate:\n\
    \tint n, n2;\n\tvector<value_type> a;\n\npublic:\n\tBinaryIndexedTree(int n_)\
    \ : n(n_), n2(1), a(n_ + 1) {\n\t\twhile (n2 < n) n2 *= 2;\n\t\tn2 /= 2;\n\t}\n\
    \tvalue_type operator()(int i) const {  // [0, i]\n\t\tassert(0 < ++i);\n\t\t\
    value_type result = 0;\n\t\tfor (; i > 0; i -= i & -i) {\n\t\t\tresult += a[i];\n\
    \t\t}\n\t\treturn result;\n\t}\n\tvalue_type operator()(int i, int j) const {\
    \  // [i, j]\n\t\treturn operator()(j) - (i ? operator()(i - 1) : 0);\n\t}\n\t\
    value_type operator[](int i) const {\n\t\treturn operator()(i, i);\n\t}\n\tvoid\
    \ add(int i, value_type x) {\n\t\tassert(0 < ++i);\n\t\tfor (; i <= n; i += i\
    \ & -i) {\n\t\t\ta[i] += x;\n\t\t}\n\t}\n\tint lower_bound(value_type k) const\
    \ {\n\t\tif (k <= 0) return 0;\n\t\tint result = 0;\n\t\tfor (int i = n2; i >\
    \ 0; i /= 2) {\n\t\t\tif (result + i <= n && a[result + i] < k) {\n\t\t\t\tk -=\
    \ a[result + i];\n\t\t\t\tresult += i;\n\t\t\t}\n\t\t}\n\t\treturn result;\n\t\
    }\n\tvector<value_type> to_a() const {\n\t\tvector<value_type> result(n);\n\t\t\
    for (int i = 0; i < n; ++i) {\n\t\t\tresult[i] = operator()(i, i);\n\t\t}\n\t\t\
    return result;\n\t}\n};\n#line 4 \"test/EulerTourForEdge.test.cpp\"\n#include\
    \ <iostream>\n#line 6 \"test/EulerTourForEdge.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint\
    \ n;\n\tcin >> n;\n\tvector<vector<int>> g(n);\n\tfor (vector<int>& v : g) {\n\
    \t\tint k;\n\t\tcin >> k;\n\t\tv.resize(k);\n\t\tfor (int& j : v) {\n\t\t\tcin\
    \ >> j;\n\t\t}\n\t}\n\n\tEulerTourForEdge euler(g);\n\teuler.build();\n\n\tBinaryIndexedTree<long\
    \ long> bit(euler.size());\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint com;\n\
    \t\tcin >> com;\n\t\tif (com == 0) {\n\t\t\tint v;\n\t\t\tlong long w;\n\t\t\t\
    cin >> v >> w;\n\t\t\tbit.add(euler.l(v), +w);\n\t\t\tbit.add(euler.r(v), -w);\n\
    \t\t} else if (com == 1) {\n\t\t\tint v;\n\t\t\tcin >> v;\n\t\t\tcout << bit(euler.l(v))\
    \ << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_D\"\
    \n#include \"./../Graph/EulerTourForEdge.cpp\"\n#include \"./../DataStructure/BinaryIndexedTree.cpp\"\
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
  dependsOn:
  - Graph/EulerTourForEdge.cpp
  - DataStructure/BinaryIndexedTree.cpp
  isVerificationFile: true
  path: test/EulerTourForEdge.test.cpp
  requiredBy: []
  timestamp: '2020-11-21 14:30:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/EulerTourForEdge.test.cpp
layout: document
redirect_from:
- /verify/test/EulerTourForEdge.test.cpp
- /verify/test/EulerTourForEdge.test.cpp.html
title: test/EulerTourForEdge.test.cpp
---