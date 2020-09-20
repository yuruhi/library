// description : ヒストグラム中の最大長方形
template <class T> T MaximumRectangle(vector<T> h) {
	int n = h.size();
	T ans = 0;
	stack<int> s;
	vector<int> L(n), R(n);
	for (int i = 0; i < n; ++i) {
		while (!s.empty() && h[s.top()] >= h[i])
			s.pop();
		L[i] = s.empty() ? 0 : s.top() + 1;
		s.push(i);
	}
	while (!s.empty())
		s.pop();
	for (int i = n - 1; i >= 0; --i) {
		while (!s.empty() && h[s.top()] >= h[i])
			s.pop();
		R[i] = s.empty() ? n : s.top();
		s.push(i);
	}
	for (int i = 0; i < n; ++i) {
		ans = max(ans, h[i] * (R[i] - L[i]));
	}
	return ans;
}