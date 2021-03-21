#pragma once
#include <vector>
#include <algorithm>
#include <limits>

template <class T> int LIS(const std::vector<T>& a) {
	constexpr T INF = std::numeric_limits<T>::max();
	std::vector<T> dp(a.size(), INF);
	for (auto num : a) {
		*std::lower_bound(dp.begin(), dp.end(), num) = num;
	}
	return std::lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
