---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/StronglyConnectedComponents.cpp
    title: Graph/StronglyConnectedComponents.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ vector<vector<int>>& _graph)\n\t    : n(_graph.size()), graph(_graph), rgraph(n)\
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
    \t\tvector<vector<int>> result(k);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\t\
    result[cmp[i]].push_back(i);\n\t\t}\n\t\treturn result;\n\t}\n\tvector<vector<int>>\
    \ make_DAG() const {\n\t\tassert(builded);\n\t\tvector<vector<int>> result(k);\n\
    \t\tfor (int i = 0; i < n; ++i) {\n\t\t\tfor (auto e : graph[i]) {\n\t\t\t\tif\
    \ (cmp[i] != cmp[e]) {\n\t\t\t\t\tresult[cmp[i]].push_back(cmp[e]);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\tfor (auto& v : result) {\n\t\t\tsort(v.begin(), v.end());\n\
    \t\t\tv.erase(unique(v.begin(), v.end()), v.end());\n\t\t}\n\t\treturn result;\n\
    \t}\n};\n#line 3 \"test/StronglyConnectedComponents.test.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n, m;\n\tcin >> n >> m;\n\tStronglyConnectedComponents scc(n);\n\tfor (int\
    \ i = 0; i < m; ++i) {\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tscc.add_edge(a,\
    \ b);\n\t}\n\tscc.build();\n\tcout << scc.count_strongly_components() << '\\n';\n\
    \tauto ans = scc.groups();\n\tfor (size_t i = 0; i < ans.size(); ++i) {\n\t\t\
    cout << ans[i].size();\n\t\tfor (size_t j = 0; j < ans[i].size(); ++j) {\n\t\t\
    \tcout << ' ' << ans[i][j];\n\t\t}\n\t\tcout << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"./../Graph/StronglyConnectedComponents.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n, m;\n\tcin >> n >> m;\n\tStronglyConnectedComponents\
    \ scc(n);\n\tfor (int i = 0; i < m; ++i) {\n\t\tint a, b;\n\t\tcin >> a >> b;\n\
    \t\tscc.add_edge(a, b);\n\t}\n\tscc.build();\n\tcout << scc.count_strongly_components()\
    \ << '\\n';\n\tauto ans = scc.groups();\n\tfor (size_t i = 0; i < ans.size();\
    \ ++i) {\n\t\tcout << ans[i].size();\n\t\tfor (size_t j = 0; j < ans[i].size();\
    \ ++j) {\n\t\t\tcout << ' ' << ans[i][j];\n\t\t}\n\t\tcout << '\\n';\n\t}\n}"
  dependsOn:
  - Graph/StronglyConnectedComponents.cpp
  isVerificationFile: true
  path: test/StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2020-11-24 20:31:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/test/StronglyConnectedComponents.test.cpp
- /verify/test/StronglyConnectedComponents.test.cpp.html
title: test/StronglyConnectedComponents.test.cpp
---
