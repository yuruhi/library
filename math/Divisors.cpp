#pragma once
#include <vector>
#include <cmath>
#include <cassert>

template <class T> std::vector<T> Divisors(T n) {
	assert(0 < n);
	std::vector<T> result;
	T i = 1;
	for (; i * i < n; ++i) {
		if (n % i == 0) result.push_back(i);
	}
	bool flag = i * i == n;
	if (flag) result.push_back(i);
	for (i = (int)result.size() - 1 - flag; i >= 0; --i) {
		result.push_back(n / result[i]);
	}
	return result;
}
template <class T> int DivisorsCount(T n) {
	assert(0 < n);
	int cnt = 0;
	T sq = std::sqrt(n);
	for (T i = 1; i <= sq; ++i) {
		cnt += n % i == 0;
	}
	return cnt * 2 - (sq * sq == n);
}
template <class T> T DivisorsSum(T n) {
	assert(0 < n);
	T i = 1, result = 0;
	for (; i * i < n; ++i) {
		if (n % i == 0) result += i + n / i;
	}
	return result + i * (i * i == n);
}
