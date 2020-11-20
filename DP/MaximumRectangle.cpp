#pragma once
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

template <class T> T MaximumRectangle(const vector<T>& a) {
	int n = a.size();
	T result = 0;
	stack<int> st;
	vector<int> L(n), R(n);
	for (int i = 0; i < n; ++i) {
		while (!st.empty() && a[st.top()] >= a[i]) st.pop();
		L[i] = st.empty() ? 0 : st.top() + 1;
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() && a[st.top()] >= a[i]) st.pop();
		R[i] = st.empty() ? n : st.top();
		st.push(i);
	}
	for (int i = 0; i < n; ++i) {
		result = max(result, a[i] * (R[i] - L[i]));
	}
	return result;
}
