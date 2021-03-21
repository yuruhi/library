#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cassert>

class Radix {
public:
	using value_type = long long;

private:
	static inline std::string chars;
	static inline std::map<char, int> char_to_int;

public:
	static void Init(std::string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
		chars = s;
		for (std::size_t i = 0; i < chars.size(); i++) {
			char_to_int[chars[i]] = i;
		}
	}
	// value(R) -> result(10)
	static value_type to10(const std::string& value, int R) {
		value_type result = 0, p = 1;
		for (int i = value.size() - 1; i >= 0; --i) {
			assert(char_to_int.count(value[i]));
			result += char_to_int[value[i]] * p;
			p *= R;
		}
		return result;
	}
	// value(10) -> result(N)
	static std::string toN(value_type value, int N) {
		std::string result;
		value_type m = value;
		do {
			result += chars[m % N];
			m /= N;
		} while (m);
		std::reverse(result.begin(), result.end());
		return result;
	}
	// value(R) -> result(N)
	static std::string toN(const std::string& value, int R, int N) {
		return toN(to10(value, R), N);
	}
};
