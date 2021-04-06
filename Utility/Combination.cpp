#pragma once
#include <vector>

template <class T, class F>
void each_repeated_permutation(const T& array, std::size_t count, F f) {
	using value_type = typename T::value_type;
	std::vector<value_type> permutation(count);
	auto dfs = [&](auto self, std::size_t size) -> void {
		if (size == count) {
			f(permutation);
		} else {
			for (const auto& i : array) {
				permutation[size] = i;
				self(self, size + 1);
			}
		}
	};
	dfs(dfs, 0);
}

template <class T> auto repeated_permutations(const T& array, std::size_t count) {
	using value_type = typename T::value_type;
	std::vector<std::vector<value_type>> result;
	std::size_t size = 1;
	for (std::size_t i = 0; i < count; ++i) {
		size *= array.size();
	}
	result.reserve(size);
	each_repeated_permutation(array, count, [&](const auto& perm) { result.push_back(perm); });
	return result;
}