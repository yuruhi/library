#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <queue>
using namespace std;

Graph SpanningTree(const Graph& graph, int root) {
	int n = graph.size();
	Graph res(n);
	queue<int> q;
	q.push(root);
	vector<bool> flag(n);
	flag[root] = true;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (const Edge& e : graph[f]) {
			if (!flag[e.to]) {
				res[f].push_back(e);
				flag[e.to] = true;
				q.push(e.to);
			}
		}
	}
	return res;
}
