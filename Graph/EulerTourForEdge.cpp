#pragma once
#include <vector>
#include <utility>
#include <cassert>
#include <functional>
using namespace std;

class EulerTourForEdge {
	vector<vector<int>> graph;
	vector<int> ls, rs;
	int pos = 0;
	bool flag = false;
	void dfs(int v, int p = -1) {
		ls[v] = pos++;
		for (int u : graph[v])
			if (u != p) {
				dfs(u, v);
			}
		rs[v] = pos++;
	}

public:
	EulerTourForEdge(int n) : graph(n), ls(n), rs(n) {}
	EulerTourForEdge(const vector<vector<int>>& _graph) : graph(_graph), ls(graph.size()), rs(graph.size()) {}
	void add_edge(int u, int v) {
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	void build(int root = 0) {
		flag = true;
		pos = 0;
		dfs(root);
	}
	int size() const {
		assert(flag);
		return pos;
	}
	int l(int i) const {
		assert(flag);
		return ls[i];
	}
	int r(int i) const {
		assert(flag);
		return rs[i];
	}
	pair<int, int> operator()(int i) {
		assert(flag);
		return make_pair(ls[i], rs[i]);
	}
	const vector<int>& get_ls() const {
		return ls;
	}
	const vector<int>& get_rs() const {
		return rs;
	}
	int operator[](int i) {
		assert(flag);
		return ls[i];
	}
	template <class T> auto call(int v, function<T(int, int)>&& f) {
		assert(flag);
		return f(ls[v], rs[v]);
	}
};
