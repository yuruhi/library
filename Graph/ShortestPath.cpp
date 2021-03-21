#pragma once
#include <vector>
#include <queue>
#include <optional>
#include <limits>

std::vector<int> ShortestPath(const std::vector<std::vector<int>>& graph, int s,
                              int inf = std::numeric_limits<int>::max()) {
	std::vector<int> dist(graph.size(), inf);
	dist[s] = 0;
	std::queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (auto e : graph[f]) {
			if (dist[e] == inf) {
				que.push(e);
				dist[e] = dist[f] + 1;
			}
		}
	}
	return dist;
}
int ShortestPathST(const std::vector<std::vector<int>>& graph, int s, int t,
                   int inf = std::numeric_limits<int>::max()) {
	std::vector<int> dist(graph.size(), inf);
	dist[s] = 0;
	std::queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int v = que.front();
		if (v == t) return dist[t];
		que.pop();
		for (auto u : graph[v]) {
			if (dist[u] == inf) {
				que.push(u);
				dist[u] = dist[v] + 1;
			}
		}
	}
	return dist[t];
}
