#pragma once
#include <vector>
#include <map>
#include <utility>
#include <cassert>
using namespace std;

class Sieve {
	int n;
	vector<int> factor, primes;

public:
	Sieve(int _n) : n(_n), factor(_n + 1) {
		assert(1 <= n);
		factor[0] = factor[1] = -1;
		for (long long i = 2; i <= n; ++i) {
			if (!factor[i]) {
				primes.push_back(i);
				factor[i] = i;
				for (long long j = i * i; j <= n; j += i) {
					if (!factor[j]) factor[j] = i;
				}
			}
		}
	}
	bool is_prime(int x) const {
		return factor[x] == x;
	}
	const vector<int>& get_primes() const {
		return primes;
	}
	vector<pair<int, int>> prime_factor(int x) const {
		assert(1 <= x);
		vector<pair<int, int>> result;
		while (x != 1) {
			if (result.empty() || result.back().first != factor[x]) {
				result.emplace_back(factor[x], 1);
			} else {
				result.back().second++;
			}
			x /= factor[x];
		}
		return result;
	}
	map<int, int> prime_factor_map(int x) const {
		assert(1 <= x);
		map<int, int> result;
		while (x != 1) {
			result[factor[x]]++;
			x /= factor[x];
		}
		return result;
	}
	vector<int> prime_factor_vec(int x) const {
		assert(1 <= x);
		vector<int> result;
		while (x != 1) {
			result.push_back(factor[x]);
			x /= factor[x];
		}
		return result;
	}
	int divisors_count(int x) const {
		assert(1 <= x);
		int result = 1;
		for (auto [elem, cnt] : prime_factor(x)) {
			result *= cnt + 1;
		}
		return result;
	}
};
