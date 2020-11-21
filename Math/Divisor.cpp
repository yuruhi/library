#pragma once
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

template <class T> vector<T> Divisors(T n) {
	assert(0 < n);
	vector<T> res;
	T i = 1;
	for (; i * i < n; ++i)
		if (n % i == 0) res.push_back(i);
	bool flag = i * i == n;
	if (flag) res.push_back(i);
	for (i = (int)res.size() - 1 - flag; i >= 0; --i) {
		res.push_back(n / res[i]);
	}
	return res;
}
template <class T> int DivisorsCount(T n) {
	assert(0 < n);
	int cnt = 0;
	T sq = (T)sqrt(n);
	for (T i = 1; i <= sq; ++i) {
		cnt += (n % i == 0);
	}
	return cnt * 2 - (sq * sq == n);
}
template <class T> T DivisorsSum(T n) {
	assert(0 < n);
	T i = 1, res = 0;
	for (; i * i < n; ++i)
		if (n % i == 0) res += i + n / i;
	return res + i * (i * i == n);
}
