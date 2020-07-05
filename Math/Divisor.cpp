// description : 約数列挙、約数の個数、約数の総和
template <class T> vector<T> Divisor(T n) {
	assert(0 < n);
	vector<T> ret;
	T i = 1;
	for (; i * i < n; ++i)
		if (n % i == 0) ret.push_back(i);
	bool flag = i * i == n;
	if (flag) ret.push_back(i);
	for (i = (int)ret.size() - 1 - flag; i >= 0; --i) ret.push_back(n / ret[i]);
	return ret;
}
template <class T> int DivCnt(T n) {
	assert(0 < n);
	int cnt = 0;
	T sq = (T)sqrt(n);
	for (T i = 1; i <= sq; ++i) cnt += (n % i == 0);
	return cnt * 2 - (sq * sq == n);
}
template <class T> T DivSum(T n) {
	assert(0 < n);
	T i = 1, ret = 0;
	for (; i * i < n; ++i)
		if (n % i == 0) ret += i + n / i;
	return ret + i * (i * i == n);
}