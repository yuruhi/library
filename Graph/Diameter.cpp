// shortcut : Diameter
// description : 木の直径
tuple<Weight, int, int> Diameter(const Graph& g) {
	function<pair<int, int>(int, int, Weight)> dfs = [&](int v, int p, Weight depth) {
		pair<int, int> ret(depth, v);
		for (auto e : g[v])if (e.to != p) {
			auto res = dfs(e.to, v, depth + e.cost);
			if (res.first > ret.first)ret = res;
		}
		return ret;
	};
	auto d1 = dfs(0, -1, 0);
	auto d2 = dfs(d1.second, -1, 0);
	return make_tuple(d2.first, d1.second, d2.second);
}