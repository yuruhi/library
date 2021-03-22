#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <functional>

std::tuple<Weight, std::vector<int>> DiameterPath(const Graph& graph) {
	int n = graph.size();
	std::vector<Weight> dist0(n);
	auto dfs = [&](auto self, int v, int p, Weight d) -> void {
		dist0[v] = d;
		for (const auto& u : graph[v])
			if (u.to != p) {
				self(self, u.to, v, d + u.cost);
			}
	};
	dfs(dfs, 0, -1, 0);

	int s = std::max_element(dist0.begin(), dist0.end()) - dist0.begin();
	std::vector<Weight> dist(n);
	std::vector<int> par(n);
	auto dfs2 = [&](auto self, int v, int p, Weight d) -> void {
		dist[v] = d;
		par[v] = p;
		for (const auto& u : graph[v]) {
			if (u.to != p) {
				self(self, u.to, v, d + u.cost);
			}
		}
	};
	dfs2(dfs2, s, -1, 0);
	auto t = std::max_element(dist.begin(), dist.end());
	std::vector<int> path{static_cast<int>(t - dist.begin())};
	for (int p = 0; (p = par[path.back()]) != -1;) {
		path.push_back(p);
	}
	std::reverse(path.begin(), path.end());
	return {*t, path};
}
