#pragma once
#include <vector>
#include <utility>
using namespace std;

class UnionFind {
	vector<int> per_m;
	int count_components_m;

public:
	UnionFind(int n = 0) {
		init(n);
	}
	void init(int n) {
		per_m.assign(n, -1);
		count_components_m = n;
	}
	int root(int x) {
		return per_m[x] < 0 ? x : per_m[x] = root(per_m[x]);
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (per_m[x] > per_m[y]) {
			swap(x, y);
		}
		per_m[x] += per_m[y];
		per_m[y] = x;
		count_components_m--;
		return true;
	}
	int size(int x) {
		return -per_m[root(x)];
	}
	int count_components() const {
		return count_components_m;
	}
};
