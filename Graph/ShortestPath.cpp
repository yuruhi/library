#pragma once
#include <vector>
#include <queue>
#include <optional>
#include <limits>
using namespace std;

vector<int> ShortestPath(const vector<vector<int>>& graph, int s,
                         int inf = numeric_limits<int>::max()) {
	int V = graph.size();
	vector<int> dist(V, inf);
	dist[s] = 0;
	queue<int> que;
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
int ShortestPathST(const vector<vector<int>>& graph, int s, int t,
                   int inf = numeric_limits<int>::max()) {
	size_t n = graph.size();
	vector<int> dist(n, inf);
	dist[s] = 0;
	queue<int> que;
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
