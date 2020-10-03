// description : Matching on Bipartite Graph
class BipartiteMatching {
	size_t left, right;
	vector<vector<int>> graph;
	vector<bool> used;
	vector<int> left_match, right_match;
	bool dfs(int v) {
		if (used[v]) {
			return false;
		}
		used[v] = true;
		for (int u : graph[v]) {
			if (right_match[u] == -1 || dfs(right_match[u])) {
				left_match[v] = u;
				right_match[u] = v;
				return true;
			}
		}
		return false;
	}

public:
	BipartiteMatching(size_t _left, size_t _right)
	    : left(_left), right(_right), graph(left), used(left), left_match(left), right_match(right) {}
	BipartiteMatching(size_t _left, size_t _right, const vector<vector<int>>& _graph)
	    : left(_left), right(_right), graph(_graph), used(left), left_match(left), right_match(right) {
		assert(graph.size() == left);
	}
	void add_edge(int l, int r) {
		graph[l].push_back(r);
	}
	int solve() {
		int res = 0;
		fill(left_match.begin(), left_match.end(), -1);
		fill(right_match.begin(), right_match.end(), -1);
		fill(used.begin(), used.end(), false);
		for (bool update = true; update;) {
			update = false;
			for (size_t i = 0; i < left; ++i) {
				if (left_match[i] == -1 && dfs(i)) {
					update = true;
					++res;
				}
			}
			if (update) {
				fill(used.begin(), used.end(), false);
			}
		}
		return res;
	}
	vector<pair<int, int>> edges() const {
		vector<pair<int, int>> res;
		for (size_t i = 0; i < left; ++i) {
			if (left_match[i] != -1) {
				res.emplace_back(i, left_match[i]);
			}
		}
		return res;
	}
};