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
    using namespace std;\n\ntuple<int, vector<int>, vector<vector<int>>> ConnectedComponent(\n\
    \    const vector<vector<int>>& graph) {\n\tint n = graph.size(), count_components\
    \ = 0;\n\tvector<int> id(n, -1);\n\tvector<vector<int>> groups(n);\n\tauto dfs\
    \ = [&](auto&& f, int ID, int v) -> void {\n\t\tid[v] = ID;\n\t\tgroups[ID].push_back(v);\n\
    \t\tfor (int u : graph[v]) {\n\t\t\tif (id[u] == -1) f(f, ID, u);\n\t\t}\n\t};\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tif (id[i] == -1) dfs(dfs, count_components++,\
    \ i);\n\t}\n\tgroups.resize(count_components);\n\treturn {count_components, id,\
    \ groups};\n}\n#line 3 \"test/ConnectedComponent.test.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\tint n, m;\n\tcin >> n >> m;\n\tvector<vector<int>>\
    \ g(n);\n\tfor (int i = 0; i < m; ++i) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\
    \tg[u].push_back(v);\n\t\tg[v].push_back(u);\n\t}\n\n\tauto [k, id, ind] = ConnectedComponent(g);\n\
    \tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\tint s, t;\n\t\tcin >> s >> t;\n\t\t\
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
  timestamp: '2020-11-22 20:04:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ConnectedComponent.test.cpp
layout: document
redirect_from:
- /verify/test/ConnectedComponent.test.cpp
- /verify/test/ConnectedComponent.test.cpp.html
title: test/ConnectedComponent.test.cpp
---
