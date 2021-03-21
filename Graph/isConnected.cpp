#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <queue>

bool isConnected(const std::vector<std::vector<int>>& graph, int s, int t) {
	std::size_t n = graph.size();
	std::queue<int> que;
	que.push(s);
	std::vector<bool> vis(n);
	vis[s] = true;
	while (!que.empty()) {
		int fro = que.front();
		que.pop();
		if (fro == t) return true;
		for (int e : graph[fro]) {
			if (!vis[e]) {
				que.push(e);
				vis[e] = true;
			}
		}
	}
	return false;
}
