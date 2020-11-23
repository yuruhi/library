#pragma once
#include <vector>
#include <algorithm>
using namespace std;

vector<int> TopologicalSort(const vector<vector<int>>& graph) {
	size_t n = graph.size();
	vector<bool> visited(n);
	vector<int> result;
	auto dfs = [&](auto self, size_t v) -> void {
		if (visited[v]) return;
		visited[v] = true;
		for (size_t i : graph[v]) self(self, i);
		result.push_back(v);
	};
	for (size_t i = 0; i < n; i++) dfs(dfs, i);
	reverse(result.begin(), result.end());
	return result;
}
