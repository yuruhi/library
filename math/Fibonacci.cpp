#pragma once
#include "./Matrix.cpp"
#include <vector>

template <class value_type> value_type Fibonacci(long long n) {
	Matrix<value_type> A(std::vector<std::vector<value_type>>{{1, 1}, {1, 0}});
	Matrix<value_type> B(std::vector<std::vector<value_type>>{{1}, {0}});
	return (A.pow(n) * B)[1][0];
}

template <class value_type = long long> std::vector<value_type> EnumerateFibonacci(int n) {
	std::vector<value_type> result(n + 1);
	for (int i = 0; i <= n; ++i) {
		if (i < 2) {
			result[i] = i;
		} else {
			result[i] = result[i - 1] + result[i - 2];
		}
	}
	return result;
}
