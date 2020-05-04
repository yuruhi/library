// shortcut : Inversion
// description : 転倒数 a : { 1..N } の順列
long long Inversion(const vector<int> a) {
	int n = a.size(); long long ans = 0;
	BinaryIndexedTree<int> bit(n);
	for (int i = 0; i < n; ++i) {
		ans += i - bit(a[i] - 1);
		bit.add(a[i], 1);
	}
	return ans;
}