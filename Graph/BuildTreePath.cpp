#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <algorithm>
using namespace std;

vector<int> BuildPathTree(const Graph& g, int s, int t) {
	int n = g.size();
	vector<int> par(n);
	auto dfs = [&](auto&& f, int v, int p) -> void {
		for (const auto& u : g[v]) {
			if (u.to != p) {
				par[u.to] = v;
				f(f, u.to, v);
			}
		}
	};
	dfs(dfs, s, -1);
	vector<int> path{t};
	while (path.back() != s) {
		path.push_back(par[path.back()]);
	}
	reverse(path.begin(), path.end());
	return path;
}