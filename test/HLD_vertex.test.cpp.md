---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.cpp
    title: DataStructure/LazySegmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/HeavyLightDecomposition.cpp
    title: Graph/HeavyLightDecomposition.cpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/399
    links:
    - https://yukicoder.me/problems/no/399
  bundledCode: "#line 1 \"test/HLD_vertex.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/399\"\
    \n#line 2 \"Graph/HeavyLightDecomposition.cpp\"\n#include <vector>\n#include <cassert>\n\
    using namespace std;\n\nclass HLD {\n\tint n;\n\tvector<vector<int>> graph;\n\t\
    vector<int> parent, size;\n\tint k;\n\tvector<int> head, hld, index, out_index;\n\
    \tbool builded = false;\n\n\tint calc_size(int v, int p, int d) {\n\t\tparent[v]\
    \ = p;\n\t\tsize[v] = 1;\n\t\tfor (int u : graph[v]) {\n\t\t\tif (u != p) {\n\t\
    \t\t\tsize[v] += calc_size(u, v, d + 1);\n\t\t\t}\n\t\t}\n\t\treturn size[v];\n\
    \t}\n\tvoid rec(int v, int p, int root) {\n\t\thead[v] = root;\n\t\tindex[v] =\
    \ k;\n\t\thld[k++] = v;\n\n\t\tint heavy_vertex = -1, max_size = 0;\n\t\tfor (int\
    \ u : graph[v]) {\n\t\t\tif (u != p && max_size < size[u]) {\n\t\t\t\tmax_size\
    \ = size[u];\n\t\t\t\theavy_vertex = u;\n\t\t\t}\n\t\t}\n\t\tif (heavy_vertex\
    \ != -1) {\n\t\t\trec(heavy_vertex, v, root);\n\t\t\tfor (int u : graph[v]) {\n\
    \t\t\t\tif (u != heavy_vertex && u != p) {\n\t\t\t\t\trec(u, v, u);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\tout_index[v] = k;\n\t}\n\npublic:\n\tHLD(int _n) : n(_n),\
    \ graph(_n) {}\n\tHLD(const vector<vector<int>>& _graph) : n(_graph.size()), graph(_graph)\
    \ {}\n\tvoid add_edge(int u, int v) {\n\t\tgraph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\
    \t\tbuilded = false;\n\t}\n\tvoid build(int root) {\n\t\tparent.assign(n, -1);\n\
    \t\tsize.assign(n, 0);\n\t\tcalc_size(root, -1, 1);\n\t\tk = 0;\n\t\thead.assign(n,\
    \ 0);\n\t\thld.assign(n, 0);\n\t\tindex.assign(n, 0);\n\t\tout_index.assign(n,\
    \ 0);\n\t\trec(root, -1, root);\n\t\tbuilded = true;\n\t}\n\tconst vector<vector<int>>&\
    \ get_graph() const {\n\t\tassert(builded);\n\t\treturn graph;\n\t}\n\tconst vector<int>&\
    \ get_parent() const {\n\t\tassert(builded);\n\t\treturn parent;\n\t}\n\tconst\
    \ vector<int>& get_size() const {\n\t\tassert(builded);\n\t\treturn size;\n\t\
    }\n\tconst vector<int>& get_head() const {\n\t\tassert(builded);\n\t\treturn head;\n\
    \t}\n\tconst vector<int>& get_hld() const {\n\t\tassert(builded);\n\t\treturn\
    \ hld;\n\t}\n\tconst vector<int>& get_index() const {\n\t\tassert(builded);\n\t\
    \treturn index;\n\t}\n\tconst vector<int>& get_out_index() const {\n\t\tassert(builded);\n\
    \t\treturn out_index;\n\t}\n\tint operator[](int v) const {\n\t\tassert(builded);\n\
    \t\treturn index[v];\n\t}\n\n\ttemplate <class F> void each_vertex(int v, int\
    \ u, F f) const {\n\t\tassert(builded);\n\t\twhile (true) {\n\t\t\tif (index[v]\
    \ > index[u]) swap(v, u);\n\t\t\tif (head[v] != head[u]) {\n\t\t\t\tf(index[head[u]],\
    \ index[u] + 1);\n\t\t\t\tu = parent[head[u]];\n\t\t\t} else {\n\t\t\t\tf(index[v],\
    \ index[u] + 1);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class F> void\
    \ each_subtree_vertex(int v, F f) const {\n\t\tassert(builded);\n\t\tf(index[v],\
    \ out_index[v]);\n\t}\n\ttemplate <class F> void each_edge(int v, int u, F f)\
    \ const {\n\t\tassert(builded);\n\t\twhile (true) {\n\t\t\tif (index[v] > index[u])\
    \ swap(v, u);\n\t\t\tif (head[v] != head[u]) {\n\t\t\t\tf(index[head[u]], index[u]\
    \ + 1);\n\t\t\t\tu = parent[head[u]];\n\t\t\t} else {\n\t\t\t\tif (v != u) f(index[v]\
    \ + 1, index[u] + 1);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t}\n\ttemplate <class\
    \ F> void each_subtree_edge(int v, F f) const {\n\t\tassert(builded);\n\t\tf(index[v]\
    \ + 1, out_index[v]);\n\t}\n\tvector<pair<int, int>> query_vertex(int u, int v)\
    \ const {\n\t\tassert(builded);\n\t\tvector<pair<int, int>> result;\n\t\teach_vertex(u,\
    \ v, [&](int a, int b) { result.emplace_back(a, b); });\n\t\treturn result;\n\t\
    }\n\tpair<int, int> query_subtree_vertex(int v) const {\n\t\tassert(builded);\n\
    \t\tpair<int, int> result;\n\t\teach_subtree_vertex(v, [&](int a, int b) { result\
    \ = {a, b}; });\n\t\treturn result;\n\t}\n\tvector<pair<int, int>> query_edge(int\
    \ u, int v) const {\n\t\tassert(builded);\n\t\tvector<pair<int, int>> result;\n\
    \t\teach_edge(u, v, [&](int a, int b) { result.emplace_back(a, b); });\n\t\treturn\
    \ result;\n\t}\n\tpair<int, int> query_subtree_edge(int v) const {\n\t\tassert(builded);\n\
    \t\tpair<int, int> result;\n\t\teach_subtree_edge(v, [&](int a, int b) { result\
    \ = {a, b}; });\n\t\treturn result;\n\t}\n\tint lca(int u, int v) const {\n\t\t\
    while (true) {\n\t\t\tif (index[u] > index[v]) swap(u, v);\n\t\t\tif (head[u]\
    \ != head[v]) {\n\t\t\t\tv = parent[head[v]];\n\t\t\t} else {\n\t\t\t\treturn\
    \ u;\n\t\t\t}\n\t\t}\n\t}\n};\n#line 1 \"atcoder/lazysegtree.hpp\"\n\n\n\n#line\
    \ 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\nnamespace atcoder {\n\n\tnamespace internal {\n\n\t\t// @param n `0\
    \ <= n`\n\t\t// @return minimum non-negative `x` s.t. `n <= 2**x`\n\t\tint ceil_pow2(int\
    \ n) {\n\t\t\tint x = 0;\n\t\t\twhile ((1U << x) < (unsigned int)(n))\n\t\t\t\t\
    x++;\n\t\t\treturn x;\n\t\t}\n\n\t\t// @param n `1 <= n`\n\t\t// @return minimum\
    \ non-negative `x` s.t. `(n & (1 << x)) != 0`\n\t\tint bsf(unsigned int n) {\n\
    #ifdef _MSC_VER\n\t\t\tunsigned long index;\n\t\t\t_BitScanForward(&index, n);\n\
    \t\t\treturn index;\n#else\n\t\t\treturn __builtin_ctz(n);\n#endif\n\t\t}\n\n\t\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 5 \"atcoder/lazysegtree.hpp\"\
    \n#include <algorithm>\n#line 7 \"atcoder/lazysegtree.hpp\"\n#include <iostream>\n\
    #line 9 \"atcoder/lazysegtree.hpp\"\nnamespace atcoder {\n\n\ttemplate <class\
    \ S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n\t          F (*composition)(F,\
    \ F), F (*id)()>\n\tstruct lazy_segtree {\n\tpublic:\n\t\tlazy_segtree() : lazy_segtree(0)\
    \ {}\n\t\tlazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}\n\t\t\
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {\n\t\t\tlog = internal::ceil_pow2(_n);\n\
    \t\t\tsize = 1 << log;\n\t\t\td = std::vector<S>(2 * size, e());\n\t\t\tlz = std::vector<F>(size,\
    \ id());\n\t\t\tfor (int i = 0; i < _n; i++) d[size + i] = v[i];\n\t\t\tfor (int\
    \ i = size - 1; i >= 1; i--) {\n\t\t\t\tupdate(i);\n\t\t\t}\n\t\t}\n\n\t\tvoid\
    \ set(int p, S x) {\n\t\t\tassert(0 <= p && p < _n);\n\t\t\tp += size;\n\t\t\t\
    for (int i = log; i >= 1; i--) push(p >> i);\n\t\t\td[p] = x;\n\t\t\tfor (int\
    \ i = 1; i <= log; i++) update(p >> i);\n\t\t}\n\n\t\tS get(int p) {\n\t\t\tassert(0\
    \ <= p && p < _n);\n\t\t\tp += size;\n\t\t\tfor (int i = log; i >= 1; i--) push(p\
    \ >> i);\n\t\t\treturn d[p];\n\t\t}\n\n\t\tS operator[](int p) {\n\t\t\treturn\
    \ get(p);\n\t\t}\n\n\t\tS prod(int l, int r) {\n\t\t\tassert(0 <= l && l <= r\
    \ && r <= _n);\n\t\t\tif (l == r) return e();\n\n\t\t\tl += size;\n\t\t\tr +=\
    \ size;\n\n\t\t\tfor (int i = log; i >= 1; i--) {\n\t\t\t\tif (((l >> i) << i)\
    \ != l) push(l >> i);\n\t\t\t\tif (((r >> i) << i) != r) push(r >> i);\n\t\t\t\
    }\n\n\t\t\tS sml = e(), smr = e();\n\t\t\twhile (l < r) {\n\t\t\t\tif (l & 1)\
    \ sml = op(sml, d[l++]);\n\t\t\t\tif (r & 1) smr = op(d[--r], smr);\n\t\t\t\t\
    l >>= 1;\n\t\t\t\tr >>= 1;\n\t\t\t}\n\n\t\t\treturn op(sml, smr);\n\t\t}\n\n\t\
    \tS operator()(int l, int r) {\n\t\t\treturn prod(l, r);\n\t\t}\n\n\t\tS all_prod()\
    \ {\n\t\t\treturn d[1];\n\t\t}\n\n\t\tvoid apply(int p, F f) {\n\t\t\tassert(0\
    \ <= p && p < _n);\n\t\t\tp += size;\n\t\t\tfor (int i = log; i >= 1; i--) push(p\
    \ >> i);\n\t\t\td[p] = mapping(f, d[p]);\n\t\t\tfor (int i = 1; i <= log; i++)\
    \ update(p >> i);\n\t\t}\n\t\tvoid apply(int l, int r, F f) {\n\t\t\tassert(0\
    \ <= l && l <= r && r <= _n);\n\t\t\tif (l == r) return;\n\n\t\t\tl += size;\n\
    \t\t\tr += size;\n\n\t\t\tfor (int i = log; i >= 1; i--) {\n\t\t\t\tif (((l >>\
    \ i) << i) != l) push(l >> i);\n\t\t\t\tif (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n\t\t\t}\n\n\t\t\t{\n\t\t\t\tint l2 = l, r2 = r;\n\t\t\t\twhile (l <\
    \ r) {\n\t\t\t\t\tif (l & 1) all_apply(l++, f);\n\t\t\t\t\tif (r & 1) all_apply(--r,\
    \ f);\n\t\t\t\t\tl >>= 1;\n\t\t\t\t\tr >>= 1;\n\t\t\t\t}\n\t\t\t\tl = l2;\n\t\t\
    \t\tr = r2;\n\t\t\t}\n\n\t\t\tfor (int i = 1; i <= log; i++) {\n\t\t\t\tif (((l\
    \ >> i) << i) != l) update(l >> i);\n\t\t\t\tif (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n\t\t\t}\n\t\t}\n\n\t\ttemplate <bool (*g)(S)> int max_right(int\
    \ l) {\n\t\t\treturn max_right(l, [](S x) { return g(x); });\n\t\t}\n\t\ttemplate\
    \ <class G> int max_right(int l, G g) {\n\t\t\tassert(0 <= l && l <= _n);\n\t\t\
    \tassert(g(e()));\n\t\t\tif (l == _n) return _n;\n\t\t\tl += size;\n\t\t\tfor\
    \ (int i = log; i >= 1; i--) push(l >> i);\n\t\t\tS sm = e();\n\t\t\tdo {\n\t\t\
    \t\twhile (l % 2 == 0) l >>= 1;\n\t\t\t\tif (!g(op(sm, d[l]))) {\n\t\t\t\t\twhile\
    \ (l < size) {\n\t\t\t\t\t\tpush(l);\n\t\t\t\t\t\tl = (2 * l);\n\t\t\t\t\t\tif\
    \ (g(op(sm, d[l]))) {\n\t\t\t\t\t\t\tsm = op(sm, d[l]);\n\t\t\t\t\t\t\tl++;\n\t\
    \t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\treturn l - size;\n\t\t\t\t}\n\t\t\t\tsm =\
    \ op(sm, d[l]);\n\t\t\t\tl++;\n\t\t\t} while ((l & -l) != l);\n\t\t\treturn _n;\n\
    \t\t}\n\n\t\ttemplate <bool (*g)(S)> int min_left(int r) {\n\t\t\treturn min_left(r,\
    \ [](S x) { return g(x); });\n\t\t}\n\t\ttemplate <class G> int min_left(int r,\
    \ G g) {\n\t\t\tassert(0 <= r && r <= _n);\n\t\t\tassert(g(e()));\n\t\t\tif (r\
    \ == 0) return 0;\n\t\t\tr += size;\n\t\t\tfor (int i = log; i >= 1; i--) push((r\
    \ - 1) >> i);\n\t\t\tS sm = e();\n\t\t\tdo {\n\t\t\t\tr--;\n\t\t\t\twhile (r >\
    \ 1 && (r % 2)) r >>= 1;\n\t\t\t\tif (!g(op(d[r], sm))) {\n\t\t\t\t\twhile (r\
    \ < size) {\n\t\t\t\t\t\tpush(r);\n\t\t\t\t\t\tr = (2 * r + 1);\n\t\t\t\t\t\t\
    if (g(op(d[r], sm))) {\n\t\t\t\t\t\t\tsm = op(d[r], sm);\n\t\t\t\t\t\t\tr--;\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\treturn r + 1 - size;\n\t\t\t\t}\n\t\t\t\t\
    sm = op(d[r], sm);\n\t\t\t} while ((r & -r) != r);\n\t\t\treturn 0;\n\t\t}\n\n\
    \t\tstd::vector<S> to_a() {\n\t\t\tstd::vector<S> res(_n);\n\t\t\tfor (int i =\
    \ 0; i < _n; ++i) {\n\t\t\t\tres[i] = get(i);\n\t\t\t}\n\t\t\treturn res;\n\t\t\
    }\n\n\tprivate:\n\t\tint _n, size, log;\n\t\tstd::vector<S> d;\n\t\tstd::vector<F>\
    \ lz;\n\n\t\tvoid update(int k) {\n\t\t\td[k] = op(d[2 * k], d[2 * k + 1]);\n\t\
    \t}\n\t\tvoid all_apply(int k, F f) {\n\t\t\td[k] = mapping(f, d[k]);\n\t\t\t\
    if (k < size) lz[k] = composition(f, lz[k]);\n\t\t}\n\t\tvoid push(int k) {\n\t\
    \t\tall_apply(2 * k, lz[k]);\n\t\t\tall_apply(2 * k + 1, lz[k]);\n\t\t\tlz[k]\
    \ = id();\n\t\t}\n\t};\n\n}  // namespace atcoder\n\n\n#line 4 \"DataStructure/LazySegmentTree.cpp\"\
    \n#include <limits>\n\nnamespace internal {\n\ttemplate <class T> struct S_sum\
    \ {\n\t\tT value, size;\n\t\tS_sum(T v, T s = 1) : value(v), size(s) {}\n\t};\n\
    \n\ttemplate <class S> constexpr S constant_min() {\n\t\treturn std::numeric_limits<S>::min();\n\
    \t}\n\ttemplate <class S> constexpr S constant_max() {\n\t\treturn std::numeric_limits<S>::max();\n\
    \t}\n\ttemplate <class S> constexpr S constant_zero() {\n\t\treturn static_cast<S>(0);\n\
    \t}\n\ttemplate <class T> constexpr S_sum<T> constant_zero_sum() {\n\t\treturn\
    \ {0, 0};\n\t}\n\n\ttemplate <class S> constexpr S op_max(S x, S y) {\n\t\treturn\
    \ std::max(x, y);\n\t}\n\ttemplate <class S> constexpr S op_min(S x, S y) {\n\t\
    \treturn std::min(x, y);\n\t}\n\ttemplate <class T> constexpr S_sum<T> op_sum(S_sum<T>\
    \ x, S_sum<T> y) {\n\t\treturn {x.value + y.value, x.size + y.size};\n\t}\n\n\t\
    template <class S, class F> constexpr S mapping_add(F f, S x) {\n\t\treturn f\
    \ + x;\n\t}\n\ttemplate <class T, class F> constexpr S_sum<T> mapping_add_sum(F\
    \ f, S_sum<T> x) {\n\t\treturn {x.value + f * x.size, x.size};\n\t}\n\ttemplate\
    \ <class S, class F> constexpr S mapping_update(F f, S x) {\n\t\treturn f == constant_max<F>()\
    \ ? x : f;\n\t}\n\ttemplate <class T, class F> constexpr S_sum<T> mapping_update_sum(F\
    \ f, S_sum<T> x) {\n\t\tif (f != constant_max<F>()) x.value = f * x.size;\n\t\t\
    return x;\n\t}\n\n\ttemplate <class F> constexpr F composition_add(F f, F g) {\n\
    \t\treturn f + g;\n\t}\n\ttemplate <class F> constexpr F composition_update(F\
    \ f, F g) {\n\t\treturn f == constant_max<F>() ? g : f;\n\t}\n}  // namespace\
    \ internal\n\nusing internal::S_sum;\n\ntemplate <class S, class F>\nusing RangeAddRangeMax\
    \ =\n    atcoder::lazy_segtree<S, internal::op_max<S>, internal::constant_min<S>,\
    \ F,\n                          internal::mapping_add<S, F>, internal::composition_add<F>,\n\
    \                          internal::constant_zero<F>>;\ntemplate <class S, class\
    \ F>\nusing RangeAddRangeMin =\n    atcoder::lazy_segtree<S, internal::op_min<S>,\
    \ internal::constant_max<S>, F,\n                          internal::mapping_add<S,\
    \ F>, internal::composition_add<F>,\n                          internal::constant_zero<F>>;\n\
    template <class T, class F>\nusing RangeAddRangeSum =\n    atcoder::lazy_segtree<internal::S_sum<T>,\
    \ internal::op_sum<T>,\n                          internal::constant_zero_sum<T>,\
    \ F, internal::mapping_add_sum<T, F>,\n                          internal::composition_add<F>,\
    \ internal::constant_zero<F>>;\ntemplate <class S, class F>\nusing RangeUpdateRangeMax\
    \ =\n    atcoder::lazy_segtree<S, internal::op_max<S>, internal::constant_min<S>,\
    \ F,\n                          internal::mapping_update<S, F>, internal::composition_update<F>,\n\
    \                          internal::constant_max<F>>;\ntemplate <class S, class\
    \ F>\nusing RangeUpdateRangeMin =\n    atcoder::lazy_segtree<S, internal::op_min<S>,\
    \ internal::constant_max<S>, F,\n                          internal::mapping_update<S,\
    \ F>, internal::composition_update<F>,\n                          internal::constant_max<F>>;\n\
    template <class T, class F>\nusing RangeUpdateRangeSum =\n    atcoder::lazy_segtree<internal::S_sum<T>,\
    \ internal::op_sum<T>,\n                          internal::constant_zero_sum<T>,\
    \ F,\n                          internal::mapping_update_sum<T, F>, internal::composition_update<F>,\n\
    \                          internal::constant_max<F>>;\n#line 5 \"test/HLD_vertex.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\n\tint n;\n\tcin >> n;\n\tHLD hld(n);\n\t\
    for (int i = 0; i < n - 1; ++i) {\n\t\tint v, u;\n\t\tcin >> v >> u;\n\t\tv--;\n\
    \t\tu--;\n\t\thld.add_edge(v, u);\n\t}\n\thld.build(0);\n\n\tll ans = 0;\n\tRangeAddRangeSum<ll,\
    \ ll> seg(vector<S_sum<ll>>(n, 1));\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\
    \tint a, b;\n\t\tcin >> a >> b;\n\t\ta--;\n\t\tb--;\n\t\thld.each_vertex(a, b,\
    \ [&](int p, int q) {\n\t\t\tans += seg(p, q).value;\n\t\t\tseg.apply(p, q, 1);\n\
    \t\t});\n\t}\n\tcout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/399\"\n#include \"./../Graph/HeavyLightDecomposition.cpp\"\
    \n#include \"./../DataStructure/LazySegmentTree.cpp\"\n#include <iostream>\nusing\
    \ namespace std;\nusing ll = long long;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\n\tint n;\n\tcin >> n;\n\tHLD hld(n);\n\t\
    for (int i = 0; i < n - 1; ++i) {\n\t\tint v, u;\n\t\tcin >> v >> u;\n\t\tv--;\n\
    \t\tu--;\n\t\thld.add_edge(v, u);\n\t}\n\thld.build(0);\n\n\tll ans = 0;\n\tRangeAddRangeSum<ll,\
    \ ll> seg(vector<S_sum<ll>>(n, 1));\n\tint q;\n\tcin >> q;\n\twhile (q--) {\n\t\
    \tint a, b;\n\t\tcin >> a >> b;\n\t\ta--;\n\t\tb--;\n\t\thld.each_vertex(a, b,\
    \ [&](int p, int q) {\n\t\t\tans += seg(p, q).value;\n\t\t\tseg.apply(p, q, 1);\n\
    \t\t});\n\t}\n\tcout << ans << '\\n';\n}"
  dependsOn:
  - Graph/HeavyLightDecomposition.cpp
  - DataStructure/LazySegmentTree.cpp
  - atcoder/lazysegtree.hpp
  - atcoder/internal_bit.hpp
  isVerificationFile: true
  path: test/HLD_vertex.test.cpp
  requiredBy: []
  timestamp: '2021-01-17 16:23:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/HLD_vertex.test.cpp
layout: document
redirect_from:
- /verify/test/HLD_vertex.test.cpp
- /verify/test/HLD_vertex.test.cpp.html
title: test/HLD_vertex.test.cpp
---
