---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/mincostflow.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <queue>\n#include <vector>\n\n\
    namespace atcoder {\n\n\ttemplate <class Cap, class Cost> struct mcf_graph {\n\
    \tpublic:\n\t\tmcf_graph() {}\n\t\tmcf_graph(int n) : _n(n), g(n) {}\n\n\t\tint\
    \ add_edge(int from, int to, Cap cap, Cost cost) {\n\t\t\tassert(0 <= from &&\
    \ from < _n);\n\t\t\tassert(0 <= to && to < _n);\n\t\t\tint m = int(pos.size());\n\
    \t\t\tpos.push_back({from, int(g[from].size())});\n\t\t\tg[from].push_back(_edge{to,\
    \ int(g[to].size()), cap, cost});\n\t\t\tg[to].push_back(_edge{from, int(g[from].size())\
    \ - 1, 0, -cost});\n\t\t\treturn m;\n\t\t}\n\n\t\tstruct edge {\n\t\t\tint from,\
    \ to;\n\t\t\tCap cap, flow;\n\t\t\tCost cost;\n\t\t\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const edge& e) {\n\t\t\t\treturn os << e.from << \"->\" << e.to << \"(\"\
    \ << e.cap << \", \" << e.cost << \")\";\n\t\t\t}\n\t\t};\n\n\t\tedge get_edge(int\
    \ i) {\n\t\t\tint m = int(pos.size());\n\t\t\tassert(0 <= i && i < m);\n\t\t\t\
    auto _e = g[pos[i].first][pos[i].second];\n\t\t\tauto _re = g[_e.to][_e.rev];\n\
    \t\t\treturn edge{\n\t\t\t    pos[i].first, _e.to, _e.cap + _re.cap, _re.cap,\
    \ _e.cost,\n\t\t\t};\n\t\t}\n\t\tstd::vector<edge> edges() {\n\t\t\tint m = int(pos.size());\n\
    \t\t\tstd::vector<edge> result(m);\n\t\t\tfor (int i = 0; i < m; i++) {\n\t\t\t\
    \tresult[i] = get_edge(i);\n\t\t\t}\n\t\t\treturn result;\n\t\t}\n\n\t\tstd::pair<Cap,\
    \ Cost> flow(int s, int t) {\n\t\t\treturn flow(s, t, std::numeric_limits<Cap>::max());\n\
    \t\t}\n\t\tstd::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {\n\t\t\treturn\
    \ slope(s, t, flow_limit).back();\n\t\t}\n\t\tstd::vector<std::pair<Cap, Cost>>\
    \ slope(int s, int t) {\n\t\t\treturn slope(s, t, std::numeric_limits<Cap>::max());\n\
    \t\t}\n\t\tstd::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit)\
    \ {\n\t\t\tassert(0 <= s && s < _n);\n\t\t\tassert(0 <= t && t < _n);\n\t\t\t\
    assert(s != t);\n\t\t\t// variants (C = maxcost):\n\t\t\t// -(n-1)C <= dual[s]\
    \ <= dual[i] <= dual[t] = 0\n\t\t\t// reduced cost (= e.cost + dual[e.from] -\
    \ dual[e.to]) >= 0 for all edge\n\t\t\tstd::vector<Cost> dual(_n, 0), dist(_n);\n\
    \t\t\tstd::vector<int> pv(_n), pe(_n);\n\t\t\tstd::vector<bool> vis(_n);\n\t\t\
    \tauto dual_ref = [&]() {\n\t\t\t\tstd::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());\n\
    \t\t\t\tstd::fill(pv.begin(), pv.end(), -1);\n\t\t\t\tstd::fill(pe.begin(), pe.end(),\
    \ -1);\n\t\t\t\tstd::fill(vis.begin(), vis.end(), false);\n\t\t\t\tstruct Q {\n\
    \t\t\t\t\tCost key;\n\t\t\t\t\tint to;\n\t\t\t\t\tbool operator<(Q r) const {\n\
    \t\t\t\t\t\treturn key > r.key;\n\t\t\t\t\t}\n\t\t\t\t};\n\t\t\t\tstd::priority_queue<Q>\
    \ que;\n\t\t\t\tdist[s] = 0;\n\t\t\t\tque.push(Q{0, s});\n\t\t\t\twhile (!que.empty())\
    \ {\n\t\t\t\t\tint v = que.top().to;\n\t\t\t\t\tque.pop();\n\t\t\t\t\tif (vis[v])\
    \ continue;\n\t\t\t\t\tvis[v] = true;\n\t\t\t\t\tif (v == t) break;\n\t\t\t\t\t\
    // dist[v] = shortest(s, v) + dual[s] - dual[v]\n\t\t\t\t\t// dist[v] >= 0 (all\
    \ reduced cost are positive)\n\t\t\t\t\t// dist[v] <= (n-1)C\n\t\t\t\t\tfor (int\
    \ i = 0; i < int(g[v].size()); i++) {\n\t\t\t\t\t\tauto e = g[v][i];\n\t\t\t\t\
    \t\tif (vis[e.to] || !e.cap) continue;\n\t\t\t\t\t\t// |-dual[e.to] + dual[v]|\
    \ <= (n-1)C\n\t\t\t\t\t\t// cost <= C - -(n-1)C + 0 = nC\n\t\t\t\t\t\tCost cost\
    \ = e.cost - dual[e.to] + dual[v];\n\t\t\t\t\t\tif (dist[e.to] - dist[v] > cost)\
    \ {\n\t\t\t\t\t\t\tdist[e.to] = dist[v] + cost;\n\t\t\t\t\t\t\tpv[e.to] = v;\n\
    \t\t\t\t\t\t\tpe[e.to] = i;\n\t\t\t\t\t\t\tque.push(Q{dist[e.to], e.to});\n\t\t\
    \t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tif (!vis[t]) {\n\t\t\t\t\treturn false;\n\
    \t\t\t\t}\n\n\t\t\t\tfor (int v = 0; v < _n; v++) {\n\t\t\t\t\tif (!vis[v]) continue;\n\
    \t\t\t\t\t// dual[v] = dual[v] - dist[t] + dist[v]\n\t\t\t\t\t//         = dual[v]\
    \ - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, v) + dual[s] - dual[v])\n\
    \t\t\t\t\t//         = - shortest(s, t) + dual[t] + shortest(s, v)\n\t\t\t\t\t\
    //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C\n\t\t\t\t\tdual[v]\
    \ -= dist[t] - dist[v];\n\t\t\t\t}\n\t\t\t\treturn true;\n\t\t\t};\n\t\t\tCap\
    \ flow = 0;\n\t\t\tCost cost = 0, prev_cost = -1;\n\t\t\tstd::vector<std::pair<Cap,\
    \ Cost>> result;\n\t\t\tresult.push_back({flow, cost});\n\t\t\twhile (flow < flow_limit)\
    \ {\n\t\t\t\tif (!dual_ref()) break;\n\t\t\t\tCap c = flow_limit - flow;\n\t\t\
    \t\tfor (int v = t; v != s; v = pv[v]) {\n\t\t\t\t\tc = std::min(c, g[pv[v]][pe[v]].cap);\n\
    \t\t\t\t}\n\t\t\t\tfor (int v = t; v != s; v = pv[v]) {\n\t\t\t\t\tauto& e = g[pv[v]][pe[v]];\n\
    \t\t\t\t\te.cap -= c;\n\t\t\t\t\tg[v][e.rev].cap += c;\n\t\t\t\t}\n\t\t\t\tCost\
    \ d = -dual[s];\n\t\t\t\tflow += c;\n\t\t\t\tcost += c * d;\n\t\t\t\tif (prev_cost\
    \ == d) {\n\t\t\t\t\tresult.pop_back();\n\t\t\t\t}\n\t\t\t\tresult.push_back({flow,\
    \ cost});\n\t\t\t\tprev_cost = cost;\n\t\t\t}\n\t\t\treturn result;\n\t\t}\n\n\
    \tprivate:\n\t\tint _n;\n\n\t\tstruct _edge {\n\t\t\tint to, rev;\n\t\t\tCap cap;\n\
    \t\t\tCost cost;\n\t\t};\n\n\t\tstd::vector<std::pair<int, int>> pos;\n\t\tstd::vector<std::vector<_edge>>\
    \ g;\n\t};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_MINCOSTFLOW_HPP\n#define ATCODER_MINCOSTFLOW_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n#include\
    \ <vector>\n\nnamespace atcoder {\n\n\ttemplate <class Cap, class Cost> struct\
    \ mcf_graph {\n\tpublic:\n\t\tmcf_graph() {}\n\t\tmcf_graph(int n) : _n(n), g(n)\
    \ {}\n\n\t\tint add_edge(int from, int to, Cap cap, Cost cost) {\n\t\t\tassert(0\
    \ <= from && from < _n);\n\t\t\tassert(0 <= to && to < _n);\n\t\t\tint m = int(pos.size());\n\
    \t\t\tpos.push_back({from, int(g[from].size())});\n\t\t\tg[from].push_back(_edge{to,\
    \ int(g[to].size()), cap, cost});\n\t\t\tg[to].push_back(_edge{from, int(g[from].size())\
    \ - 1, 0, -cost});\n\t\t\treturn m;\n\t\t}\n\n\t\tstruct edge {\n\t\t\tint from,\
    \ to;\n\t\t\tCap cap, flow;\n\t\t\tCost cost;\n\t\t\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const edge& e) {\n\t\t\t\treturn os << e.from << \"->\" << e.to << \"(\"\
    \ << e.cap << \", \" << e.cost << \")\";\n\t\t\t}\n\t\t};\n\n\t\tedge get_edge(int\
    \ i) {\n\t\t\tint m = int(pos.size());\n\t\t\tassert(0 <= i && i < m);\n\t\t\t\
    auto _e = g[pos[i].first][pos[i].second];\n\t\t\tauto _re = g[_e.to][_e.rev];\n\
    \t\t\treturn edge{\n\t\t\t    pos[i].first, _e.to, _e.cap + _re.cap, _re.cap,\
    \ _e.cost,\n\t\t\t};\n\t\t}\n\t\tstd::vector<edge> edges() {\n\t\t\tint m = int(pos.size());\n\
    \t\t\tstd::vector<edge> result(m);\n\t\t\tfor (int i = 0; i < m; i++) {\n\t\t\t\
    \tresult[i] = get_edge(i);\n\t\t\t}\n\t\t\treturn result;\n\t\t}\n\n\t\tstd::pair<Cap,\
    \ Cost> flow(int s, int t) {\n\t\t\treturn flow(s, t, std::numeric_limits<Cap>::max());\n\
    \t\t}\n\t\tstd::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {\n\t\t\treturn\
    \ slope(s, t, flow_limit).back();\n\t\t}\n\t\tstd::vector<std::pair<Cap, Cost>>\
    \ slope(int s, int t) {\n\t\t\treturn slope(s, t, std::numeric_limits<Cap>::max());\n\
    \t\t}\n\t\tstd::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit)\
    \ {\n\t\t\tassert(0 <= s && s < _n);\n\t\t\tassert(0 <= t && t < _n);\n\t\t\t\
    assert(s != t);\n\t\t\t// variants (C = maxcost):\n\t\t\t// -(n-1)C <= dual[s]\
    \ <= dual[i] <= dual[t] = 0\n\t\t\t// reduced cost (= e.cost + dual[e.from] -\
    \ dual[e.to]) >= 0 for all edge\n\t\t\tstd::vector<Cost> dual(_n, 0), dist(_n);\n\
    \t\t\tstd::vector<int> pv(_n), pe(_n);\n\t\t\tstd::vector<bool> vis(_n);\n\t\t\
    \tauto dual_ref = [&]() {\n\t\t\t\tstd::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());\n\
    \t\t\t\tstd::fill(pv.begin(), pv.end(), -1);\n\t\t\t\tstd::fill(pe.begin(), pe.end(),\
    \ -1);\n\t\t\t\tstd::fill(vis.begin(), vis.end(), false);\n\t\t\t\tstruct Q {\n\
    \t\t\t\t\tCost key;\n\t\t\t\t\tint to;\n\t\t\t\t\tbool operator<(Q r) const {\n\
    \t\t\t\t\t\treturn key > r.key;\n\t\t\t\t\t}\n\t\t\t\t};\n\t\t\t\tstd::priority_queue<Q>\
    \ que;\n\t\t\t\tdist[s] = 0;\n\t\t\t\tque.push(Q{0, s});\n\t\t\t\twhile (!que.empty())\
    \ {\n\t\t\t\t\tint v = que.top().to;\n\t\t\t\t\tque.pop();\n\t\t\t\t\tif (vis[v])\
    \ continue;\n\t\t\t\t\tvis[v] = true;\n\t\t\t\t\tif (v == t) break;\n\t\t\t\t\t\
    // dist[v] = shortest(s, v) + dual[s] - dual[v]\n\t\t\t\t\t// dist[v] >= 0 (all\
    \ reduced cost are positive)\n\t\t\t\t\t// dist[v] <= (n-1)C\n\t\t\t\t\tfor (int\
    \ i = 0; i < int(g[v].size()); i++) {\n\t\t\t\t\t\tauto e = g[v][i];\n\t\t\t\t\
    \t\tif (vis[e.to] || !e.cap) continue;\n\t\t\t\t\t\t// |-dual[e.to] + dual[v]|\
    \ <= (n-1)C\n\t\t\t\t\t\t// cost <= C - -(n-1)C + 0 = nC\n\t\t\t\t\t\tCost cost\
    \ = e.cost - dual[e.to] + dual[v];\n\t\t\t\t\t\tif (dist[e.to] - dist[v] > cost)\
    \ {\n\t\t\t\t\t\t\tdist[e.to] = dist[v] + cost;\n\t\t\t\t\t\t\tpv[e.to] = v;\n\
    \t\t\t\t\t\t\tpe[e.to] = i;\n\t\t\t\t\t\t\tque.push(Q{dist[e.to], e.to});\n\t\t\
    \t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tif (!vis[t]) {\n\t\t\t\t\treturn false;\n\
    \t\t\t\t}\n\n\t\t\t\tfor (int v = 0; v < _n; v++) {\n\t\t\t\t\tif (!vis[v]) continue;\n\
    \t\t\t\t\t// dual[v] = dual[v] - dist[t] + dist[v]\n\t\t\t\t\t//         = dual[v]\
    \ - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, v) + dual[s] - dual[v])\n\
    \t\t\t\t\t//         = - shortest(s, t) + dual[t] + shortest(s, v)\n\t\t\t\t\t\
    //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C\n\t\t\t\t\tdual[v]\
    \ -= dist[t] - dist[v];\n\t\t\t\t}\n\t\t\t\treturn true;\n\t\t\t};\n\t\t\tCap\
    \ flow = 0;\n\t\t\tCost cost = 0, prev_cost = -1;\n\t\t\tstd::vector<std::pair<Cap,\
    \ Cost>> result;\n\t\t\tresult.push_back({flow, cost});\n\t\t\twhile (flow < flow_limit)\
    \ {\n\t\t\t\tif (!dual_ref()) break;\n\t\t\t\tCap c = flow_limit - flow;\n\t\t\
    \t\tfor (int v = t; v != s; v = pv[v]) {\n\t\t\t\t\tc = std::min(c, g[pv[v]][pe[v]].cap);\n\
    \t\t\t\t}\n\t\t\t\tfor (int v = t; v != s; v = pv[v]) {\n\t\t\t\t\tauto& e = g[pv[v]][pe[v]];\n\
    \t\t\t\t\te.cap -= c;\n\t\t\t\t\tg[v][e.rev].cap += c;\n\t\t\t\t}\n\t\t\t\tCost\
    \ d = -dual[s];\n\t\t\t\tflow += c;\n\t\t\t\tcost += c * d;\n\t\t\t\tif (prev_cost\
    \ == d) {\n\t\t\t\t\tresult.pop_back();\n\t\t\t\t}\n\t\t\t\tresult.push_back({flow,\
    \ cost});\n\t\t\t\tprev_cost = cost;\n\t\t\t}\n\t\t\treturn result;\n\t\t}\n\n\
    \tprivate:\n\t\tint _n;\n\n\t\tstruct _edge {\n\t\t\tint to, rev;\n\t\t\tCap cap;\n\
    \t\t\tCost cost;\n\t\t};\n\n\t\tstd::vector<std::pair<int, int>> pos;\n\t\tstd::vector<std::vector<_edge>>\
    \ g;\n\t};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_MINCOSTFLOW_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/mincostflow.hpp
  requiredBy: []
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/mincostflow.hpp
layout: document
redirect_from:
- /library/atcoder/mincostflow.hpp
- /library/atcoder/mincostflow.hpp.html
title: atcoder/mincostflow.hpp
---
