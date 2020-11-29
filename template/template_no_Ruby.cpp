#pragma once
#include <bits/stdc++.h>
#include "./constants.cpp"
#include "./Input.cpp"
#include "./Output.cpp"
#include "./functions.cpp"
#if __has_include(<library/dump.hpp>)
#include <library/dump.hpp>
#define LOCAL
#else
#define dump(...) ((void)0)
#endif

template <class T> constexpr T oj_local(const T& oj, const T& local) {
#ifndef LOCAL
	return oj;
#else
	return local;
#endif
}
