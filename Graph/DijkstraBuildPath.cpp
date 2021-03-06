#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

pair<vector<Weight>, vector<int>> DijkstraBuildPrev(const Graph& graph, int s) {
	int V = graph.size();
	vector<Weight> dist(V, INF);
	dist[s] = 0;
	vector<int> prev(V, -1);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	pq.emplace(s, 0);
	while (!pq.empty()) {
		Edge p = pq.top();
		pq.pop();
		int v = p.to;
		if (dist[v] < p.cost) continue;
		for (auto e : graph[v]) {
			if (dist[e.to] > dist[v] + e.cost) {
				dist[e.to] = dist[v] + e.cost;
				pq.emplace(e.to, dist[e.to]);
				prev[e.to] = v;
			}
		}
	}
	return {dist, prev};
}
vector<int> BuildPath(const vector<int>& prev, int t) {
	vector<int> result;
	while (prev[t] != -1) {
		result.push_back(t);
		t = prev[t];
	}
	result.push_back(t);
	reverse(result.begin(), result.end());
	return result;
}
