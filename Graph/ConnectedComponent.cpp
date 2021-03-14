#pragma once
#include <vector>
#include <tuple>

auto ConnectedComponent(const std::vector<std::vector<int>>& graph) {
	int n = graph.size(), count_components = 0;
	std::vector<int> id(n, -1);
	std::vector<std::vector<int>> groups(n);
	auto dfs = [&](auto&& f, int ID, int v) -> void {
		id[v] = ID;
		groups[ID].push_back(v);
		for (int u : graph[v]) {
			if (id[u] == -1) f(f, ID, u);
		}
	};
	for (int i = 0; i < n; ++i) {
		if (id[i] == -1) dfs(dfs, count_components++, i);
	}
	groups.resize(count_components);
	return std::tuple(count_components, id, groups);
}
