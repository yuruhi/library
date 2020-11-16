#pragma once
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

template <class T> int LIS(const vector<T>& a) {
	constexpr T INF = numeric_limits<T>::max();
	int n = a.size();
	vector<T> dp(n, INF);
	for (auto num : a) {
		*lower_bound(dp.begin(), dp.end(), num) = num;
	}
	return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
