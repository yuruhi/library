---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/BipartiteMatching.cpp
    title: Graph/BipartiteMatching.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/BipartiteMatching.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \n#line 2 \"Graph/BipartiteMatching.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <algorithm>\n#include <cassert>\nusing namespace std;\n\nclass BipartiteMatching\
    \ {\n\tsize_t left, right;\n\tvector<vector<int>> graph;\n\tvector<bool> used;\n\
    \tvector<int> left_match, right_match;\n\tbool dfs(int v) {\n\t\tif (used[v])\
    \ {\n\t\t\treturn false;\n\t\t}\n\t\tused[v] = true;\n\t\tfor (int u : graph[v])\
    \ {\n\t\t\tif (right_match[u] == -1 || dfs(right_match[u])) {\n\t\t\t\tleft_match[v]\
    \ = u;\n\t\t\t\tright_match[u] = v;\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\t\
    return false;\n\t}\n\npublic:\n\tBipartiteMatching(size_t _left, size_t _right)\n\
    \t    : left(_left), right(_right), graph(left), used(left), left_match(left),\
    \ right_match(right) {}\n\tBipartiteMatching(size_t _left, size_t _right, const\
    \ vector<vector<int>>& _graph)\n\t    : left(_left), right(_right), graph(_graph),\
    \ used(left), left_match(left), right_match(right) {\n\t\tassert(graph.size()\
    \ == left);\n\t}\n\tvoid add_edge(int l, int r) {\n\t\tgraph[l].push_back(r);\n\
    \t}\n\tint solve() {\n\t\tint res = 0;\n\t\tfill(left_match.begin(), left_match.end(),\
    \ -1);\n\t\tfill(right_match.begin(), right_match.end(), -1);\n\t\tfill(used.begin(),\
    \ used.end(), false);\n\t\tfor (bool update = true; update;) {\n\t\t\tupdate =\
    \ false;\n\t\t\tfor (size_t i = 0; i < left; ++i) {\n\t\t\t\tif (left_match[i]\
    \ == -1 && dfs(i)) {\n\t\t\t\t\tupdate = true;\n\t\t\t\t\t++res;\n\t\t\t\t}\n\t\
    \t\t}\n\t\t\tif (update) {\n\t\t\t\tfill(used.begin(), used.end(), false);\n\t\
    \t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tvector<pair<int, int>> edges() const {\n\
    \t\tvector<pair<int, int>> res;\n\t\tfor (size_t i = 0; i < left; ++i) {\n\t\t\
    \tif (left_match[i] != -1) {\n\t\t\t\tres.emplace_back(i, left_match[i]);\n\t\t\
    \t}\n\t\t}\n\t\treturn res;\n\t}\n};\n#line 3 \"test/BipartiteMatching.test.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint l, r, m;\n\tcin >> l >> r >> m;\n\n\
    \tBipartiteMatching graph(l, r);\n\tfor (int i = 0; i < m; ++i) {\n\t\tint a,\
    \ b;\n\t\tcin >> a >> b;\n\t\tgraph.add_edge(a, b);\n\t}\n\n\tcout << graph.solve()\
    \ << '\\n';\n\tfor (auto [a, b] : graph.edges()) {\n\t\tcout << a << ' ' << b\
    \ << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ \"./../Graph/BipartiteMatching.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\tint\
    \ l, r, m;\n\tcin >> l >> r >> m;\n\n\tBipartiteMatching graph(l, r);\n\tfor (int\
    \ i = 0; i < m; ++i) {\n\t\tint a, b;\n\t\tcin >> a >> b;\n\t\tgraph.add_edge(a,\
    \ b);\n\t}\n\n\tcout << graph.solve() << '\\n';\n\tfor (auto [a, b] : graph.edges())\
    \ {\n\t\tcout << a << ' ' << b << '\\n';\n\t}\n}"
  dependsOn:
  - Graph/BipartiteMatching.cpp
  isVerificationFile: true
  path: test/BipartiteMatching.test.cpp
  requiredBy: []
  timestamp: '2020-10-18 11:21:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BipartiteMatching.test.cpp
layout: document
redirect_from:
- /verify/test/BipartiteMatching.test.cpp
- /verify/test/BipartiteMatching.test.cpp.html
title: test/BipartiteMatching.test.cpp
---
