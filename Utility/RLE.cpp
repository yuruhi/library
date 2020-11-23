#pragma once
#include <vector>
#include <utility>
using namespace std;

template <class T, class U = typename T::value_type> auto RLE(const T& a) {
	size_t n = a.size();
	vector<size_t> count;
	vector<U> value;
	for (size_t i = 0; i < n;) {
		size_t cnt = 0;
		auto val = a[i];
		for (; i < n && a[i] == val; ++i) ++cnt;
		count.push_back(cnt);
		value.push_back(val);
	}
	return make_pair(count, value);
}
