#pragma once
#include <vector>
#include <string>
#include <library/dump.hpp>

class RollingHash {
public:
	using value_type = std::uint64_t;

private:
	static constexpr value_type MASK30 = (1ul << 30) - 1;
	static constexpr value_type MASK31 = (1ul << 31) - 1;
	static constexpr value_type MASK61 = (1ul << 61) - 1;
	static constexpr value_type MOD = MASK61;

	static constexpr value_type mul(value_type a, value_type b) {
		auto au = a >> 31, ad = a & MASK31;
		auto bu = b >> 31, bd = b & MASK31;
		auto mid = ad * bu + au * bd;
		auto midu = mid >> 30, midd = mid & MASK30;
		return au * bu * 2 + midu + (midd << 31) + ad * bd;
	}
	static constexpr value_type calc_mod(value_type x) {
		auto res = (x >> 61) + (x & MASK61);
		if (res >= MOD) res -= MOD;
		return res;
	}

	std::size_t n;
	value_type base;
	std::vector<value_type> pow, hash;

public:
	RollingHash(const std::string& s, value_type _base = 10007)
	    : n(s.size()), base(_base), pow(n + 1), hash(n + 1) {
		pow[0] = 1;
		for (std::size_t i = 0; i < n; ++i) {
			pow[i + 1] = calc_mod(mul(pow[i], base));
			hash[i + 1] = calc_mod(mul(hash[i], base) + s[i]);
		}
		dump(pow, hash);
	}
	// [0, right)
	value_type operator()(int right) const {
		return hash[right];
	}
	// [left, right)
	value_type operator()(int left, int right) const {
		return calc_mod(hash[right] + MOD * 4 - mul(hash[left], pow[right - left]));
	}
};
