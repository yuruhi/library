#pragma once
#include "./../DataStructure/BinaryIndexedTree.cpp"
#include <vector>

long long Inversion(const std::vector<int>& a, int max_val) {
	long long ans = 0;
	BinaryIndexedTree<int> bit(max_val + 1);
	for (std::size_t i = 0; i < a.size(); ++i) {
		ans += i - bit(a[i]);
		bit.add(a[i], 1);
	}
	return ans;
}
