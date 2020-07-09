// description : 全方位木DP
template <class DP> class ReRooting {
	int n;
	vector<vector<int>> g;
	vector<vector<DP>> dp;
	vector<DP> ans;

	DP dfs(int v, int p) {
		DP sum;
		for (size_t i = 0; i < g[v].size(); ++i) {
			int e = g[v][i];
			DP& dp_e = dp[v][i];
			if (e != p) {
				dp_e = dfs(e, v);
				sum += dp_e;
			}
		}
		return sum.add_root();
	}
	void bfs(int v, int p, const DP& dp_par) {
		for (size_t i = 0; i < g[v].size(); ++i) {
			if (g[v][i] == p) {
				dp[v][i] = dp_par;
			}
		}

		vector<DP> dp_left(g[v].size() + 1);
		for (size_t i = 0; i < g[v].size(); ++i) {
			dp_left[i + 1] = dp_left[i] + dp[v][i];
		}
		vector<DP> dp_right(g[v].size() + 1);
		for (int i = g[v].size() - 1; i >= 0; --i) {
			dp_right[i] = dp_right[i + 1] + dp[v][i];
		}
		ans[v] = dp_left.back().add_root();

		for (size_t i = 0; i < g[v].size(); ++i) {
			int e = g[v][i];
			if (e != p) {
				bfs(e, v, (dp_left[i] + dp_right[i + 1]).add_root());
			}
		}
	}

public:
	ReRooting(const vector<vector<int>>& _g) : n(_g.size()), g(_g), dp(n), ans(n) {
		for (int i = 0; i < n; ++i) dp[i].resize(g[i].size());
	}
	vector<DP> solve() {
		dfs(0, -1);
		bfs(0, -1, DP());
		return ans;
	}
};

struct DP {
	int dp;
	DP(int _dp = 1) : dp(_dp) {}
	DP operator+(const DP& d) const {
		return DP(*this) += d;
	}
	DP& operator+=(const DP& d) {
		return *this;
	}
	DP add_root() const {
		DP res = *this;

		return res;
	}
};