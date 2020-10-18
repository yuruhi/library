#pragma once
#include <vector>
#include <tuple>
using namespace std;

tuple<bool, vector<bool>> BipartiteGraph(const vector<vector<int>>& g) {
	int n = g.size();
	vector<int> a(n);
	bool flag = true;
	auto dfs = [&](auto&& f, int v, int color) -> bool {
		a[v] = color;
		for (int u : g[v]) {
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
	vector<bool> res(n);
	for (int i = 0; i < n; ++i) {
		res[i] = a[i] == 1;
	}
	return {flag, res};
}
