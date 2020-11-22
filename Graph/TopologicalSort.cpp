#pragma once
#include <vector>
#include <algorithm>
using namespace std;

vector<int> TopologicalSort(const vector<vector<int>>& graph) {
	size_t n = graph.size();
	vector<bool> visited(n);
	vector<int> res;
	auto dfs = [&](auto self, size_t v) {
		if (visited[v]) return;
		visited[v] = true;
		for (size_t i : graph[v]) dfs(i);
		res.push_back(v);
	};
	for (size_t i = 0; i < n; i++) dfs(i);
	reverse(res.begin(), res.end());
	return res;
}
