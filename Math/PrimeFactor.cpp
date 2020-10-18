#pragma once
#include <map>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;

template <class T> vector<pair<T, int>> PrimeFactor(T n) {
	assert(2 <= n);
	vector<pair<T, int>> res;
	for (T i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			res.emplace_back(i, 0);
			while (n % i == 0) {
				res.back().second++;
				n /= i;
			}
		}
	}
	if (n != 1) {
		res.emplace_back(n, 1);
	}
	return res;
}
template <class T> map<T, int> PrimeFactor_map(T n) {
	assert(2 <= n);
	map<T, int> res;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i]++;
			n /= i;
		}
	}
	if (n != 1) {
		res[n] = 1;
	}
	return res;
}
template <class T> vector<T> PrimeFactor_vector(T n) {
	assert(2 <= n);
	vector<T> res;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		res.push_back(n);
	}
	return res;
}
