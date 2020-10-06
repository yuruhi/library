#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
using namespace std;

vector<Weight> ShortestPathTree(const Graph& g, int s) {
	int V = g.size();
	vector<Weight> dist(V);
	auto dfs = [&](auto&& f, int v, int p, Weight depth) -> void {
		dist[v] = depth;
		for (auto e : g[v]) {
			if (e.to != p) {
				f(f, e.to, v, depth + e.cost);
			}
		}
	};
	dfs(dfs, s, -1, 0);
	return dist;
}