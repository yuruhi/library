// description : エラトステネスの篩 O(N log log N)、素因数分解 O(素因数の個数)
struct Sieve {
	int n;
	vector<int> f, primes;
	Sieve(int _n) : n(_n), f(_n + 1) {
		assert(1 <= n);
		f[0] = f[1] = -1;
		for (long long i = 2; i <= n; ++i)
			if (!f[i]) {
				primes.push_back(i);
				f[i] = i;
				for (long long j = i * i; j <= n; j += i)
					if (!f[j]) f[j] = i;
			}
	}
	bool is_prime(int x) const {
		return f[x] == x;
	}
	vector<pair<int, int>> factor(int x) const {
		assert(1 <= x);
		vector<pair<int, int>> res;
		while (x != 1) {
			if (res.empty() || res.back().first != f[x]) {
				res.emplace_back(f[x], 1);
			} else {
				res.back().second++;
			}
			x /= f[x];
		}
		return res;
	}
	map<int, int> factor_map(int x) const {
		assert(1 <= x);
		map<int, int> res;
		while (x != 1) {
			res[f[x]]++;
			x /= f[x];
		}
		return res;
	}
	vector<int> factor_vec(int x) const {
		assert(1 <= x);
		vector<int> res;
		while (x != 1) {
			res.push_back(f[x]);
			x /= f[x];
		}
		return res;
	}
	int diviser_count(int x) const {
		assert(1 <= x);
		int res = 1;
		for (auto [elem, cnt] : factor(x)) {
			res *= cnt + 1;
		}
		return res;
	}
};