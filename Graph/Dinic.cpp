#pragma once
#include "./FlowTemplate.cpp"
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Dinic {
	int V;
	GraphF G;
	vector<int> level, iter;
	void bfs(int s) {
		fill(level.begin(), level.end(), -1);
		level[s] = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto& e : G[v]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}
	FLOW dfs(int v, int t, FLOW f) {
		if (v == t) return f;
		for (int i = iter[v]; i < G[v].size(); ++i) {
			auto& e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				FLOW d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

public:
	Dinic(int v) : V(v), G(v), level(v), iter(v) {}
	const GraphF& get_G() {
		return G;
	}
	void add_edge(int from, int to, FLOW cap) {
		G[from].emplace_back(to, G[to].size(), cap);
		G[to].emplace_back(from, G[from].size() - 1, 0);
	}
	FLOW solve(int s, int t) {
		FLOW res = 0;
		while (true) {
			bfs(s);
			if (level[t] < 0) return res;
			fill(iter.begin(), iter.end(), 0);
			FLOW f;
			while ((f = dfs(s, t, INF_FLOW)) > 0)
				res += f;
		}
	}
};