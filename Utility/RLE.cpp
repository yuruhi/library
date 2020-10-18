#pragma once
#include <vector>
#include <utility>
using namespace std;

template <class T, class U = typename T::value_type> auto RLE(const T& a) {
	int n = a.size();
	vector<int> res1;
	vector<U> res2;
	for (int i = 0; i < n;) {
		int cnt = 0;
		auto e = a[i];
		for (; i < n && a[i] == e; ++i)
			++cnt;
		res1.push_back(cnt);
		res2.push_back(e);
	}
	return make_pair(res1, res2);
}
