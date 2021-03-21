#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <queue>

Graph SpanningTree(const Graph& graph, int root) {
	Graph result(graph.size());
	std::queue<int> q;
	q.push(root);
	std::vector<bool> flag(graph.size());
	flag[root] = true;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (const Edge& e : graph[f]) {
			if (!flag[e.to]) {
				result[f].push_back(e);
				flag[e.to] = true;
				q.push(e.to);
			}
		}
	}
	return result;
}
