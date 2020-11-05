#pragma once
#include <vector>
#include <utility>
using namespace std;

class LowLink {
	size_t n;
	vector<vector<int>> graph;
	vector<bool> visited;
	vector<int> ord, low, articulation_points;
	vector<pair<int, int>> bridges;
	int k;

	void dfs(int v, int parent) {
		visited[v] = true;
		ord[v] = k++;
		low[v] = ord[v];
		int count = 0;
		bool is_articultion_point = false;
		for (int u : graph[v]) {
			if (!visited[u]) {
				count++;
				dfs(u, v);
				low[v] = min(low[v], low[u]);
				if (parent != -1 && ord[v] <= low[u]) {
					is_articultion_point = true;
				}
				if (ord[v] < low[u]) {
					bridges.emplace_back(min(v, u), max(v, u));
				}
			} else if (u != parent) {
				low[v] = min(low[v], ord[u]);
			}
		}
		if (is_articultion_point || (parent == -1 && count > 1)) {
			articulation_points.push_back(v);
		}
	}

public:
	LowLink(size_t _n) : n(_n), graph(_n) {}
	LowLink(const vector<vector<int>>& _graph) : n(_graph.size()), graph(_graph) {}
	void add_edge(int u, int v) {
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	pair<vector<int>, vector<pair<int, int>>> build() {
		visited.assign(n, false);
		ord.assign(n, 0);
		low.assign(n, 0);
		articulation_points.clear();
		bridges.clear();
		k = 0;
		for (size_t i = 0; i < n; ++i) {
			if (!visited[i]) dfs(i, -1);
		}
		return {articulation_points, bridges};
	}
};
