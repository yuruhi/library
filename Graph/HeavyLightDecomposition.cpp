#pragma once
#include <vector>
using namespace std;

class HLD {
	int n;
	vector<vector<int>> graph;
	vector<int> parent, size, depth;
	int k;
	vector<int> head, hld, index;

	int calc_size(int v, int p, int d) {
		parent[v] = p;
		size[v] = 1;
		depth[v] = 1;
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
		if (heavy_vertex == -1) return;
		rec(heavy_vertex, v, root);
		for (int u : graph[v]) {
			if (u != heavy_vertex && u != p) {
				rec(u, v, u);
			}
		}
	}

public:
	HLD(int _n) : n(_n), graph(_n) {}
	HLD(const vector<vector<int>>& _graph) : n(_graph.size()), graph(_graph) {}
	void add_edge(int u, int v) {
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	void build(int root) {
		parent.assign(n, -1);
		size.assign(n, 0);
		depth.assign(n, 0);
		calc_size(root, -1, 1);
		k = 0;
		head.assign(n, 0);
		hld.assign(n, 0);
		index.assign(n, 0);
		rec(root, -1, root);
	}
	const vector<int>& get_head() const {
		return head;
	}
	const vector<int>& get_hld() const {
		return hld;
	}
	const vector<int>& get_index() const {
		return index;
	}

	template <class F> void each_vertex(int v, int u, F f) const {
		while (true) {
			if (index[v] > index[u]) swap(v, u);
			if (head[v] != head[u]) {
				f(index[head[u]], index[u]);
				u = parent[head[u]];
			} else {
				f(index[v], index[u]);
				break;
			}
		}
	}
	template <class F> void each_edge(int v, int u, F f) const {
		while (true) {
			if (index[v] > index[u]) swap(v, u);
			if (head[v] != head[u]) {
				f(index[head[u]], index[u]);
				u = parent[head[u]];
			} else {
				if (v != u) f(index[v] + 1, index[u]);
				break;
			}
		}
	}
	vector<pair<int, int>> query_vertex(int u, int v) {
		vector<pair<int, int>> result;
		each_vertex(u, v, [&](int a, int b) { result.emplace_back(a, b); });
		return result;
	}
	vector<pair<int, int>> query_edge(int u, int v) {
		vector<pair<int, int>> result;
		each_edge(u, v, [&](int a, int b) { result.emplace_back(a, b); });
		return result;
	}
};
