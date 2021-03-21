#pragma once
#include <vector>
#include <optional>
#include <cmath>

template <class T>
std::optional<std::vector<T>> QuadraticEquation(long long a, long long b, long long c) {
	T A = a, B = b, C = c;
	if (a == 0 && b == 0 && c == 0) {
		return std::nullopt;
	} else if (a == 0 && b == 0) {
		return std::vector<T>();
	} else if (a == 0) {
		return std::vector{-(C / B)};
	} else {
		long long d = b * b - 4 * a * c;
		T D = static_cast<T>(d);
		if (d < 0) {
			return std::vector<T>();
		} else if (d == 0) {
			return std::vector{-B / (2 * A)};
		} else {
			T ans1 = 0, ans2 = 0;
			if (b > 0) {
				ans1 = (-B - sqrt(D)) / (2 * A);
			} else {
				ans1 = (-B + sqrt(D)) / (2 * A);
			}
			ans2 = (C / A) / ans1;
			return std::vector{min(ans1, ans2), max(ans1, ans2)};
		}
	}
}
