#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <algorithm>

std::vector<int> TopologicalSort(const UnWeightedTree& graph) {
	std::size_t n = graph.size();
	std::vector<bool> visited(n);
	std::vector<int> result;
	auto dfs = [&](auto self, std::size_t v) -> void {
		if (visited[v]) return;
		visited[v] = true;
		for (std::size_t i : graph[v]) self(self, i);
		result.push_back(v);
	};
	for (std::size_t i = 0; i < n; i++) dfs(dfs, i);
	std::reverse(result.begin(), result.end());
	return result;
}
