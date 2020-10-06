#pragma once

template <class T> int mex(const T& a) {
	int x = 0;
	for (int i : a) {
		if (x < i) break;
		if (i == x) x++;
	}
	return x;
}