#pragma once
#include "./../template/functions.cpp"
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int64_t BabystepGiantstep(uint64_t g, uint64_t h, uint64_t mod) {  // g ^ res = h (mod mod)
	const uint64_t m = ceil(sqrt(mod));
	unordered_map<uint64_t, uint64_t> table;
	uint64_t e = 1;
	for (uint64_t i = 0; i < m; ++i) {
		table[e] = i;
		e = e * g % mod;
	}
	e = h;
	for (uint64_t f = Powmod(g, mod - m - 1, mod), i = 0; i < m; ++i) {
		if (table.count(e)) {
			return i * m + table[e];
		}
		e = (e * f) % mod;
	}
	return -1;
}