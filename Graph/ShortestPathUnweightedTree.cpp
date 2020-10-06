#pragma once
#include <vector>
using namespace std;

vector<int> ShortestPathTree(const vector<vector<int>>& g, int s) {
	int V = g.size();
	vector<int> dist(V);
	auto dfs = [&](auto&& f, int v, int p, int depth) -> void {
		dist[v] = depth;
		for (int e : g[v]) {
			if (e != p) {
				f(f, e, v, depth + 1);
			}
		}
	};
	dfs(dfs, s, -1, 0);
	return dist;
}