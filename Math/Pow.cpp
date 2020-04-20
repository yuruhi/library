// shortcut : Pow
// description : 繰り返し二乗法 O(log N)
template<class T>T Pow(T a, T n) {
	T ret = 1;
	while (n > 0) {
		if (n & 1)ret *= a;
		a *= a; n /= 2;
	}
	return ret;
}
template<class T>T Powmod(T a, T n, T m) {
	T ret = 1;
	while (n > 0) {
		if (n & 1)ret = ret * a % m, n--;
		else a = a * a % m, n /= 2;
	}
	return ret;
}