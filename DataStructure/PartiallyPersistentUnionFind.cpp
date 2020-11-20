#pragma once
#include <vector>
#include <utility>
#include <limits>
using namespace std;

class PartiallyPersistentUnionFind {
	vector<int> par_m, rank_m, time_m;
	vector<vector<pair<int, int>>> size_m;
	int now_m;
	static constexpr int INF = numeric_limits<int>::max();

public:
	PartiallyPersistentUnionFind(size_t n)
	    : par_m(n), rank_m(n), time_m(n, INF), size_m(n), now_m(0) {
		for (size_t i = 0; i < n; ++i) {
			par_m[i] = i;
			size_m[i].emplace_back(0, 1);
		}
	}
	int root(int x, int t) const {
		if (t < time_m[x]) {
			return x;
		} else {
			return root(par_m[x], t);
		}
	}
	bool same(int x, int y, int t) const {
		return root(x, t) == root(y, t);
	}
	int size(int x, int t) const {
		x = root(x, t);
		int ok = 0, ng = size_m[x].size();
		while (ng - ok > 1) {
			int mid = (ok + ng) / 2;
			(size_m[x][mid].first <= t ? ok : ng) = mid;
		}
		return size_m[x][ok].second;
	}
	bool unite(int x, int y) {
		now_m++;
		x = root(x, now_m);
		y = root(y, now_m);
		if (x == y) {
			return false;
		}
		if (rank_m[x] < rank_m[y]) {
			swap(x, y);
		}
		size_m[x].emplace_back(now_m, size(x, now_m) + size(y, now_m));
		par_m[y] = x;
		time_m[y] = now_m;
		if (rank_m[x] == rank_m[y]) {
			rank_m[x]++;
		}
		return true;
	}
};
