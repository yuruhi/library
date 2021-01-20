#pragma once
#include <vector>
using namespace std;

class EulerTourForVertex {
	vector<int> ls_m, rs_m;
	vector<vector<int>> graph;
	int k = 0;
	void dfs(int v, int p) {
		ls_m[v] = k++;
		for (int u : graph[v]) {
			if (u != p) dfs(u, v);
		}
		rs_m[v] = k;
	}

public:
	EulerTourForVertex() {}
	EulerTourForVertex(int n) : ls_m(n), rs_m(n), graph(n) {}
	EulerTourForVertex(const vector<vector<int>>& _graph)
	    : ls_m(_graph.size()), rs_m(_graph.size()), graph(_graph) {}
	void add_edge(int u, int v) {
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	void build(int root) {
		k = 0;
		dfs(root, -1);
	}
	int l(int v) const {
		return ls_m[v];
	}
	int r(int v) const {
		return rs_m[v];
	}
	pair<int, int> get(int v) const {
		return {ls_m[v], rs_m[v]};
	}
	const vector<int>& ls() const {
		return ls_m;
	}
	const vector<int>& rs() const {
		return rs_m;
	}
	template <typename F> void call(int v, F f) {
		f(ls_m[v], rs_m[v]);
	}
};
