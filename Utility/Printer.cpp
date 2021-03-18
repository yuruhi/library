#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include <string>
#include <string_view>
#include <optional>
#include <charconv>
#include <cstring>
#include <cassert>

class Printer {
public:
	struct BoolString {
		std::string_view t, f;
		BoolString(std::string_view _t, std::string_view _f) : t(_t), f(_f) {}
	};
	struct Separator {
		std::string_view div, sep, last;
		Separator(std::string_view _div, std::string_view _sep, std::string_view _last)
		    : div(_div), sep(_sep), last(_last) {}
	};

	inline static const BoolString Yes{"Yes", "No"}, yes{"yes", "no"}, YES{"YES", "NO"},
	    Int{"1", "0"}, Possible{"Possible", "Impossible"};
	inline static const Separator space{" ", " ", "\n"}, no_space{"", "", "\n"},
	    endl{"\n", "\n", "\n"}, comma{",", ",", "\n"}, no_endl{" ", " ", ""},
	    sep_endl{" ", "\n", "\n"};

	BoolString bool_str{Yes};
	Separator separator{space};

	void print(int v) const {
		char buf[12]{};
		if (auto [ptr, e] = std::to_chars(std::begin(buf), std::end(buf), v);
		    e == std::errc{}) {
			print(std::string_view(buf, ptr - buf));
		} else {
			assert(false);
		}
	}
	void print(long long v) const {
		char buf[21]{};
		if (auto [ptr, e] = std::to_chars(std::begin(buf), std::end(buf), v);
		    e == std::errc{}) {
			print(std::string_view(buf, ptr - buf));
		} else {
			assert(false);
		}
	}
	void print(bool v) const {
		print(v ? bool_str.t : bool_str.f);
	}
	void print(std::vector<bool>::reference v) const {
		print(v ? bool_str.t : bool_str.f);
	}
	void print(char v) const {
		putchar_unlocked(v);
	}
	void print(std::string_view v) const {
		fwrite_unlocked(v.data(), sizeof(std::string_view::value_type), v.size(), stdout);
	}
	void print(double v) const {
		std::printf("%.20f", v);
	}
	void print(long double v) const {
		std::printf("%.20Lf", v);
	}
	template <class T> void print(const T& v) const {
		std::cout << v;
	}
	template <class T, class U> void print(const std::pair<T, U>& v) const {
		print(v.first);
		print(separator.div);
		print(v.second);
	}
	template <class T> void print(const std::optional<T>& v) const {
		print(*v);
	}
	template <class InputIterater>
	void print_range(const InputIterater& begin, const InputIterater& end) const {
		for (InputIterater i = begin; i != end; ++i) {
			if (i != begin) print(separator.sep);
			print(*i);
		}
	}
	template <class T> void print(const std::vector<T>& v) const {
		print_range(v.begin(), v.end());
	}
	template <class T, std::size_t N> void print(const std::array<T, N>& v) const {
		print_range(v.begin(), v.end());
	}
	template <class T> void print(const std::vector<std::vector<T>>& v) const {
		for (std::size_t i = 0; i < v.size(); ++i) {
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
		return operator()(std::forward<Tail>(tail)...);
	}
	template <class... Args> Printer& flag(bool f, Args&&... args) {
		if (f) {
			return operator()(std::forward<Args>(args)...);
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
		operator()(std::forward<T>(t)...);
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
	Printer& set(std::string_view t, std::string_view f) {
		bool_str = BoolString(t, f);
		return *this;
	}
} out;
