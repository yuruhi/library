#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <queue>
using namespace std;

vector<Weight> Dijkstra(const Graph& graph, int s) {
	int V = graph.size();
	vector<Weight> dist(V, INF);
	dist[s] = 0;
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
			}
		}
	}
	return dist;
}