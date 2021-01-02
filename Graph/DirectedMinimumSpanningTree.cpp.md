---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/Graph/GraphTemplate.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/Graph/GraphTemplate.cpp\"\n#include \"library/Graph/CycleDetection.cpp\"\
    \n#include <vector>\n#include <utility>\n#include <numeric>\nusing namespace std;\n\
    \nclass DirectedMinimumSpanningTree {\n\tint n;\n\tEdges edges;\n\npublic:\n\t\
    DirectedMinimumSpanningTree(int _n) : n(_n) {}\n\tvoid add_edge(int from, int\
    \ to, Weight cost) {\n\t\tif (from != to) {\n\t\t\tedges.emplace_back(from, to,\
    \ cost);\n\t\t}\n\t}\n\tWeight solve(int root) {\n\t\tvector<vector<Edge>> in_edges(n);\n\
    \t\tfor (auto edge : edges) {\n\t\t\tif (root != edge.to) {\n\t\t\t\tin_edges[edge.to].emplace_back(edge.from,\
    \ edge.cost);\n\t\t\t}\n\t\t}\n\n\t\tvector<pair<int, int>> min_edges;\n\t\tvector<Weight>\
    \ min_costs;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tif (in_edges[i].empty())\
    \ continue;\n\t\t\tpair<int, int> min_edge;\n\t\t\tWeight min_cost = INF;\n\t\t\
    \tfor (auto edge : in_edges[i]) {\n\t\t\t\tif (min_cost > edge.cost) {\n\t\t\t\
    \t\tmin_edge = pair(edge.to, i);\n\t\t\t\t\tmin_cost = edge.cost;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t\tmin_edges.push_back(min_edge);\n\t\t\tmin_costs.push_back(min_cost);\n\
    \t\t}\n\n\t\tif (auto cycle_opt = CycleDetectionEdge(n, min_edges); cycle_opt)\
    \ {\n\t\t\tconst auto& cycle = cycle_opt.value();\n\n\t\t\tvector<Weight> minus(n);\n\
    \t\t\tvector<bool> on_cycle(n);\n\t\t\tWeight cycle_cost_sum = 0;\n\t\t\tfor (int\
    \ i : cycle) {\n\t\t\t\tminus[min_edges[i].second] = min_costs[i];\n\t\t\t\ton_cycle[min_edges[i].first]\
    \ = true;\n\t\t\t\tcycle_cost_sum += min_costs[i];\n\t\t\t}\n\n\t\t\tint compressed_vertex\
    \ = min_edges[cycle.front()].first;\n\t\t\tDirectedMinimumSpanningTree sub(n);\n\
    \t\t\tfor (size_t i = 0; i < edges.size(); ++i) {\n\t\t\t\tauto edge = edges[i];\n\
    \t\t\t\tif (on_cycle[edge.to]) {\n\t\t\t\t\tif (on_cycle[edge.from]) continue;\n\
    \t\t\t\t\tedge.cost -= minus[edge.to];\n\t\t\t\t\tedge.to = compressed_vertex;\n\
    \t\t\t\t}\n\t\t\t\tif (on_cycle[edge.from]) {\n\t\t\t\t\tedge.from = compressed_vertex;\n\
    \t\t\t\t}\n\t\t\t\tsub.add_edge(edge.from, edge.to, edge.cost);\n\t\t\t}\n\t\t\
    \treturn cycle_cost_sum + sub.solve(root);\n\t\t} else {\n\t\t\treturn accumulate(min_costs.begin(),\
    \ min_costs.end(), Weight(0));\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/DirectedMinimumSpanningTree.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/DirectedMinimumSpanningTree.cpp
layout: document
redirect_from:
- /library/Graph/DirectedMinimumSpanningTree.cpp
- /library/Graph/DirectedMinimumSpanningTree.cpp.html
title: Graph/DirectedMinimumSpanningTree.cpp
---
