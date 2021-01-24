---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/twosat.hpp\"\n\n\n\n#line 1 \"atcoder/internal_scc.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ atcoder {\n\tnamespace internal {\n\n\t\ttemplate <class E> struct csr {\n\t\
    \t\tstd::vector<int> start;\n\t\t\tstd::vector<E> elist;\n\t\t\tcsr(int n, const\
    \ std::vector<std::pair<int, E>>& edges) : start(n + 1), elist(edges.size()) {\n\
    \t\t\t\tfor (auto e : edges) {\n\t\t\t\t\tstart[e.first + 1]++;\n\t\t\t\t}\n\t\
    \t\t\tfor (int i = 1; i <= n; i++) {\n\t\t\t\t\tstart[i] += start[i - 1];\n\t\t\
    \t\t}\n\t\t\t\tauto counter = start;\n\t\t\t\tfor (auto e : edges) {\n\t\t\t\t\
    \telist[counter[e.first]++] = e.second;\n\t\t\t\t}\n\t\t\t}\n\t\t};\n\n\t\t//\
    \ Reference:\n\t\t// R. Tarjan,\n\t\t// Depth-First Search and Linear Graph Algorithms\n\
    \t\tstruct scc_graph {\n\t\tpublic:\n\t\t\tscc_graph(int n) : _n(n) {}\n\n\t\t\
    \tint num_vertices() {\n\t\t\t\treturn _n;\n\t\t\t}\n\n\t\t\tvoid add_edge(int\
    \ from, int to) {\n\t\t\t\tedges.push_back({from, {to}});\n\t\t\t}\n\n\t\t\t//\
    \ @return pair of (# of scc, scc id)\n\t\t\tstd::pair<int, std::vector<int>> scc_ids()\
    \ {\n\t\t\t\tauto g = csr<edge>(_n, edges);\n\t\t\t\tint now_ord = 0, group_num\
    \ = 0;\n\t\t\t\tstd::vector<int> visited, low(_n), ord(_n, -1), ids(_n);\n\t\t\
    \t\tvisited.reserve(_n);\n\t\t\t\tauto dfs = [&](auto self, int v) -> void {\n\
    \t\t\t\t\tlow[v] = ord[v] = now_ord++;\n\t\t\t\t\tvisited.push_back(v);\n\t\t\t\
    \t\tfor (int i = g.start[v]; i < g.start[v + 1]; i++) {\n\t\t\t\t\t\tauto to =\
    \ g.elist[i].to;\n\t\t\t\t\t\tif (ord[to] == -1) {\n\t\t\t\t\t\t\tself(self, to);\n\
    \t\t\t\t\t\t\tlow[v] = std::min(low[v], low[to]);\n\t\t\t\t\t\t} else {\n\t\t\t\
    \t\t\t\tlow[v] = std::min(low[v], ord[to]);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\
    \t\tif (low[v] == ord[v]) {\n\t\t\t\t\t\twhile (true) {\n\t\t\t\t\t\t\tint u =\
    \ visited.back();\n\t\t\t\t\t\t\tvisited.pop_back();\n\t\t\t\t\t\t\tord[u] = _n;\n\
    \t\t\t\t\t\t\tids[u] = group_num;\n\t\t\t\t\t\t\tif (u == v) break;\n\t\t\t\t\t\
    \t}\n\t\t\t\t\t\tgroup_num++;\n\t\t\t\t\t}\n\t\t\t\t};\n\t\t\t\tfor (int i = 0;\
    \ i < _n; i++) {\n\t\t\t\t\tif (ord[i] == -1) dfs(dfs, i);\n\t\t\t\t}\n\t\t\t\t\
    for (auto& x : ids) {\n\t\t\t\t\tx = group_num - 1 - x;\n\t\t\t\t}\n\t\t\t\treturn\
    \ {group_num, ids};\n\t\t\t}\n\n\t\t\tstd::vector<std::vector<int>> scc() {\n\t\
    \t\t\tauto ids = scc_ids();\n\t\t\t\tint group_num = ids.first;\n\t\t\t\tstd::vector<int>\
    \ counts(group_num);\n\t\t\t\tfor (auto x : ids.second)\n\t\t\t\t\tcounts[x]++;\n\
    \t\t\t\tstd::vector<std::vector<int>> groups(ids.first);\n\t\t\t\tfor (int i =\
    \ 0; i < group_num; i++) {\n\t\t\t\t\tgroups[i].reserve(counts[i]);\n\t\t\t\t\
    }\n\t\t\t\tfor (int i = 0; i < _n; i++) {\n\t\t\t\t\tgroups[ids.second[i]].push_back(i);\n\
    \t\t\t\t}\n\t\t\t\treturn groups;\n\t\t\t}\n\n\t\tprivate:\n\t\t\tint _n;\n\t\t\
    \tstruct edge {\n\t\t\t\tint to;\n\t\t\t};\n\t\t\tstd::vector<std::pair<int, edge>>\
    \ edges;\n\t\t};\n\n\t}  // namespace internal\n\n}  // namespace atcoder\n\n\n\
    #line 5 \"atcoder/twosat.hpp\"\n#include <cassert>\n#line 7 \"atcoder/twosat.hpp\"\
    \n\nnamespace atcoder {\n\n\t// Reference:\n\t// B. Aspvall, M. Plass, and R.\
    \ Tarjan,\n\t// A Linear-Time Algorithm for Testing the Truth of Certain Quantified\
    \ Boolean\n\t// Formulas\n\tstruct two_sat {\n\tpublic:\n\t\ttwo_sat() : _n(0),\
    \ scc(0) {}\n\t\ttwo_sat(int n) : _n(n), _answer(n), scc(2 * n) {}\n\n\t\tvoid\
    \ add_clause(int i, bool f, int j, bool g) {\n\t\t\tassert(0 <= i && i < _n);\n\
    \t\t\tassert(0 <= j && j < _n);\n\t\t\tscc.add_edge(2 * i + (f ? 0 : 1), 2 * j\
    \ + (g ? 1 : 0));\n\t\t\tscc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));\n\
    \t\t}\n\t\tbool satisfiable() {\n\t\t\tauto id = scc.scc_ids().second;\n\t\t\t\
    for (int i = 0; i < _n; i++) {\n\t\t\t\tif (id[2 * i] == id[2 * i + 1]) return\
    \ false;\n\t\t\t\t_answer[i] = id[2 * i] < id[2 * i + 1];\n\t\t\t}\n\t\t\treturn\
    \ true;\n\t\t}\n\t\tstd::vector<bool> answer() {\n\t\t\treturn _answer;\n\t\t\
    }\n\n\tprivate:\n\t\tint _n;\n\t\tstd::vector<bool> _answer;\n\t\tinternal::scc_graph\
    \ scc;\n\t};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_TWOSAT_HPP\n#define ATCODER_TWOSAT_HPP 1\n\n#include \"./internal_scc.hpp\"\
    \n#include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n\t// Reference:\n\
    \t// B. Aspvall, M. Plass, and R. Tarjan,\n\t// A Linear-Time Algorithm for Testing\
    \ the Truth of Certain Quantified Boolean\n\t// Formulas\n\tstruct two_sat {\n\
    \tpublic:\n\t\ttwo_sat() : _n(0), scc(0) {}\n\t\ttwo_sat(int n) : _n(n), _answer(n),\
    \ scc(2 * n) {}\n\n\t\tvoid add_clause(int i, bool f, int j, bool g) {\n\t\t\t\
    assert(0 <= i && i < _n);\n\t\t\tassert(0 <= j && j < _n);\n\t\t\tscc.add_edge(2\
    \ * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n\t\t\tscc.add_edge(2 * j + (g ? 0\
    \ : 1), 2 * i + (f ? 1 : 0));\n\t\t}\n\t\tbool satisfiable() {\n\t\t\tauto id\
    \ = scc.scc_ids().second;\n\t\t\tfor (int i = 0; i < _n; i++) {\n\t\t\t\tif (id[2\
    \ * i] == id[2 * i + 1]) return false;\n\t\t\t\t_answer[i] = id[2 * i] < id[2\
    \ * i + 1];\n\t\t\t}\n\t\t\treturn true;\n\t\t}\n\t\tstd::vector<bool> answer()\
    \ {\n\t\t\treturn _answer;\n\t\t}\n\n\tprivate:\n\t\tint _n;\n\t\tstd::vector<bool>\
    \ _answer;\n\t\tinternal::scc_graph scc;\n\t};\n\n}  // namespace atcoder\n\n\
    #endif  // ATCODER_TWOSAT_HPP\n"
  dependsOn:
  - atcoder/internal_scc.hpp
  isVerificationFile: false
  path: atcoder/twosat.hpp
  requiredBy: []
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/twosat.hpp
layout: document
redirect_from:
- /library/atcoder/twosat.hpp
- /library/atcoder/twosat.hpp.html
title: atcoder/twosat.hpp
---
