#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
using namespace std;

pair<bool, vector<Weight>> BellmanFord(const Graph& graph, int s) {
	int V = graph.size();
	vector<Weight> dist(V, INF);
	dist[s] = 0;
	for (int i = 0; i < V; ++i)
		for (int v = 0; v < V; ++v)
			for (auto e : graph[v]) {
				if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					if (i == V - 1) return {true, dist};
				}
			}
	return {false, dist};
}