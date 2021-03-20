#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <optional>
#include <tuple>

std::optional<std::vector<bool>> BipartiteGraph(const UnWeightedGraph& graph) {
	std::size_t n = graph.size();
	std::vector<std::optional<bool>> a(n);
	auto dfs = [&](auto&& f, int v, bool color) -> bool {
		a[v] = color;
		for (int u : graph[v]) {
			if (a[u].has_value() ? a[u].value() == color : !f(f, u, !color)) {
				return false;
			}
		}
		return true;
	};
	for (std::size_t i = 0; i < n; ++i) {
		if (!a[i].has_value() && !dfs(dfs, i, 1)) {
			return std::nullopt;
		}
	}
	std::vector<bool> result(n);
	for (std::size_t i = 0; i < n; ++i) {
		result[i] = a[i].value();
	}
	return result;
}
