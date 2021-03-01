#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
using namespace std;

#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#define fwrite_unlocked fwrite
#define fflush_unlocked fflush
#endif
class Scanner {
	static int gc() {
		return getchar_unlocked();
	}
	static char next_char() {
		char c;
		scan(c);
		return c;
	}
	template <class T> static void scan(T& v) {
		cin >> v;
	}
	static void scan(char& v) {
		while (isspace(v = gc()))
			;
	}
	static void scan(bool& v) {
		v = next_char() != '0';
	}
	static void scan(string& v) {
		v.clear();
		for (char c = next_char(); !isspace(c); c = gc()) v += c;
	}
	static void scan(int& v) {
		v = 0;
		bool neg = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c); c = gc()) v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	static void scan(long long& v) {
		v = 0;
		bool neg = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c); c = gc()) v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	static void scan(double& v) {
		v = 0;
		double dp = 1;
		bool neg = false, after_dp = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c) || c == '.'; c = gc()) {
			if (c == '.') {
				after_dp = true;
			} else if (after_dp) {
				v += (c - '0') * (dp *= 0.1);
			} else {
				v = v * 10 + (c - '0');
			}
		}
		if (neg) v = -v;
	}
	static void scan(long double& v) {
		v = 0;
		long double dp = 1;
		bool neg = false, after_dp = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c) || c == '.'; c = gc()) {
			if (c == '.') {
				after_dp = true;
			} else if (after_dp) {
				v += (c - '0') * (dp *= 0.1);
			} else {
				v = v * 10 + (c - '0');
			}
		}
		if (neg) v = -v;
	}
	template <class T, class U> static void scan(pair<T, U>& v) {
		scan(v.first);
		scan(v.second);
	}
	template <class T> static void scan(vector<T>& v) {
		for (auto& e : v) scan(e);
	}
	template <size_t N = 0, class T> static void scan_tuple_impl(T& v) {
		if constexpr (N < tuple_size_v<T>) {
			scan(get<N>(v));
			scan_tuple_impl<N + 1>(v);
		}
	}
	template <class... T> static void scan(tuple<T...>& v) {
		scan_tuple_impl(v);
	}
	struct ReadVectorHelper {
		size_t n;
		ReadVectorHelper(size_t _n) : n(_n) {}
		template <class T> operator vector<T>() {
			vector<T> v(n);
			scan(v);
			return v;
		}
	};
	struct Read2DVectorHelper {
		size_t n, m;
		Read2DVectorHelper(const pair<size_t, size_t>& nm) : n(nm.first), m(nm.second) {}
		template <class T> operator vector<vector<T>>() {
			vector<vector<T>> v(n, vector<T>(m));
			scan(v);
			return v;
		}
	};

public:
	string read_line() const {
		string v;
		for (char c = gc(); c != '\n' && c != '\0'; c = gc()) v += c;
		return v;
	}
	template <class T> T read() const {
		T result;
		scan(result);
		return result;
	}
	template <class T> vector<T> read(size_t n) const {
		vector<T> result(n);
		scan(result);
		return result;
	}
	template <class T> operator T() const {
		return read<T>();
	}
	int operator--(int) const {
		return read<int>() - 1;
	}
	ReadVectorHelper operator[](size_t n) const {
		return ReadVectorHelper(n);
	}
	Read2DVectorHelper operator[](const pair<size_t, size_t>& nm) const {
		return Read2DVectorHelper(nm);
	}
	void operator()() const {}
	template <class H, class... T> void operator()(H&& h, T&&... t) const {
		scan(h);
		operator()(forward<T>(t)...);
	}

private:
	template <template <class...> class, class...> struct Column;
	template <template <class...> class V, class Head, class... Tail>
	struct Column<V, Head, Tail...> {
		template <class... Args> using vec = V<vector<Head>, Args...>;
		using type = typename Column<vec, Tail...>::type;
	};
	template <template <class...> class V> struct Column<V> { using type = V<>; };
	template <class... T> using column_t = typename Column<tuple, T...>::type;
	template <size_t N = 0, class T> void column_impl(T& t) const {
		if constexpr (N < tuple_size_v<T>) {
			auto& vec = get<N>(t);
			using V = typename remove_reference_t<decltype(vec)>::value_type;
			vec.push_back(read<V>());
			column_impl<N + 1>(t);
		}
	}

public:
	template <class... T> auto column(size_t h) const {
		column_t<T...> result;
		while (h--) column_impl(result);
		return result;
	}
} in;
#define inputs(T, ...) \
	T __VA_ARGS__;     \
	in(__VA_ARGS__)
#define ini(...) inputs(int, __VA_ARGS__)
#define inl(...) inputs(long long, __VA_ARGS__)
#define ins(...) inputs(string, __VA_ARGS__)
