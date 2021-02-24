#pragma once
#include <vector>
#include <utility>

class UnionFind {
	std::size_t n;
	std::vector<int> data_m;
	int count_components_m;

public:
	UnionFind(int _n = 0) {
		init(_n);
	}
	void init(int _n) {
		n = _n;
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
			std::swap(x, y);
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
	std::vector<int> roots() {
		std::vector<int> result;
		for (std::size_t i = 0; i < n; ++i) {
			if (root(i) == i) result.push_back(i);
		}
		return result;
	}
	std::vector<std::vector<int>> groups() {
		std::vector<int> root_buf(n), group_size(n);
		for (std::size_t i = 0; i < n; i++) {
			root_buf[i] = root(i);
			group_size[root_buf[i]]++;
		}
		std::vector<std::vector<int>> result(n);
		for (std::size_t i = 0; i < n; i++) {
			result[i].reserve(group_size[i]);
		}
		for (std::size_t i = 0; i < n; i++) {
			result[root_buf[i]].push_back(i);
		}
		result.erase(std::remove_if(result.begin(), result.end(),
		                            [&](const std::vector<int>& v) { return v.empty(); }),
		             result.end());
		return result;
	}
};
