#pragma once
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <array>
#include <charconv>
#include <cstring>
#include <cassert>
using namespace std;

struct BoolStr {
	const char *t, *f;
	BoolStr(const char* _t, const char* _f) : t(_t), f(_f) {}
} Yes("Yes", "No"), yes("yes", "no"), YES("YES", "NO"), Int("1", "0");
struct DivStr {
	const char *d, *l;
	DivStr(const char* _d, const char* _l) : d(_d), l(_l) {}
} spc(" ", "\n"), no_spc("", "\n"), end_line("\n", "\n"), comma(",", "\n"),
    no_endl(" ", "");
class Output {
	BoolStr B{Yes};
	DivStr D{spc};

public:
	void put(int v) const {
		char buf[12]{};
		if (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {
			fwrite(buf, sizeof(char), ptr - buf, stdout);
		} else {
			assert(false);
		}
	}
	void put(long long v) const {
		char buf[21]{};
		if (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {
			fwrite(buf, sizeof(char), ptr - buf, stdout);
		} else {
			assert(false);
		}
	}
	void put(bool v) const {
		put(v ? B.t : B.f);
	}
	void put(vector<bool>::reference v) const {
		put(v ? B.t : B.f);
	}
	void put(char v) const {
		putchar_unlocked(v);
	}
	void put(const char* v) const {
		fwrite_unlocked(v, 1, strlen(v), stdout);
	}
	void put(double v) const {
		printf("%.20f", v);
	}
	void put(long double v) const {
		printf("%.20Lf", v);
	}
	template <class T> void put(const T& v) const {
		cout << v;
	}
	template <class T, class U> void put(const pair<T, U>& v) const {
		put(v.first);
		put(D.d);
		put(v.second);
	}
	template <class InputIterater>
	void put_range(const InputIterater& begin, const InputIterater& end) const {
		for (InputIterater i = begin; i != end; ++i) {
			if (i != begin) put(D.d);
			put(*i);
		}
	}
	template <class T> void put(const vector<T>& v) const {
		put_range(v.begin(), v.end());
	}
	template <class T, size_t N> void put(const array<T, N>& v) const {
		put_range(v.begin(), v.end());
	}
	template <class T> void put(const vector<vector<T>>& v) const {
		for (size_t i = 0; i < v.size(); ++i) {
			if (i) put(D.l);
			put(v[i]);
		}
	}

	Output() = default;
	Output(const BoolStr& _boolstr, const DivStr& _divstr) : B(_boolstr), D(_divstr) {}
	Output& operator()() {
		put(D.l);
		return *this;
	}
	template <class H> Output& operator()(H&& h) {
		put(h);
		put(D.l);
		return *this;
	}
	template <class H, class... T> Output& operator()(H&& h, T&&... t) {
		put(h);
		put(D.d);
		return operator()(forward<T>(t)...);
	}
	template <class InputIterator>
	Output& range(const InputIterator& begin, const InputIterator& end) {
		put_range(begin, end);
		put(D.l);
		return *this;
	}
	template <class T> Output& range(const T& a) {
		range(a.begin(), a.end());
		return *this;
	}
	template <class... T> void exit(T&&... t) {
		operator()(forward<T>(t)...);
		std::exit(EXIT_SUCCESS);
	}
	Output& flush() {
		fflush_unlocked(stdout);
		return *this;
	}
	Output& set(const BoolStr& b) {
		B = b;
		return *this;
	}
	Output& set(const DivStr& d) {
		D = d;
		return *this;
	}
	Output& set(const char* t, const char* f) {
		B = BoolStr(t, f);
		return *this;
	}
} out;
