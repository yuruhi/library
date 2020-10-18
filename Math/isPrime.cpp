#pragma once

template <class T> bool isPrime(T n) {
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;
	for (T i = 3; i * i <= n; i += 2)
		if (n % i == 0) return false;
	return true;
}
