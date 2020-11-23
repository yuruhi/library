#pragma once
#include "./FlowTemplate.cpp"
#include <vector>
using namespace std;

class FordFulkerson {
	int n;
	GraphF graph;
	vector<bool> used;
	FLOW dfs(int v, int t, FLOW f) {
		if (v == t) return f;
		used[v] = true;
		for (auto& e : graph[v]) {
			if (!used[e.to] && e.cap > 0) {
				FLOW d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					graph[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

public:
	FordFulkerson(int _n) : n(_n), graph(n), used(n) {}
	const GraphF& get_G() {
		return graph;
	}
	void add_edge(int from, int to, FLOW cap) {
		graph[from].emplace_back(to, graph[to].size(), cap);
		graph[to].emplace_back(from, graph[from].size() - 1, 0);
	}
	FLOW solve(int s, int t) {
		FLOW result = 0;
		while (true) {
			fill(used.begin(), used.end(), false);
			FLOW f = dfs(s, t, INF_FLOW);
			if (!f) return result;
			result += f;
		}
	}
};
