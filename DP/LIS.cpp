#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template <class T> int LIS(const vector<T>& a, T INF_ = 1e9) {
	int n = a.size();
	vector<T> dp(n, INF_);
	for (auto num : a) {
		*lower_bound(dp.begin(), dp.end(), num) = num;
	}
	return lower_bound(dp.begin(), dp.end(), INF_) - dp.begin();
}