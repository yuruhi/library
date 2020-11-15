#pragma once
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <optional>
using namespace std;

pair<bool, vector<int>> CycleDetectionEdge(int n, const vector<pair<int, int>>& edges) {
	vector<vector<pair<int, int>>> graph(n);
	for (size_t i = 0; i < edges.size(); ++i) {
		graph[edges[i].first].emplace_back(edges[i].second, i);
	}
	vector<bool> visited(n), finished(n);
	stack<int> st;
	optional<int> pos;
	auto dfs = [&](auto&& f, int v) -> void {
		visited[v] = true;
		for (auto [u, i] : graph[v]) {
			if (!finished[u]) {
				st.push(i);
				if (visited[u]) {
					pos = u;
					return;
				}
				f(f, u);
				if (pos) return;
				st.pop();
			}
		}
		finished[v] = true;
	};
	for (int i = 0; i < n && !pos; ++i) {
		if (!visited[i]) dfs(dfs, i);
	}

	if (pos) {
		vector<int> cycle;
		while (!st.empty()) {
			int top = st.top();
			st.pop();
			cycle.push_back(top);
			if (edges[top].first == *pos) {
				break;
			}
		}
		reverse(cycle.begin(), cycle.end());
		return {true, cycle};
	} else {
		return {false, {}};
	}
}