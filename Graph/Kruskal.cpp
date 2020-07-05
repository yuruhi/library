// description : クラスカル法 O(E log V)
Weight Kruskal(int V, Edges &graph) {
	sort(graph.begin(), graph.end(), [](const Edge2 &e1, const Edge2 &e2) { return e1.cost < e2.cost; });
	Weight res = 0;
	UnionFind uf(V);
	for (auto e : graph) {
		if (uf.unite(e.from, e.to)) {
			res += e.cost;
		}
	}
	return res;
}