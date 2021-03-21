#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

class StronglyConnectedComponents {
	int n;
	std::vector<std::vector<int>> graph, rgraph;
	std::vector<bool> used;
	std::vector<int> cmp, vs;
	int k;
	bool builded = false;
	void dfs(int v) {
		used[v] = true;
		for (auto e : graph[v]) {
			if (!used[e]) dfs(e);
		}
		vs.push_back(v);
	}
	void rdfs(int v, int k) {
		used[v] = true;
		cmp[v] = k;
		for (auto e : rgraph[v]) {
			if (!used[e]) rdfs(e, k);
		}
	}

public:
	StronglyConnectedComponents(int _n) : n(_n), graph(n), rgraph(n) {}
	StronglyConnectedComponents(const std::vector<std::vector<int>>& _graph)
	    : n(_graph.size()), graph(_graph), rgraph(n) {
		for (int v = 0; v < n; ++v) {
			for (int u : graph[v]) {
				rgraph[u].push_back(v);
			}
		}
	}
	void add_edge(int s, int t) {
		builded = false;
		graph[s].push_back(t);
		rgraph[t].push_back(s);
	}
	int build() {
		vs.clear();
		used.assign(n, false);
		cmp.assign(n, 0);
		for (int i = 0; i < n; ++i) {
			if (!used[i]) dfs(i);
		}
		k = 0;
		std::fill(used.begin(), used.end(), false);
		for (int i = vs.size() - 1; i >= 0; --i) {
			if (!used[vs[i]]) rdfs(vs[i], k++);
		}
		builded = true;
		return k;
	}
	int operator[](int i) const {
		assert(builded);
		return cmp[i];
	}
	const std::vector<int>& get_cmp() const {
		assert(builded);
		return cmp;
	}
	const std::vector<std::vector<int>>& get_graph() const {
		assert(builded);
		return graph;
	}
	int count_strongly_components() const {
		assert(builded);
		return k;
	}
	std::vector<std::vector<int>> groups() const {
		assert(builded);
		std::vector<std::vector<int>> result(k);
		for (int i = 0; i < n; ++i) {
			result[cmp[i]].push_back(i);
		}
		return result;
	}
	std::vector<std::vector<int>> make_DAG() const {
		assert(builded);
		std::vector<std::vector<int>> result(k);
		for (int i = 0; i < n; ++i) {
			for (auto e : graph[i]) {
				if (cmp[i] != cmp[e]) {
					result[cmp[i]].push_back(cmp[e]);
				}
			}
		}
		for (auto& v : result) {
			std::sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
		}
		return result;
	}
};
