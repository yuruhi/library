#pragma once
#include <optional>
#include <type_traits>
#include <cassert>

template <class T, class F, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
std::optional<T> Bsearch(T left, T right, F f) {
	if (left >= right || !f(right)) {
		return std::nullopt;
	}
	while (right - left > 1) {
		T middle = (left + right) / 2;
		(f(middle) ? right : left) = middle;
	}
	assert(!f(left));
	assert(f(right));
	return right;
}