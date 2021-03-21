#pragma once
#include "./GraphTemplate.cpp"
#include "./../DataStructure/UnionFind.cpp"
#include <algorithm>

Weight Kruskal(int V, Edges& graph) {
	std::sort(graph.begin(), graph.end(),
	          [](const Edge2& e1, const Edge2& e2) { return e1.cost < e2.cost; });
	Weight result = 0;
	UnionFind uf(V);
	for (auto e : graph) {
		if (uf.unite(e.from, e.to)) {
			result += e.cost;
		}
	}
	return result;
}
