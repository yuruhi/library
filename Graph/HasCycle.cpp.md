---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/GraphTemplate.cpp
    title: Graph/GraphTemplate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/GraphTemplate.cpp\"\n#include <limits>\n#include <vector>\n\
    #include <iostream>\nusing namespace std;\n\nusing Weight = long long;\nconstexpr\
    \ Weight INF = numeric_limits<Weight>::max();\nstruct Edge {\n\tint to;\n\tWeight\
    \ cost;\n\tEdge() : to(-1), cost(-1) {}\n\tEdge(int _to, Weight _cost = 1) : to(_to),\
    \ cost(_cost) {}\n\tfriend bool operator<(const Edge& e1, const Edge& e2) {\n\t\
    \treturn e1.cost < e2.cost;\n\t}\n\tfriend bool operator>(const Edge& e1, const\
    \ Edge& e2) {\n\t\treturn e1.cost > e2.cost;\n\t}\n\tfriend ostream& operator<<(ostream&\
    \ os, const Edge& e) {\n\t\treturn os << \"->\" << e.to << '(' << e.cost << ')';\n\
    \t}\n};\nusing Graph = vector<vector<Edge>>;\nstruct Edge2 {\n\tint from, to;\n\
    \tWeight cost;\n\tEdge2() : from(-1), to(-1), cost(0) {}\n\tEdge2(int _from, int\
    \ _to, Weight _cost) : from(_from), to(_to), cost(_cost) {}\n\tfriend bool operator<(const\
    \ Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost < e2.cost;\n\t}\n\tfriend\
    \ bool operator>(const Edge2& e1, const Edge2& e2) {\n\t\treturn e1.cost > e2.cost;\n\
    \t}\n\tfriend ostream& operator<<(ostream& os, const Edge2& e) {\n\t\treturn os\
    \ << e.from << \"->\" << e.to << '(' << e.cost << ')';\n\t}\n};\nusing Edges =\
    \ vector<Edge2>;\nusing Matrix = vector<vector<Weight>>;\n#line 4 \"Graph/HasCycle.cpp\"\
    \n#include <stack>\nusing namespace std;\n\nbool HasCycle(const Graph& graph)\
    \ {\n\tint V = graph.size();\n\tvector<int> h(V);\n\tfor (auto g : graph) {\n\t\
    \tfor (auto e : g)\n\t\t\th[e.to]++;\n\t}\n\tstack<int> st;\n\tint cnt = 0;\n\t\
    for (int i = 0; i < V; i++)\n\t\tif (!h[i]) {\n\t\t\tst.push(i);\n\t\t\tcnt++;\n\
    \t\t}\n\tvector<int> res;\n\twhile (!st.empty()) {\n\t\tint i = st.top();\n\t\t\
    st.pop();\n\t\tres.push_back(i);\n\t\tfor (auto& e : graph[i]) {\n\t\t\th[e.to]--;\n\
    \t\t\tif (!h[e.to]) {\n\t\t\t\tst.push(e.to);\n\t\t\t\tcnt++;\n\t\t\t}\n\t\t}\n\
    \t}\n\treturn cnt != V;\n}\n"
  code: "#pragma once\n#include \"./GraphTemplate.cpp\"\n#include <vector>\n#include\
    \ <stack>\nusing namespace std;\n\nbool HasCycle(const Graph& graph) {\n\tint\
    \ V = graph.size();\n\tvector<int> h(V);\n\tfor (auto g : graph) {\n\t\tfor (auto\
    \ e : g)\n\t\t\th[e.to]++;\n\t}\n\tstack<int> st;\n\tint cnt = 0;\n\tfor (int\
    \ i = 0; i < V; i++)\n\t\tif (!h[i]) {\n\t\t\tst.push(i);\n\t\t\tcnt++;\n\t\t\
    }\n\tvector<int> res;\n\twhile (!st.empty()) {\n\t\tint i = st.top();\n\t\tst.pop();\n\
    \t\tres.push_back(i);\n\t\tfor (auto& e : graph[i]) {\n\t\t\th[e.to]--;\n\t\t\t\
    if (!h[e.to]) {\n\t\t\t\tst.push(e.to);\n\t\t\t\tcnt++;\n\t\t\t}\n\t\t}\n\t}\n\
    \treturn cnt != V;\n}"
  dependsOn:
  - Graph/GraphTemplate.cpp
  isVerificationFile: false
  path: Graph/HasCycle.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/HasCycle.cpp
layout: document
redirect_from:
- /library/Graph/HasCycle.cpp
- /library/Graph/HasCycle.cpp.html
title: Graph/HasCycle.cpp
---
