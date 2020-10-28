#pragma once
#include "./Matrix.cpp"
#include <vector>
using namespace std;

template <class value_type> value_type Fibonacci(long long n) {
	Matrix<value_type> A(vector<vector<value_type>>{{1, 1}, {1, 0}});
	Matrix<value_type> B(vector<vector<value_type>>{{1}, {0}});
	return (A.pow(n) * B)[1][0];
}
