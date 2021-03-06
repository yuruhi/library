#pragma once
#include <vector>
using namespace std;

template <class DP> class ReRooting {
	size_t n;
	vector<vector<int>> graph;
	vector<vector<DP>> dp;
	vector<DP> ans;

	DP dfs(int v, int p) {
		DP sum;
		for (size_t i = 0; i < graph[v].size(); ++i) {
			int e = graph[v][i];
			DP& dp_e = dp[v][i];
			if (e != p) {
				dp_e = dfs(e, v);
				sum += dp_e;
			}
		}
		return sum.add_root(v);
	}
	void bfs(int v, int p, const DP& dp_par) {
		for (size_t i = 0; i < graph[v].size(); ++i) {
			if (graph[v][i] == p) {
				dp[v][i] = dp_par;
			}
		}

		vector<DP> dp_left(graph[v].size() + 1);
		for (size_t i = 0; i < graph[v].size(); ++i) {
			dp_left[i + 1] = dp_left[i] + dp[v][i];
		}
		vector<DP> dp_right(graph[v].size() + 1);
		for (int i = graph[v].size() - 1; i >= 0; --i) {
			dp_right[i] = dp_right[i + 1] + dp[v][i];
		}
		ans[v] = dp_left.back().add_root(v);

		for (size_t i = 0; i < graph[v].size(); ++i) {
			int e = graph[v][i];
			if (e != p) {
				bfs(e, v, (dp_left[i] + dp_right[i + 1]).add_root(v));
			}
		}
	}

public:
	ReRooting(size_t _n) : n(_n), graph(n), dp(n), ans(n) {}
	ReRooting(const vector<vector<int>>& _graph)
	    : n(_graph.size()), graph(_graph), dp(n), ans(n) {}
	void add_edge(int v, int u) {
		graph[v].push_back(u);
		graph[u].push_back(v);
	}
	vector<DP> solve() {
		for (size_t i = 0; i < n; ++i) {
			dp[i].assign(graph[i].size(), DP());
		}
		dfs(0, -1);
		bfs(0, -1, DP());
		return ans;
	}
};

/*
struct DP {
    int dp;
    DP(int _dp = 1) : dp(_dp) {}
    DP operator+(const DP& d) const {
        return DP(*this) += d;
    }
    DP& operator+=(const DP& d) {
        return *this;
    }
    DP add_root([[maybe_unused]] int v) const {
        DP res = *this;

        return res;
    }
};
*/
