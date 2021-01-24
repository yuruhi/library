---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/internal_queue.hpp
    title: atcoder/internal_queue.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/maxflow.hpp\"\n\n\n\n#include <algorithm>\n#line\
    \ 1 \"atcoder/internal_queue.hpp\"\n\n\n\n#include <vector>\n\nnamespace atcoder\
    \ {\n\n\tnamespace internal {\n\n\t\ttemplate <class T> struct simple_queue {\n\
    \t\t\tstd::vector<T> payload;\n\t\t\tint pos = 0;\n\t\t\tvoid reserve(int n) {\n\
    \t\t\t\tpayload.reserve(n);\n\t\t\t}\n\t\t\tint size() const {\n\t\t\t\treturn\
    \ int(payload.size()) - pos;\n\t\t\t}\n\t\t\tbool empty() const {\n\t\t\t\treturn\
    \ pos == int(payload.size());\n\t\t\t}\n\t\t\tvoid push(const T& t) {\n\t\t\t\t\
    payload.push_back(t);\n\t\t\t}\n\t\t\tT& front() {\n\t\t\t\treturn payload[pos];\n\
    \t\t\t}\n\t\t\tvoid clear() {\n\t\t\t\tpayload.clear();\n\t\t\t\tpos = 0;\n\t\t\
    \t}\n\t\t\tvoid pop() {\n\t\t\t\tpos++;\n\t\t\t}\n\t\t};\n\n\t}  // namespace\
    \ internal\n\n}  // namespace atcoder\n\n\n#line 6 \"atcoder/maxflow.hpp\"\n#include\
    \ <cassert>\n#include <limits>\n#include <queue>\n#line 10 \"atcoder/maxflow.hpp\"\
    \n\nnamespace atcoder {\n\n\ttemplate <class Cap> struct mf_graph {\n\tpublic:\n\
    \t\tmf_graph() : _n(0) {}\n\t\tmf_graph(int n) : _n(n), g(n) {}\n\n\t\tint add_edge(int\
    \ from, int to, Cap cap) {\n\t\t\tassert(0 <= from && from < _n);\n\t\t\tassert(0\
    \ <= to && to < _n);\n\t\t\tassert(0 <= cap);\n\t\t\tint m = int(pos.size());\n\
    \t\t\tpos.push_back({from, int(g[from].size())});\n\t\t\tg[from].push_back(_edge{to,\
    \ int(g[to].size()), cap});\n\t\t\tg[to].push_back(_edge{from, int(g[from].size())\
    \ - 1, 0});\n\t\t\treturn m;\n\t\t}\n\n\t\tstruct edge {\n\t\t\tint from, to;\n\
    \t\t\tCap cap, flow;\n\t\t\tfriend std::ostream& operator<<(std::ostream& os,\
    \ const edge& e) {\n\t\t\t\treturn os << e.from << \"->\" << e.to << '(' << e.cap\
    \ << ',' << e.flow << ')';\n\t\t\t}\n\t\t};\n\n\t\tedge get_edge(int i) {\n\t\t\
    \tint m = int(pos.size());\n\t\t\tassert(0 <= i && i < m);\n\t\t\tauto _e = g[pos[i].first][pos[i].second];\n\
    \t\t\tauto _re = g[_e.to][_e.rev];\n\t\t\treturn edge{pos[i].first, _e.to, _e.cap\
    \ + _re.cap, _re.cap};\n\t\t}\n\t\tstd::vector<edge> edges() {\n\t\t\tint m =\
    \ int(pos.size());\n\t\t\tstd::vector<edge> result;\n\t\t\tfor (int i = 0; i <\
    \ m; i++) {\n\t\t\t\tresult.push_back(get_edge(i));\n\t\t\t}\n\t\t\treturn result;\n\
    \t\t}\n\t\tvoid change_edge(int i, Cap new_cap, Cap new_flow) {\n\t\t\tint m =\
    \ int(pos.size());\n\t\t\tassert(0 <= i && i < m);\n\t\t\tassert(0 <= new_flow\
    \ && new_flow <= new_cap);\n\t\t\tauto& _e = g[pos[i].first][pos[i].second];\n\
    \t\t\tauto& _re = g[_e.to][_e.rev];\n\t\t\t_e.cap = new_cap - new_flow;\n\t\t\t\
    _re.cap = new_flow;\n\t\t}\n\n\t\tCap flow(int s, int t) {\n\t\t\treturn flow(s,\
    \ t, std::numeric_limits<Cap>::max());\n\t\t}\n\t\tCap flow(int s, int t, Cap\
    \ flow_limit) {\n\t\t\tassert(0 <= s && s < _n);\n\t\t\tassert(0 <= t && t < _n);\n\
    \n\t\t\tstd::vector<int> level(_n), iter(_n);\n\t\t\tinternal::simple_queue<int>\
    \ que;\n\n\t\t\tauto bfs = [&]() {\n\t\t\t\tstd::fill(level.begin(), level.end(),\
    \ -1);\n\t\t\t\tlevel[s] = 0;\n\t\t\t\tque.clear();\n\t\t\t\tque.push(s);\n\t\t\
    \t\twhile (!que.empty()) {\n\t\t\t\t\tint v = que.front();\n\t\t\t\t\tque.pop();\n\
    \t\t\t\t\tfor (auto e : g[v]) {\n\t\t\t\t\t\tif (e.cap == 0 || level[e.to] >=\
    \ 0) continue;\n\t\t\t\t\t\tlevel[e.to] = level[v] + 1;\n\t\t\t\t\t\tif (e.to\
    \ == t) return;\n\t\t\t\t\t\tque.push(e.to);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t};\n\
    \t\t\tauto dfs = [&](auto self, int v, Cap up) {\n\t\t\t\tif (v == s) return up;\n\
    \t\t\t\tCap res = 0;\n\t\t\t\tint level_v = level[v];\n\t\t\t\tfor (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n\t\t\t\t\t_edge& e = g[v][i];\n\t\t\t\t\tif (level_v\
    \ <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n\t\t\t\t\tCap d = self(self,\
    \ e.to, std::min(up - res, g[e.to][e.rev].cap));\n\t\t\t\t\tif (d <= 0) continue;\n\
    \t\t\t\t\tg[v][i].cap += d;\n\t\t\t\t\tg[e.to][e.rev].cap -= d;\n\t\t\t\t\tres\
    \ += d;\n\t\t\t\t\tif (res == up) break;\n\t\t\t\t}\n\t\t\t\treturn res;\n\t\t\
    \t};\n\n\t\t\tCap flow = 0;\n\t\t\twhile (flow < flow_limit) {\n\t\t\t\tbfs();\n\
    \t\t\t\tif (level[t] == -1) break;\n\t\t\t\tstd::fill(iter.begin(), iter.end(),\
    \ 0);\n\t\t\t\twhile (flow < flow_limit) {\n\t\t\t\t\tCap f = dfs(dfs, t, flow_limit\
    \ - flow);\n\t\t\t\t\tif (!f) break;\n\t\t\t\t\tflow += f;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\treturn flow;\n\t\t}\n\n\t\tstd::vector<bool> min_cut(int s) {\n\t\t\t\
    std::vector<bool> visited(_n);\n\t\t\tinternal::simple_queue<int> que;\n\t\t\t\
    que.push(s);\n\t\t\twhile (!que.empty()) {\n\t\t\t\tint p = que.front();\n\t\t\
    \t\tque.pop();\n\t\t\t\tvisited[p] = true;\n\t\t\t\tfor (auto e : g[p]) {\n\t\t\
    \t\t\tif (e.cap && !visited[e.to]) {\n\t\t\t\t\t\tvisited[e.to] = true;\n\t\t\t\
    \t\t\tque.push(e.to);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn visited;\n\
    \t\t}\n\n\tprivate:\n\t\tint _n;\n\t\tstruct _edge {\n\t\t\tint to, rev;\n\t\t\
    \tCap cap;\n\t\t};\n\t\tstd::vector<std::pair<int, int>> pos;\n\t\tstd::vector<std::vector<_edge>>\
    \ g;\n\t};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_MAXFLOW_HPP\n#define ATCODER_MAXFLOW_HPP 1\n\n#include <algorithm>\n\
    #include \"./internal_queue.hpp\"\n#include <cassert>\n#include <limits>\n#include\
    \ <queue>\n#include <vector>\n\nnamespace atcoder {\n\n\ttemplate <class Cap>\
    \ struct mf_graph {\n\tpublic:\n\t\tmf_graph() : _n(0) {}\n\t\tmf_graph(int n)\
    \ : _n(n), g(n) {}\n\n\t\tint add_edge(int from, int to, Cap cap) {\n\t\t\tassert(0\
    \ <= from && from < _n);\n\t\t\tassert(0 <= to && to < _n);\n\t\t\tassert(0 <=\
    \ cap);\n\t\t\tint m = int(pos.size());\n\t\t\tpos.push_back({from, int(g[from].size())});\n\
    \t\t\tg[from].push_back(_edge{to, int(g[to].size()), cap});\n\t\t\tg[to].push_back(_edge{from,\
    \ int(g[from].size()) - 1, 0});\n\t\t\treturn m;\n\t\t}\n\n\t\tstruct edge {\n\
    \t\t\tint from, to;\n\t\t\tCap cap, flow;\n\t\t\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const edge& e) {\n\t\t\t\treturn os << e.from << \"->\" << e.to << '(' <<\
    \ e.cap << ',' << e.flow << ')';\n\t\t\t}\n\t\t};\n\n\t\tedge get_edge(int i)\
    \ {\n\t\t\tint m = int(pos.size());\n\t\t\tassert(0 <= i && i < m);\n\t\t\tauto\
    \ _e = g[pos[i].first][pos[i].second];\n\t\t\tauto _re = g[_e.to][_e.rev];\n\t\
    \t\treturn edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};\n\t\t}\n\t\t\
    std::vector<edge> edges() {\n\t\t\tint m = int(pos.size());\n\t\t\tstd::vector<edge>\
    \ result;\n\t\t\tfor (int i = 0; i < m; i++) {\n\t\t\t\tresult.push_back(get_edge(i));\n\
    \t\t\t}\n\t\t\treturn result;\n\t\t}\n\t\tvoid change_edge(int i, Cap new_cap,\
    \ Cap new_flow) {\n\t\t\tint m = int(pos.size());\n\t\t\tassert(0 <= i && i <\
    \ m);\n\t\t\tassert(0 <= new_flow && new_flow <= new_cap);\n\t\t\tauto& _e = g[pos[i].first][pos[i].second];\n\
    \t\t\tauto& _re = g[_e.to][_e.rev];\n\t\t\t_e.cap = new_cap - new_flow;\n\t\t\t\
    _re.cap = new_flow;\n\t\t}\n\n\t\tCap flow(int s, int t) {\n\t\t\treturn flow(s,\
    \ t, std::numeric_limits<Cap>::max());\n\t\t}\n\t\tCap flow(int s, int t, Cap\
    \ flow_limit) {\n\t\t\tassert(0 <= s && s < _n);\n\t\t\tassert(0 <= t && t < _n);\n\
    \n\t\t\tstd::vector<int> level(_n), iter(_n);\n\t\t\tinternal::simple_queue<int>\
    \ que;\n\n\t\t\tauto bfs = [&]() {\n\t\t\t\tstd::fill(level.begin(), level.end(),\
    \ -1);\n\t\t\t\tlevel[s] = 0;\n\t\t\t\tque.clear();\n\t\t\t\tque.push(s);\n\t\t\
    \t\twhile (!que.empty()) {\n\t\t\t\t\tint v = que.front();\n\t\t\t\t\tque.pop();\n\
    \t\t\t\t\tfor (auto e : g[v]) {\n\t\t\t\t\t\tif (e.cap == 0 || level[e.to] >=\
    \ 0) continue;\n\t\t\t\t\t\tlevel[e.to] = level[v] + 1;\n\t\t\t\t\t\tif (e.to\
    \ == t) return;\n\t\t\t\t\t\tque.push(e.to);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t};\n\
    \t\t\tauto dfs = [&](auto self, int v, Cap up) {\n\t\t\t\tif (v == s) return up;\n\
    \t\t\t\tCap res = 0;\n\t\t\t\tint level_v = level[v];\n\t\t\t\tfor (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n\t\t\t\t\t_edge& e = g[v][i];\n\t\t\t\t\tif (level_v\
    \ <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n\t\t\t\t\tCap d = self(self,\
    \ e.to, std::min(up - res, g[e.to][e.rev].cap));\n\t\t\t\t\tif (d <= 0) continue;\n\
    \t\t\t\t\tg[v][i].cap += d;\n\t\t\t\t\tg[e.to][e.rev].cap -= d;\n\t\t\t\t\tres\
    \ += d;\n\t\t\t\t\tif (res == up) break;\n\t\t\t\t}\n\t\t\t\treturn res;\n\t\t\
    \t};\n\n\t\t\tCap flow = 0;\n\t\t\twhile (flow < flow_limit) {\n\t\t\t\tbfs();\n\
    \t\t\t\tif (level[t] == -1) break;\n\t\t\t\tstd::fill(iter.begin(), iter.end(),\
    \ 0);\n\t\t\t\twhile (flow < flow_limit) {\n\t\t\t\t\tCap f = dfs(dfs, t, flow_limit\
    \ - flow);\n\t\t\t\t\tif (!f) break;\n\t\t\t\t\tflow += f;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\treturn flow;\n\t\t}\n\n\t\tstd::vector<bool> min_cut(int s) {\n\t\t\t\
    std::vector<bool> visited(_n);\n\t\t\tinternal::simple_queue<int> que;\n\t\t\t\
    que.push(s);\n\t\t\twhile (!que.empty()) {\n\t\t\t\tint p = que.front();\n\t\t\
    \t\tque.pop();\n\t\t\t\tvisited[p] = true;\n\t\t\t\tfor (auto e : g[p]) {\n\t\t\
    \t\t\tif (e.cap && !visited[e.to]) {\n\t\t\t\t\t\tvisited[e.to] = true;\n\t\t\t\
    \t\t\tque.push(e.to);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn visited;\n\
    \t\t}\n\n\tprivate:\n\t\tint _n;\n\t\tstruct _edge {\n\t\t\tint to, rev;\n\t\t\
    \tCap cap;\n\t\t};\n\t\tstd::vector<std::pair<int, int>> pos;\n\t\tstd::vector<std::vector<_edge>>\
    \ g;\n\t};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_MAXFLOW_HPP\n"
  dependsOn:
  - atcoder/internal_queue.hpp
  isVerificationFile: false
  path: atcoder/maxflow.hpp
  requiredBy: []
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/maxflow.hpp
layout: document
redirect_from:
- /library/atcoder/maxflow.hpp
- /library/atcoder/maxflow.hpp.html
title: atcoder/maxflow.hpp
---
