#pragma once
#include <vector>
#include <stack>
#include <algorithm>
#include <optional>

std::optional<std::vector<int>> CycleDetectionEdge(
    int n, const std::vector<std::pair<int, int>>& edges, bool directed = true) {
	std::vector<std::vector<std::pair<int, int>>> graph(n);
	for (std::size_t i = 0; i < edges.size(); ++i) {
		auto [u, v] = edges[i];
		graph[u].emplace_back(v, i);
		if (!directed) graph[v].emplace_back(u, i);
	}
	std::vector<bool> visited(n), finished(n);
	std::stack<std::pair<int, int>> st;
	std::optional<int> pos;
	auto dfs = [&](auto&& f, int v, int prev_edge) -> void {
		visited[v] = true;
		for (auto [u, i] : graph[v]) {
			if (!finished[u] && (directed || i != prev_edge)) {
				st.emplace(i, v);
				if (visited[u]) {
					pos = u;
					return;
				}
				f(f, u, i);
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
		std::vector<int> cycle;
		while (!st.empty()) {
			auto [top, from] = st.top();
			st.pop();
			cycle.push_back(top);
			if (from == *pos) {
				break;
			}
		}
		std::reverse(cycle.begin(), cycle.end());
		return cycle;
	} else {
		return std::nullopt;
	}
}

std::optional<std::vector<int>> CycleDetectionVertex(
    const std::vector<std::vector<int>>& graph, bool directed = true) {
	int n = graph.size();
	std::vector<bool> visited(n), finished(n);
	std::stack<int> st;
	std::optional<int> pos;
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
		std::vector<int> cycle;
		while (!st.empty()) {
			int top = st.top();
			st.pop();
			cycle.push_back(top);
			if (top == *pos) {
				break;
			}
		}
		std::reverse(cycle.begin(), cycle.end());
		return cycle;
	} else {
		return std::nullopt;
	}
}

auto CycleDetectionVertex(int n, const std::vector<std::pair<int, int>>& edges,
                          bool directed = true) {
	std::vector<std::vector<int>> graph(n);
	for (auto [u, v] : edges) {
		graph[u].push_back(v);
		if (!directed) graph[v].push_back(u);
	}
	return CycleDetectionVertex(graph, directed);
}
