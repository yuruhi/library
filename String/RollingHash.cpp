#pragma once
#include <vector>
#include <string>
using namespace std;

template <uint64_t MOD> class RollingHash {
public:
	using ull = uint64_t;

private:
	int n;
	ull base;
	vector<ull> pow, hash;

public:
	RollingHash(const string& s, ull _base = 10007)
	    : n(s.size()), base(_base), pow(n + 1), hash(n + 1) {
		pow[0] = 1;
		hash[0] = 0;
		for (int i = 0; i < n; ++i) {
			pow[i + 1] = pow[i] * base % MOD;
			hash[i + 1] = (s[i] + hash[i] * base) % MOD;
		}
	}
	// [0, r)
	ull operator()(int r) const {
		return hash[r];
	}
	// [l, r)
	ull operator()(int l, int r) const {
		return (hash[r] - hash[l] * pow[r - l] % MOD + MOD) % MOD;
	}
};
using RH = RollingHash<1000000007>;
