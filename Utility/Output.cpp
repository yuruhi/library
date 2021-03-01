#pragma once
#include <iostream>
#include <utility>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <charconv>
#include <cstring>
#include <cassert>
using namespace std;

class Printer {
public:
	struct BoolString {
		string_view t, f;
		BoolString(string_view _t, string_view _f) : t(_t), f(_f) {}
	};
	struct Separator {
		string_view div, sep, last;
		Separator(string_view _div, string_view _sep, string_view _last)
		    : div(_div), sep(_sep), last(_last) {}
	};

	inline static const BoolString Yes{"Yes", "No"}, yes{"yes", "no"}, YES{"YES", "NO"},
	    Int{"1", "0"};
	inline static const Separator space{" ", " ", "\n"}, no_space{"", "", "\n"},
	    end_line{"\n", "\n", "\n"}, comma{",", ",", "\n"}, no_endl{" ", " ", ""};

	BoolString bool_str{Yes};
	Separator separator{space};

public:
	void print(int v) const {
		char buf[12]{};
		if (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {
			print(string_view(buf, ptr - buf));
		} else {
			assert(false);
		}
	}
	void print(long long v) const {
		char buf[21]{};
		if (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {
			print(string_view(buf, ptr - buf));
		} else {
			assert(false);
		}
	}
	void print(bool v) const {
		print(v ? bool_str.t : bool_str.f);
	}
	void print(vector<bool>::reference v) const {
		print(v ? bool_str.t : bool_str.f);
	}
	void print(char v) const {
		putchar_unlocked(v);
	}
	void print(string_view v) const {
		fwrite_unlocked(v.data(), sizeof(string_view::value_type), v.size(), stdout);
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
		print(separator.div);
		print(v.second);
	}
	template <class InputIterater>
	void print_range(const InputIterater& begin, const InputIterater& end) const {
		for (InputIterater i = begin; i != end; ++i) {
			if (i != begin) print(separator.div);
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
			if (i) print(separator.last);
			print(v[i]);
		}
	}

	Printer() = default;
	Printer(const BoolString& _bool_str, const Separator& _separator)
	    : bool_str(_bool_str), separator(_separator) {}
	Printer& operator()() {
		print(separator.last);
		return *this;
	}
	template <class Head> Printer& operator()(Head&& head) {
		print(head);
		print(separator.last);
		return *this;
	}
	template <class Head, class... Tail> Printer& operator()(Head&& head, Tail&&... tail) {
		print(head);
		print(separator.sep);
		return operator()(forward<Tail>(tail)...);
	}
	template <class... Args> Printer& flag(bool f, Args&&... args) {
		if (f) {
			return operator()(forward<Args>(args)...);
		} else {
			return *this;
		}
	}
	template <class InputIterator>
	Printer& range(const InputIterator& begin, const InputIterator& end) {
		print_range(begin, end);
		print(separator.last);
		return *this;
	}
	template <class Container> Printer& range(const Container& a) {
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
	Printer& set(const BoolString& _bool_str) {
		bool_str = _bool_str;
		return *this;
	}
	Printer& set(const Separator& _separator) {
		separator = _separator;
		return *this;
	}
	Printer& set(string_view t, string_view f) {
		bool_str = BoolString(t, f);
		return *this;
	}
} out;
