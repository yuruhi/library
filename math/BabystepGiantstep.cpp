#pragma once
#include "./../template/functions.cpp"
#include <vector>
#include <unordered_map>
#include <cmath>

// g ^ result ≡ h (mod mod)
int64_t BabystepGiantstep(std::uint64_t g, std::uint64_t h, std::uint64_t mod) {
	const std::uint64_t m = std::ceil(std::sqrt(mod));
	std::unordered_map<std::uint64_t, std::uint64_t> table;
	std::uint64_t e = 1;
	for (std::uint64_t i = 0; i < m; ++i) {
		table[e] = i;
		e = e * g % mod;
	}
	e = h;
	for (std::uint64_t f = Powmod(g, mod - m - 1, mod), i = 0; i < m; ++i) {
		if (table.count(e)) {
			return i * m + table[e];
		}
		e = (e * f) % mod;
	}
	return -1;
}
