#pragma once
template <class T> constexpr T oj_local(const T& oj, const T& local) {
#ifndef LOCAL
	return oj;
#else
	return local;
#endif
}
