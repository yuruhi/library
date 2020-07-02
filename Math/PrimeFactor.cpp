// shortcut : PrimeFactor
// description : 素因数分解 O(√N)
template <class T> map<T, int> PrimeFactor(T n) {
	assert(2 <= n);
	map<T, int> ret;
	for (T i = 2; i * i <= n; ++i)
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	if (n != 1) ret[n] = 1;
	return ret;
}
template <class T> vector<T> PrimeFactorV(T n) {
	assert(2 <= n);
	vector<T> ret;
	for (T i = 2; i * i <= n; ++i)
		while (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	if (n != 1) ret.push_back(n);
	return ret;
}