// shortcut : extGcd
// description : ax + by = c の整数解
template<class T>T extGcd(T a, T b, T& x, T& y) {
	T d = a;
	if (b != 0) {
		d = extGcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}