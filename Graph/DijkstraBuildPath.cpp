#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>

auto DijkstraBuildPrev(const Graph& graph, int s) {
	std::size_t n = graph.size();
	std::vector<Weight> dist(n, INF);
	dist[s] = 0;
	std::vector<int> prev(n, -1);
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
				prev[e.to] = v;
			}
		}
	}
	return std::pair(dist, prev);
}
std::vector<int> BuildPath(const std::vector<int>& prev, int t) {
	std::vector<int> result;
	while (prev[t] != -1) {
		result.push_back(t);
		t = prev[t];
	}
	result.push_back(t);
	std::reverse(result.begin(), result.end());
	return result;
}
