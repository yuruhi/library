#pragma once
#include <vector>
#include <utility>
using namespace std;

vector<int> BuildTreePathEdge(const vector<vector<pair<int, int>>>& g, int s, int t) {
	int n = g.size();
	vector<pair<int, int>> par(n, make_pair(-1, -1));
	auto dfs = [&](auto&& f, int v, int p) -> void {
		for (auto [u, i] : g[v]) {
			if (u != p) {
				par[u] = make_pair(v, i);
				f(f, u, v);
			}
		}
	};
	dfs(dfs, t, -1);
	vector<int> res;
	for (int v = s; v != t; v = par[v].first) {
		res.push_back(par[v].second);
	}
	return res;
}