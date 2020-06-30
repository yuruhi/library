// shortcut : Mex
// description : a に含まれない最小の非負整数
template <class T> int mex(const T &a) {
	int x = 0;
	for (int i : a) {
		if (x < i) break;
		if (i == x) x++;
	}
	return x;
}