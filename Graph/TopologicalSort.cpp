#pragma once
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

vector<int> TopologicalSort(const vector<vector<int>>& graph) {
	int V = graph.size();
	vector<bool> visited(V);
	vector<int> res;
	function<void(int)> dfs = [&](int u) {
		if (visited[u]) return;
		visited[u] = true;
		for (auto& i : graph[u])
			dfs(i);
		res.push_back(u);
	};
	for (int i = 0; i < V; i++)
		dfs(i);
	reverse(res.begin(), res.end());
	return res;
}