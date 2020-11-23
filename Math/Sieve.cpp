#pragma once
#include <vector>
#include <map>
#include <utility>
#include <cassert>
using namespace std;

class Sieve {
	int n;
	vector<int> f, primes;

public:
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
	const vector<int>& get_primes() const {
		return primes;
	}
	vector<pair<int, int>> factor(int x) const {
		assert(1 <= x);
		vector<pair<int, int>> result;
		while (x != 1) {
			if (result.empty() || result.back().first != f[x]) {
				result.emplace_back(f[x], 1);
			} else {
				result.back().second++;
			}
			x /= f[x];
		}
		return result;
	}
	map<int, int> factor_map(int x) const {
		assert(1 <= x);
		map<int, int> result;
		while (x != 1) {
			result[f[x]]++;
			x /= f[x];
		}
		return result;
	}
	vector<int> factor_vec(int x) const {
		assert(1 <= x);
		vector<int> result;
		while (x != 1) {
			result.push_back(f[x]);
			x /= f[x];
		}
		return result;
	}
	int diviser_count(int x) const {
		assert(1 <= x);
		int result = 1;
		for (auto [elem, cnt] : factor(x)) {
			result *= cnt + 1;
		}
		return result;
	}
}
