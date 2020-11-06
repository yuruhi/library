#pragma once
#include <iostream>
#include <utility>
#include <string>
#include <vector>
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
} spc(" ", "\n"), no_spc("", "\n"), end_line("\n", "\n"), comma(",", "\n"), no_endl(" ", "");
class Output {
	BoolStr B{Yes};
	DivStr D{spc};
	void p(int v) const {
		char buf[12]{};
		if (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {
			fwrite(buf, sizeof(char), ptr - buf, stdout);
		} else {
			assert(false);
		}
	}
	void p(long long v) const {
		char buf[21]{};
		if (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {
			fwrite(buf, sizeof(char), ptr - buf, stdout);
		} else {
			assert(false);
		}
	}
	void p(bool v) const {
		p(v ? B.t : B.f);
	}
	void p(char v) const {
		putchar_unlocked(v);
	}
	void p(const char* v) const {
		fwrite_unlocked(v, 1, strlen(v), stdout);
	}
	void p(double v) const {
		printf("%.20f", v);
	}
	void p(long double v) const {
		printf("%.20Lf", v);
	}
	template <class T> void p(const T& v) const {
		cout << v;
	}
	template <class T, class U> void p(const pair<T, U>& v) const {
		p(v.first);
		p(D.d);
		p(v.second);
	}
	template <class T> void p(const vector<T>& v) const {
		for (size_t i = 0; i < v.size(); ++i) {
			if (i) p(D.d);
			p(v[i]);
		}
	}
	template <class T> void p(const vector<vector<T>>& v) const {
		for (size_t i = 0; i < v.size(); ++i) {
			if (i) p(D.l);
			p(v[i]);
		}
	}

public:
	Output& operator()() {
		p(D.l);
		return *this;
	}
	template <class H> Output& operator()(H&& h) {
		p(h);
		p(D.l);
		return *this;
	}
	template <class H, class... T> Output& operator()(H&& h, T&&... t) {
		p(h);
		p(D.d);
		return operator()(forward<T>(t)...);
	}
	template <class It> Output& range(const It& l, const It& r) {
		for (It i = l; i != r; i++) {
			if (i != l) p(D.d);
			p(*i);
		}
		p(D.l);
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
