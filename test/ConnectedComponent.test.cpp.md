---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/ConnectedComponent.cpp
    title: Graph/ConnectedComponent.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_11_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_11_D
  bundledCode: "#line 1 \"test/ConnectedComponent.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_11_D\"\
    \n#line 2 \"Graph/ConnectedComponent.cpp\"\n#include <vector>\n#include <tuple>\n\
    using namespace std;\n\ntuple<int, vector<int>, vector<vector<int>>> ConnectedComponent(const\
    \ vector<vector<int>>& g) {\n\tint V = g.size(), N = 0;\n\tvector<int> id(V, -1);\n\
    \tvector<vector<int>> ind(V);\n\tauto dfs = [&](auto&& f, int ID, int v) -> void\
    \ {\n\t\tid[v] = ID;\n\t\tind[ID].push_back(v);\n\t\tfor (auto e : g[v])\n\t\t\
    \tif (id[e] == -1) f(f, ID, e);\n\t};\n\tfor (int i = 0; i < V; ++i)\n\t\tif (id[i]\
    \ == -1) dfs(dfs, N++, i);\n\tind.resize(N);\n\treturn make_tuple(N, id, ind);\n\
    }\n#line 3 \"test/ConnectedComponent.test.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tint n, m;\n\tcin >> n >> m;\n\tvector<vector<int>> g(n);\n\
    \tfor (int i = 0; i < m; ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tg[u].push_back(v);\n\
    \t\tg[v].push_back(u);\n\t}\n\n\tauto [k, id, ind] = ConnectedComponent(g);\n\t\
    int q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint s, t;\n\t\tcin >> s >> t;\n\t\t\
    cout << (id[s] == id[t] ? \"yes\" : \"no\") << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_11_D\"\
    \n#include \"./../Graph/ConnectedComponent.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tint n, m;\n\tcin >> n >> m;\n\tvector<vector<int>> g(n);\n\
    \tfor (int i = 0; i < m; ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tg[u].push_back(v);\n\
    \t\tg[v].push_back(u);\n\t}\n\n\tauto [k, id, ind] = ConnectedComponent(g);\n\t\
    int q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint s, t;\n\t\tcin >> s >> t;\n\t\t\
    cout << (id[s] == id[t] ? \"yes\" : \"no\") << '\\n';\n\t}\n}"
  dependsOn:
  - Graph/ConnectedComponent.cpp
  isVerificationFile: true
  path: test/ConnectedComponent.test.cpp
  requiredBy: []
  timestamp: '2020-10-06 22:30:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ConnectedComponent.test.cpp
layout: document
redirect_from:
- /verify/test/ConnectedComponent.test.cpp
- /verify/test/ConnectedComponent.test.cpp.html
title: test/ConnectedComponent.test.cpp
---
