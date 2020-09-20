// description : n 以下の素数列挙
vector<int> Primes(int n) {
	vector<int> res;
	auto p = Eratosthenes(n);
	for (int i = 0; i <= n; ++i)
		if (p[i]) res.push_back(i);
	return res;
}