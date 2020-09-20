// description : 転倒数 a : { 1..N } の順列
long long Inversion(const vector<int>& a, int max_val) {
	long long ans = 0;
	BinaryIndexedTree<int> bit(max_val + 1);
	for (size_t i = 0; i < a.size(); ++i) {
		ans += i - bit(a[i] - 1);
		bit.add(a[i], 1);
	}
	return ans;
}