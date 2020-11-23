#pragma once
#include "./FlowTemplate.cpp"
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Dinic {
	int V;
	GraphF graph;
	vector<int> level, iter;
	void bfs(int s) {
		fill(level.begin(), level.end(), -1);
		level[s] = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto& e : graph[v]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}
	FLOW dfs(int v, int t, FLOW f) {
		if (v == t) return f;
		for (int i = iter[v]; i < graph[v].size(); ++i) {
			auto& e = graph[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
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
	Dinic(int v) : V(v), graph(v), level(v), iter(v) {}
	const GraphF& get_graph() {
		return graph;
	}
	void add_edge(int from, int to, FLOW cap) {
		graph[from].emplace_back(to, graph[to].size(), cap);
		graph[to].emplace_back(from, graph[from].size() - 1, 0);
	}
	FLOW solve(int s, int t) {
		FLOW result = 0;
		while (true) {
			bfs(s);
			if (level[t] < 0) return result;
			fill(iter.begin(), iter.end(), 0);
			FLOW f;
			while ((f = dfs(s, t, INF_FLOW)) > 0) result += f;
		}
	}
};
