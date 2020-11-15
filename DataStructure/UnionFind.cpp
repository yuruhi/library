#pragma once
#include <vector>
#include <utility>
using namespace std;

class UnionFind {
	vector<int> data_m;
	int count_components_m;

public:
	UnionFind(int n = 0) {
		init(n);
	}
	void init(int n) {
		data_m.assign(n, -1);
		count_components_m = n;
	}
	int root(int x) {
		return data_m[x] < 0 ? x : data_m[x] = root(data_m[x]);
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
		if (data_m[x] > data_m[y]) {
			swap(x, y);
		}
		data_m[x] += data_m[y];
		data_m[y] = x;
		count_components_m--;
		return true;
	}
	int size(int x) {
		return -data_m[root(x)];
	}
	int count_components() const {
		return count_components_m;
	}
};
