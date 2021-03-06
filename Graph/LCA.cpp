#pragma once
#include "./GraphTemplate.cpp"
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

class LCA {
	const int n, LOG;
	vector<int> dist;
	vector<vector<int>> table;
	void dfs(const Graph& graph, int v, int p, int d) {
		table[0][v] = p;
		dist[v] = d;
		for (auto e : graph[v])
			if (e.to != p) {
				dfs(graph, e.to, v, d + 1);
			}
	}

public:
	LCA(const Graph& graph, const int root)
	    : n(graph.size()), LOG(log2(n) + 1), dist(n), table(LOG, vector<int>(n)) {
		dfs(graph, root, -1, 0);
		for (int k = 0; k + 1 < LOG; ++k) {
			for (int v = 0; v < n; ++v) {
				if (table[k][v] < 0) {
					table[k + 1][v] = -1;
				} else {
					table[k + 1][v] = table[k][table[k][v]];
				}
			}
		}
	}
	int operator()(int u, int v) {
		if (dist[u] > dist[v]) swap(u, v);
		for (int k = 0; k < LOG; ++k) {
			if ((dist[v] - dist[u]) >> k & 1) {
				v = table[k][v];
			}
		}
		if (u == v) return u;
		for (int k = LOG - 1; k >= 0; --k) {
			if (table[k][u] != table[k][v]) {
				u = table[k][u];
				v = table[k][v];
			}
		}
		return table[0][u];
	}
};
