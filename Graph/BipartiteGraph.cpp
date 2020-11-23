#pragma once
#include <vector>
#include <tuple>
using namespace std;

tuple<bool, vector<bool>> BipartiteGraph(const vector<vector<int>>& graph) {
	int n = graph.size();
	vector<int> a(n);
	auto dfs = [&](auto&& f, int v, int color) -> bool {
		a[v] = color;
		for (int u : graph[v]) {
			if (a[u] == color || (a[u] == 0 && !f(f, u, color * -1))) {
				return false;
			}
		}
		return true;
	};
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0 && !dfs(dfs, 0, 1)) {
			return {false, vector<bool>()};
		}
	}
	vector<bool> result(n);
	for (int i = 0; i < n; ++i) {
		result[i] = a[i] == 1;
	}
	return {true, result};
}
