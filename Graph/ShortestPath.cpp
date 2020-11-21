#pragma once
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> ShortestPath(const vector<vector<int>>& graph, const int s) {
	int V = graph.size();
	vector<int> dist(V, INT_MAX);
	dist[s] = 0;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (auto e : graph[f]) {
			if (dist[e] == INT_MAX) {
				que.push(e);
				dist[e] = dist[f] + 1;
			}
		}
	}
	return dist;
}
