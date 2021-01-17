#pragma once
#include <vector>
#include <cassert>
using namespace std;

class HLD {
	int n;
	vector<vector<int>> graph;
	vector<int> parent, size;
	int k;
	vector<int> head, hld, index, out_index;
	bool builded = false;

	int calc_size(int v, int p, int d) {
		parent[v] = p;
		size[v] = 1;
		for (int u : graph[v]) {
			if (u != p) {
				size[v] += calc_size(u, v, d + 1);
			}
		}
		return size[v];
	}
	void rec(int v, int p, int root) {
		head[v] = root;
		index[v] = k;
		hld[k++] = v;

		int heavy_vertex = -1, max_size = 0;
		for (int u : graph[v]) {
			if (u != p && max_size < size[u]) {
				max_size = size[u];
				heavy_vertex = u;
			}
		}
		if (heavy_vertex != -1) {
			rec(heavy_vertex, v, root);
			for (int u : graph[v]) {
				if (u != heavy_vertex && u != p) {
					rec(u, v, u);
				}
			}
		}
		out_index[v] = k;
	}

public:
	HLD(int _n) : n(_n), graph(_n) {}
	HLD(const vector<vector<int>>& _graph) : n(_graph.size()), graph(_graph) {}
	void add_edge(int u, int v) {
		graph[u].push_back(v);
		graph[v].push_back(u);
		builded = false;
	}
	void build(int root) {
		parent.assign(n, -1);
		size.assign(n, 0);
		calc_size(root, -1, 1);
		k = 0;
		head.assign(n, 0);
		hld.assign(n, 0);
		index.assign(n, 0);
		out_index.assign(n, 0);
		rec(root, -1, root);
		builded = true;
	}
	const vector<vector<int>>& get_graph() const {
		assert(builded);
		return graph;
	}
	const vector<int>& get_parent() const {
		assert(builded);
		return parent;
	}
	const vector<int>& get_size() const {
		assert(builded);
		return size;
	}
	const vector<int>& get_head() const {
		assert(builded);
		return head;
	}
	const vector<int>& get_hld() const {
		assert(builded);
		return hld;
	}
	const vector<int>& get_index() const {
		assert(builded);
		return index;
	}
	const vector<int>& get_out_index() const {
		assert(builded);
		return out_index;
	}
	int operator[](int v) const {
		assert(builded);
		return index[v];
	}

	template <class F> void each_vertex(int v, int u, F f) const {
		assert(builded);
		while (true) {
			if (index[v] > index[u]) swap(v, u);
			if (head[v] != head[u]) {
				f(index[head[u]], index[u] + 1);
				u = parent[head[u]];
			} else {
				f(index[v], index[u] + 1);
				break;
			}
		}
	}
	template <class F> void each_subtree_vertex(int v, F f) const {
		assert(builded);
		f(index[v], out_index[v]);
	}
	template <class F> void each_edge(int v, int u, F f) const {
		assert(builded);
		while (true) {
			if (index[v] > index[u]) swap(v, u);
			if (head[v] != head[u]) {
				f(index[head[u]], index[u] + 1);
				u = parent[head[u]];
			} else {
				if (v != u) f(index[v] + 1, index[u] + 1);
				break;
			}
		}
	}
	template <class F> void each_subtree_edge(int v, F f) const {
		assert(builded);
		f(index[v] + 1, out_index[v]);
	}
	vector<pair<int, int>> query_vertex(int u, int v) const {
		assert(builded);
		vector<pair<int, int>> result;
		each_vertex(u, v, [&](int a, int b) { result.emplace_back(a, b); });
		return result;
	}
	pair<int, int> query_subtree_vertex(int v) const {
		assert(builded);
		pair<int, int> result;
		each_subtree_vertex(v, [&](int a, int b) { result = {a, b}; });
		return result;
	}
	vector<pair<int, int>> query_edge(int u, int v) const {
		assert(builded);
		vector<pair<int, int>> result;
		each_edge(u, v, [&](int a, int b) { result.emplace_back(a, b); });
		return result;
	}
	pair<int, int> query_subtree_edge(int v) const {
		assert(builded);
		pair<int, int> result;
		each_subtree_edge(v, [&](int a, int b) { result = {a, b}; });
		return result;
	}
	int lca(int u, int v) const {
		while (true) {
			if (index[u] > index[v]) swap(u, v);
			if (head[u] != head[v]) {
				v = parent[head[v]];
			} else {
				return u;
			}
		}
	}
};
