#pragma once
#include "./Range.cpp"
#include <vector>
using namespace std;

vector<Range> split(const vector<int>& v) {
	int n = v.size();
	vector<Range> result;
	if (n <= 1) {
		result.emplace_back(0, n - 1);
		return result;
	}
	int x = 0;
	bool flag = v[0] < v[1];
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || !((flag && v[i] < v[i + 1]) || (!flag && v[i] > v[i + 1]))) {
			flag = flag ? false : true;
			result.emplace_back(x, i);
			x = i;
		}
	}
	return result;
}
