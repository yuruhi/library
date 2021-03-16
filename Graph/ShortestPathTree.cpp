#pragma once
#include "./GraphTemplate.cpp"
#include <vector>

std::vector<int> ShortestPathTree(const UnWeightedGraph& graph, int s) {
	std::vector<int> dist(graph.size());
	auto dfs = [&](auto&& f, int v, int p, int depth) -> void {
		dist[v] = depth;
		for (int e : graph[v]) {
			if (e != p) {
				f(f, e, v, depth + 1);
			}
		}
	};
	dfs(dfs, s, -1, 0);
	return dist;
}
std::vector<Weight> ShortestPathTree(const Graph& graph, int s) {
	std::vector<Weight> dist(graph.size());
	auto dfs = [&](auto&& f, int v, int p, Weight depth) -> void {
		dist[v] = depth;
		for (auto e : graph[v]) {
			if (e.to != p) {
				f(f, e.to, v, depth + e.cost);
			}
		}
	};
	dfs(dfs, s, -1, 0);
	return dist;
}
