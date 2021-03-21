#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <algorithm>

std::vector<int> BuildPathTree(const Graph& graph, int s, int t) {
	int n = graph.size();
	std::vector<int> par(n);
	auto dfs = [&](auto&& f, int v, int p) -> void {
		for (const auto& u : graph[v]) {
			if (u.to != p) {
				par[u.to] = v;
				f(f, u.to, v);
			}
		}
	};
	dfs(dfs, s, -1);
	std::vector<int> path{t};
	while (path.back() != s) {
		path.push_back(par[path.back()]);
	}
	std::reverse(path.begin(), path.end());
	return path;
}
