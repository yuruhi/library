#pragma once
#include <vector>
using namespace std;

class EulerTourForVertex {
	vector<int> ls, rs;
	vector<vector<int>> graph;
	int k = 0;
	void dfs(int v, int p) {
		ls[v] = k++;
		for (int u : graph[v]) {
			if (u != p) dfs(u, v);
		}
		rs[v] = k;
	}

public:
	EulerTourForVertex() {}
	EulerTourForVertex(int n) : ls(n), rs(n), graph(n) {}
	void add_edge(int u, int v) {
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	void build(int root) {
		k = 0;
		dfs(root, -1);
	}
	int get_l(int v) const {
		return ls[v];
	}
	int get_r(int v) const {
		return rs[v];
	}
	pair<int, int> get(int v) const {
		return {ls[v], rs[v]};
	}
	const vector<int>& get_ls() const {
		return ls;
	}
	const vector<int>& get_rs() const {
		return rs;
	}
	template <typename F> void call(int v, F f) {
		f(ls[v], rs[v]);
	}
};
