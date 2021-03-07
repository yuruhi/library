#pragma once
#include <vector>
#include <map>
#include <utility>
#include <cassert>
using namespace std;

class Sieve {
	int n;
	vector<int> factor_m, primes_m;

public:
	Sieve(int _n) : n(_n), factor_m(_n + 1) {
		assert(1 <= n);
		factor_m[0] = factor_m[1] = -1;
		for (long long i = 2; i <= n; ++i) {
			if (!factor_m[i]) {
				primes_m.push_back(i);
				factor_m[i] = i;
				for (long long j = i * i; j <= n; j += i) {
					if (!factor_m[j]) factor_m[j] = i;
				}
			}
		}
	}
	bool is_prime(int x) const {
		return factor_m[x] == x;
	}
	vector<int> primes() const {
		return primes_m;
	}
	vector<int> primes(int x) const {
		vector<int> result;
		for (size_t i = 0; i < primes_m.size(); ++i) {
			if (primes_m[i] > x) break;
			result.push_back(primes_m[i]);
		}
		return result;
	}
	vector<pair<int, int>> prime_factor(int x) const {
		assert(1 <= x);
		vector<pair<int, int>> result;
		while (x != 1) {
			if (result.empty() || result.back().first != factor_m[x]) {
				result.emplace_back(factor_m[x], 1);
			} else {
				result.back().second++;
			}
			x /= factor_m[x];
		}
		return result;
	}
	map<int, int> prime_factor_map(int x) const {
		assert(1 <= x);
		map<int, int> result;
		while (x != 1) {
			result[factor_m[x]]++;
			x /= factor_m[x];
		}
		return result;
	}
	vector<int> prime_factor_vec(int x) const {
		assert(1 <= x);
		vector<int> result;
		while (x != 1) {
			result.push_back(factor_m[x]);
			x /= factor_m[x];
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
