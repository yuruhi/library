#pragma once
#include <vector>
#include <tuple>
using namespace std;

tuple<int, vector<int>, vector<vector<int>>> ConnectedComponent(const vector<vector<int>>& g) {
	int V = g.size(), N = 0;
	vector<int> id(V, -1);
	vector<vector<int>> ind(V);
	auto dfs = [&](auto&& f, int ID, int v) -> void {
		id[v] = ID;
		ind[ID].push_back(v);
		for (auto e : g[v])
			if (id[e] == -1) f(f, ID, e);
	};
	for (int i = 0; i < V; ++i)
		if (id[i] == -1) dfs(dfs, N++, i);
	ind.resize(N);
	return make_tuple(N, id, ind);
}
