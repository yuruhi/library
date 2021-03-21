#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <queue>
#include <functional>
#include <cassert>

std::vector<Weight> Dijkstra(const Graph& graph, int s) {
	assert(0 <= s && s <= static_cast<int>(graph.size()));
	std::vector<Weight> dist(graph.size(), INF);
	dist[s] = 0;
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
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
Weight Dijkstra(const Graph& graph, int s, int t) {
	assert(0 <= s && s <= static_cast<int>(graph.size()));
	assert(0 <= t && t <= static_cast<int>(graph.size()));
	std::vector<Weight> dist(graph.size(), INF);
	dist[s] = 0;
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
	pq.emplace(s, 0);
	while (!pq.empty()) {
		Edge p = pq.top();
		pq.pop();
		int v = p.to;
		if (v == t) return dist[t];
		if (dist[v] < p.cost) continue;
		for (auto e : graph[v]) {
			if (dist[e.to] > dist[v] + e.cost) {
				dist[e.to] = dist[v] + e.cost;
				pq.emplace(e.to, dist[e.to]);
			}
		}
	}
	return dist[t];
}
