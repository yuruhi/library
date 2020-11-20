#pragma once
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <optional>
using namespace std;

pair<bool, vector<int>> CycleDetectionEdge(int n, const vector<pair<int, int>>& edges,
                                           bool directed = true) {
	vector<vector<pair<int, int>>> graph(n);
	for (size_t i = 0; i < edges.size(); ++i) {
		auto [u, v] = edges[i];
		graph[u].emplace_back(v, i);
		if (!directed) graph[v].emplace_back(u, i);
	}
	vector<bool> visited(n), finished(n);
	stack<pair<int, int>> st;
	optional<int> pos;
	auto dfs = [&](auto&& f, int v, int prev) -> void {
		visited[v] = true;
		for (auto [u, i] : graph[v]) {
			if (!finished[u] && (directed || u != prev)) {
				st.emplace(i, v);
				if (visited[u]) {
					pos = u;
					return;
				}
				f(f, u, v);
				if (pos) return;
				st.pop();
			}
		}
		finished[v] = true;
	};
	for (int i = 0; i < n && !pos; ++i) {
		if (!visited[i]) dfs(dfs, i, -1);
	}

	if (pos) {
		vector<int> cycle;
		while (!st.empty()) {
			auto [top, from] = st.top();
			st.pop();
			cycle.push_back(top);
			if (from == *pos) {
				break;
			}
		}
		reverse(cycle.begin(), cycle.end());
		return {true, cycle};
	} else {
		return {false, {}};
	}
}

pair<bool, vector<int>> CycleDetectionVertex(int n, const vector<pair<int, int>>& edges,
                                             bool directed = true) {
	vector<vector<int>> graph(n);
	for (auto [u, v] : edges) {
		graph[u].push_back(v);
		if (!directed) graph[v].push_back(u);
	}
	vector<bool> visited(n), finished(n);
	stack<int> st;
	optional<int> pos;
	auto dfs = [&](auto&& f, int v, int prev) -> void {
		visited[v] = true;
		st.push(v);
		for (int u : graph[v]) {
			if (!finished[u] && (directed || u != prev)) {
				if (visited[u]) {
					pos = u;
					return;
				}
				f(f, u, v);
				if (pos) return;
			}
		}
		finished[v] = true;
		st.pop();
	};
	for (int i = 0; i < n && !pos; ++i) {
		if (!visited[i]) dfs(dfs, i, -1);
	}

	if (pos) {
		vector<int> cycle;
		while (!st.empty()) {
			int top = st.top();
			st.pop();
			cycle.push_back(top);
			if (top == *pos) {
				break;
			}
		}
		reverse(cycle.begin(), cycle.end());
		return {true, cycle};
	} else {
		return {false, {}};
	}
}