#pragma once
#include <vector>
#include <utility>

std::vector<int> BuildTreePathEdge(const std::vector<std::vector<std::pair<int, int>>>& graph,
                                   int s, int t) {
	int n = graph.size();
	std::vector par(n, std::pair(-1, -1));
	auto dfs = [&](auto&& f, int v, int p) -> void {
		for (auto [u, i] : graph[v]) {
			if (u != p) {
				par[u] = std::pair(v, i);
				f(f, u, v);
			}
		}
	};
	dfs(dfs, t, -1);
	std::vector<int> result;
	for (int v = s; v != t; v = par[v].first) {
		result.push_back(par[v].second);
	}
	return result;
}
