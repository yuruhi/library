#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <queue>
using namespace std;

bool isConnected(const vector<vector<int>>& graph, int s, int t) {
	int V = graph.size();
	queue<int> que;
	que.push(s);
	vector<bool> vis(V);
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
