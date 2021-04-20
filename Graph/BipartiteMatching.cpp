#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>

class BipartiteMatching {
	std::size_t left, right;
	std::vector<std::vector<int>> graph;
	std::vector<bool> used;
	std::vector<int> left_match, right_match;
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
	BipartiteMatching(std::size_t _left, std::size_t _right)
	    : left(_left),
	      right(_right),
	      graph(left),
	      used(left),
	      left_match(left),
	      right_match(right) {}
	BipartiteMatching(std::size_t _left, std::size_t _right,
	                  const std::vector<std::vector<int>>& _graph)
	    : left(_left),
	      right(_right),
	      graph(_graph),
	      used(left),
	      left_match(left),
	      right_match(right) {
		assert(graph.size() == left);
	}
	BipartiteMatching(std::size_t _left, std::size_t _right,
	                  const std::vector<std::pair<int, int>>& edges)
	    : left(_left),
	      right(_right),
	      graph(left),
	      used(left),
	      left_match(left),
	      right_match(right) {
		for (auto [u, v] : edges) {
			graph[u].push_back(v);
		}
	}
	void add_edge(int l, int r) {
		graph[l].push_back(r);
	}
	int solve() {
		int result = 0;
		std::fill(left_match.begin(), left_match.end(), -1);
		std::fill(right_match.begin(), right_match.end(), -1);
		std::fill(used.begin(), used.end(), false);
		for (bool update = true; update;) {
			update = false;
			for (std::size_t i = 0; i < left; ++i) {
				if (left_match[i] == -1 && dfs(i)) {
					update = true;
					++result;
				}
			}
			if (update) {
				std::fill(used.begin(), used.end(), false);
			}
		}
		return result;
	}
	std::vector<std::pair<int, int>> edges() const {
		std::vector<std::pair<int, int>> result;
		for (std::size_t i = 0; i < left; ++i) {
			if (left_match[i] != -1) {
				result.emplace_back(i, left_match[i]);
			}
		}
		return result;
	}
};
