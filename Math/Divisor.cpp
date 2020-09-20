// description : 約数列挙、約数の個数、約数の総和
template <class T> vector<T> Divisor(T n) {
	assert(0 < n);
	vector<T> res;
	T i = 1;
	for (; i * i < n; ++i)
		if (n % i == 0) res.push_back(i);
	bool flag = i * i == n;
	if (flag) res.push_back(i);
	for (i = (int)res.size() - 1 - flag; i >= 0; --i)
		res.push_back(n / res[i]);
	return res;
}
template <class T> int DivCnt(T n) {
	assert(0 < n);
	int cnt = 0;
	T sq = (T)sqrt(n);
	for (T i = 1; i <= sq; ++i)
		cnt += (n % i == 0);
	return cnt * 2 - (sq * sq == n);
}
template <class T> T DivSum(T n) {
	assert(0 < n);
	T i = 1, res = 0;
	for (; i * i < n; ++i)
		if (n % i == 0) res += i + n / i;
	return res + i * (i * i == n);
}