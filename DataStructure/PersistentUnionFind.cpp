#pragma once
#include <utility>
#include "./PersistentArray.cpp"

class PersistentUnionFind {
	using data_type = PersistentArray<int, 2>;

public:
	data_type data;
	PersistentUnionFind(const data_type& _data) : data(_data) {}

	PersistentUnionFind() = default;
	PersistentUnionFind(int n) : data(vector(n, -1)) {}
	int root(int k) const {
		int p = data[k];
		return p >= 0 ? root(p) : k;
	}
	bool same(int u, int v) const {
		return root(u) == root(v);
	}
	int size(int k) const {
		return -data[root(k)];
	}
	pair<bool, PersistentUnionFind> unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return {false, *this};
		}
		if (data[x] > data[y]) {
			swap(x, y);
		}
		return {true, data.set(x, data[x] + data[y]).set(y, x)};
	}
};
