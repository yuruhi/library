#pragma once
#include <vector>
#include <utility>

template <class T> class WeightedUnionFind {
public:
	using value_type = T;

private:
	std::vector<int> par_m, rank_m;
	std::vector<value_type> weight_m;

public:
	WeightedUnionFind(std::size_t n) : par_m(n), rank_m(n, 0), weight_m(n, 0) {
		for (std::size_t i = 0; i < n; ++i) par_m[i] = i;
	}
	int root(int x) {
		if (par_m[x] == x) {
			return x;
		} else {
			int r = root(par_m[x]);
			weight_m[x] += weight_m[par_m[x]];
			return par_m[x] = r;
		}
	}
	value_type weight(int x) {
		root(x);
		return weight_m[x];
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool merge(int x, int y, value_type w) {
		w += weight(x);
		w -= weight(y);
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (rank_m[x] < rank_m[y]) {
			swap(x, y);
			w = -w;
		}
		if (rank_m[x] == rank_m[y]) rank_m[x]++;
		par_m[y] = x;
		weight_m[y] = w;
		return true;
	}
	value_type diff(int x, int y) {
		return weight(y) - weight(x);
	}
};
