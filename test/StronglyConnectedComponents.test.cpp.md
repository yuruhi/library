---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/StronglyConnectedComponents.cpp
    title: Graph/StronglyConnectedComponents.cpp
  - icon: ':x:'
    path: Graph/TopologicalSort.cpp
    title: Graph/TopologicalSort.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/StronglyConnectedComponents.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n#line 2 \"Graph/StronglyConnectedComponents.cpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <cassert>\nusing namespace\
    \ std;\n\nclass StronglyConnectedComponents {\n\tint n;\n\tvector<vector<int>>\
    \ graph, rgraph;\n\tvector<bool> used;\n\tvector<int> cmp, vs;\n\tint k;\n\tbool\
    \ builded = false;\n\tvoid dfs(int v) {\n\t\tused[v] = true;\n\t\tfor (auto e\
    \ : graph[v]) {\n\t\t\tif (!used[e]) dfs(e);\n\t\t}\n\t\tvs.push_back(v);\n\t\
    }\n\tvoid rdfs(int v, int k) {\n\t\tused[v] = true;\n\t\tcmp[v] = k;\n\t\tfor\
    \ (auto e : rgraph[v]) {\n\t\t\tif (!used[e]) rdfs(e, k);\n\t\t}\n\t}\n\npublic:\n\
    \tStronglyConnectedComponents(int _n) : n(_n), graph(n), rgraph(n) {}\n\tStronglyConnectedComponents(const\
    \ vector<vector<int>>& _graph)\n\t    : n(_graph.size()), graph(_graph), rgraph(_graph)\
    \ {\n\t\tfor (int v = 0; v < n; ++v) {\n\t\t\tfor (int u : graph[v]) {\n\t\t\t\
    \trgraph[u].push_back(v);\n\t\t\t}\n\t\t}\n\t}\n\tvoid add_edge(int s, int t)\
    \ {\n\t\tbuilded = false;\n\t\tgraph[s].push_back(t);\n\t\trgraph[t].push_back(s);\n\
    \t}\n\tint build() {\n\t\tvs.clear();\n\t\tused.assign(n, false);\n\t\tcmp.assign(n,\
    \ 0);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (!used[i]) dfs(i);\n\t\t}\n\
    \t\tk = 0;\n\t\tfill(used.begin(), used.end(), false);\n\t\tfor (int i = vs.size()\
    \ - 1; i >= 0; --i) {\n\t\t\tif (!used[vs[i]]) rdfs(vs[i], k++);\n\t\t}\n\t\t\
    builded = true;\n\t\treturn k;\n\t}\n\tint operator[](int i) const {\n\t\tassert(builded);\n\
    \t\treturn cmp[i];\n\t}\n\tconst vector<int>& get_cmp() const {\n\t\tassert(builded);\n\
    \t\treturn cmp;\n\t}\n\tconst vector<vector<int>>& get_graph() const {\n\t\tassert(builded);\n\
    \t\treturn graph;\n\t}\n\tint count_strongly_components() const {\n\t\tassert(builded);\n\
    \t\treturn k;\n\t}\n\tvector<vector<int>> groups() const {\n\t\tassert(builded);\n\
    \t\tvector<vector<int>> res(k);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[cmp[i]].push_back(i);\n\
    \t\t}\n\t\treturn res;\n\t}\n\tvector<vector<int>> make_DAG() const {\n\t\tassert(builded);\n\
    \t\tvector<vector<int>> res(k);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tfor\
    \ (auto e : graph[i]) {\n\t\t\t\tif (cmp[i] != cmp[e]) {\n\t\t\t\t\tres[cmp[i]].push_back(cmp[e]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor (auto& v : res) {\n\t\t\tsort(v.begin(), v.end());\n\
    \t\t\tv.erase(unique(v.begin(), v.end()), v.end());\n\t\t}\n\t\treturn res;\n\t\
    }\n};\n#line 4 \"Graph/TopologicalSort.cpp\"\nusing namespace std;\n\nvector<int>\
    \ TopologicalSort(const vector<vector<int>>& graph) {\n\tsize_t n = graph.size();\n\
    \tvector<bool> visited(n);\n\tvector<int> res;\n\tauto dfs = [&](auto self, size_t\
    \ v) {\n\t\tif (visited[v]) return;\n\t\tvisited[v] = true;\n\t\tfor (size_t i\
    \ : graph[v]) dfs(i);\n\t\tres.push_back(v);\n\t};\n\tfor (size_t i = 0; i < n;\
    \ i++) dfs(i);\n\treverse(res.begin(), res.end());\n\treturn res;\n}\n#line 4\
    \ \"test/StronglyConnectedComponents.test.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tStronglyConnectedComponents scc(n);\n\tfor (int\
    \ i = 0; i < m; ++i) {\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tscc.add_edge(a,\
    \ b);\n\t}\n\tscc.build();\n\tcout << scc.count_strongly_components() << '\\n';\n\
    \tauto ans = scc.groups();\n\tfor (int i : TopologicalSort(scc.make_DAG())) {\n\
    \t\tcout << ans[i].size();\n\t\tfor (size_t j = 0; j < ans[i].size(); ++j) {\n\
    \t\t\tcout << ' ' << ans[i][j];\n\t\t}\n\t\tcout << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"./../Graph/StronglyConnectedComponents.cpp\"\
    \n#include \"./../Graph/TopologicalSort.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tStronglyConnectedComponents scc(n);\n\tfor (int\
    \ i = 0; i < m; ++i) {\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tscc.add_edge(a,\
    \ b);\n\t}\n\tscc.build();\n\tcout << scc.count_strongly_components() << '\\n';\n\
    \tauto ans = scc.groups();\n\tfor (int i : TopologicalSort(scc.make_DAG())) {\n\
    \t\tcout << ans[i].size();\n\t\tfor (size_t j = 0; j < ans[i].size(); ++j) {\n\
    \t\t\tcout << ' ' << ans[i][j];\n\t\t}\n\t\tcout << '\\n';\n\t}\n}"
  dependsOn:
  - Graph/StronglyConnectedComponents.cpp
  - Graph/TopologicalSort.cpp
  isVerificationFile: true
  path: test/StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2020-11-22 20:04:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/test/StronglyConnectedComponents.test.cpp
- /verify/test/StronglyConnectedComponents.test.cpp.html
title: test/StronglyConnectedComponents.test.cpp
---
