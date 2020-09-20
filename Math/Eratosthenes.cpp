// description : エラトステネスの篩
vector<bool> Eratosthenes(int n) {
	vector<bool> p(n + 1, true);
	p[0] = p[1] = false;
	for (long long i = 2; i <= n; ++i)
		if (p[i])
			for (long long j = i * i; j <= n; j += i)
				p[j] = false;
	return p;
}