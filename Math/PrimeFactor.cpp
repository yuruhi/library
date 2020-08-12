// description : 素因数分解 O(√N)
template <class T> map<T, int> PrimeFactor(T n) {
	assert(2 <= n);
	map<T, int> res;
	for (T i = 2; i * i <= n; ++i)
		while (n % i == 0) {
			res[i]++;
			n /= i;
		}
	if (n != 1) res[n] = 1;
	return res;
}
template <class T> vector<T> PrimeFactorV(T n) {
	assert(2 <= n);
	vector<T> res;
	for (T i = 2; i * i <= n; ++i)
		while (n % i == 0) {
			res.push_back(i);
			n /= i;
		}
	if (n != 1) res.push_back(n);
	return res;
}