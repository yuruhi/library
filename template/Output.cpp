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
class Printer {
	BoolStr B{Yes};
	DivStr D{spc};

public:
	void print(int v) const {
		char buf[12]{};
		if (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {
			fwrite(buf, sizeof(char), ptr - buf, stdout);
		} else {
			assert(false);
		}
	}
	void print(long long v) const {
		char buf[21]{};
		if (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {
			fwrite(buf, sizeof(char), ptr - buf, stdout);
		} else {
			assert(false);
		}
	}
	void print(bool v) const {
		print(v ? B.t : B.f);
	}
	void print(vector<bool>::reference v) const {
		print(v ? B.t : B.f);
	}
	void print(char v) const {
		putchar_unlocked(v);
	}
	void print(const char* v) const {
		fwrite_unlocked(v, 1, strlen(v), stdout);
	}
	void print(double v) const {
		printf("%.20f", v);
	}
	void print(long double v) const {
		printf("%.20Lf", v);
	}
	template <class T> void print(const T& v) const {
		cout << v;
	}
	template <class T, class U> void print(const pair<T, U>& v) const {
		print(v.first);
		print(D.d);
		print(v.second);
	}
	template <class InputIterater>
	void print_range(const InputIterater& begin, const InputIterater& end) const {
		for (InputIterater i = begin; i != end; ++i) {
			if (i != begin) print(D.d);
			print(*i);
		}
	}
	template <class T> void print(const vector<T>& v) const {
		print_range(v.begin(), v.end());
	}
	template <class T, size_t N> void print(const array<T, N>& v) const {
		print_range(v.begin(), v.end());
	}
	template <class T> void print(const vector<vector<T>>& v) const {
		for (size_t i = 0; i < v.size(); ++i) {
			if (i) print(D.l);
			print(v[i]);
		}
	}

	Printer() = default;
	Printer(const BoolStr& _boolstr, const DivStr& _divstr) : B(_boolstr), D(_divstr) {}
	Printer& operator()() {
		print(D.l);
		return *this;
	}
	template <class H> Printer& operator()(H&& h) {
		print(h);
		print(D.l);
		return *this;
	}
	template <class H, class... T> Printer& operator()(H&& h, T&&... t) {
		print(h);
		print(D.d);
		return operator()(forward<T>(t)...);
	}
	template <class InputIterator>
	Printer& range(const InputIterator& begin, const InputIterator& end) {
		print_range(begin, end);
		print(D.l);
		return *this;
	}
	template <class T> Printer& range(const T& a) {
		range(a.begin(), a.end());
		return *this;
	}
	template <class... T> void exit(T&&... t) {
		operator()(forward<T>(t)...);
		std::exit(EXIT_SUCCESS);
	}
	Printer& flush() {
		fflush_unlocked(stdout);
		return *this;
	}
	Printer& set(const BoolStr& b) {
		B = b;
		return *this;
	}
	Printer& set(const DivStr& d) {
		D = d;
		return *this;
	}
	Printer& set(const char* t, const char* f) {
		B = BoolStr(t, f);
		return *this;
	}
} out;
