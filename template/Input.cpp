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
class Input {
	static int gc() {
		return getchar_unlocked();
	}
	template <class T> static void i(T& v) {
		cin >> v;
	}
	static void i(char& v) {
		while (isspace(v = gc()))
			;
	}
	static void i(bool& v) {
		v = in<char>() != '0';
	}
	static void i(string& v) {
		v.clear();
		char c;
		for (i(c); !isspace(c); c = gc()) v += c;
	}
	static void i(int& v) {
		bool neg = false;
		v = 0;
		char c;
		i(c);
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c); c = gc()) v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	static void i(long long& v) {
		bool neg = false;
		v = 0;
		char c;
		i(c);
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c); c = gc()) v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	static void i(double& v) {
		double dp = 1;
		bool neg = false, adp = false;
		v = 0;
		char c;
		i(c);
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c) || c == '.'; c = gc()) {
			if (c == '.')
				adp = true;
			else if (adp)
				v += (c - '0') * (dp *= 0.1);
			else
				v = v * 10 + (c - '0');
		}
		if (neg) v = -v;
	}
	static void i(long double& v) {
		long double dp = 1;
		bool neg = false, adp = false;
		v = 0;
		char c;
		i(c);
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c) || c == '.'; c = gc()) {
			if (c == '.')
				adp = true;
			else if (adp)
				v += (c - '0') * (dp *= 0.1);
			else
				v = v * 10 + (c - '0');
		}
		if (neg) v = -v;
	}
	template <class T, class U> static void i(pair<T, U>& v) {
		i(v.first);
		i(v.second);
	}
	template <class T> static void i(vector<T>& v) {
		for (auto& e : v) i(e);
	}
	template <size_t N = 0, class T> static void input_tuple(T& v) {
		if constexpr (N < tuple_size_v<T>) {
			i(get<N>(v));
			input_tuple<N + 1>(v);
		}
	}
	template <class... T> static void i(tuple<T...>& v) {
		input_tuple(v);
	}
	struct InputV {
		int n, m;
		InputV(int _n) : n(_n), m(0) {}
		InputV(const pair<int, int>& nm) : n(nm.first), m(nm.second) {}
		template <class T> operator vector<T>() {
			vector<T> v(n);
			i(v);
			return v;
		}
		template <class T> operator vector<vector<T>>() {
			vector<vector<T>> v(n, vector<T>(m));
			i(v);
			return v;
		}
	};

public:
	static string read_line() {
		string v;
		char c;
		for (i(c); c != '\n' && c != '\0'; c = gc()) v += c;
		return v;
	}
	template <class T> static T in() {
		T v;
		i(v);
		return v;
	}
	template <class T> operator T() const {
		return in<T>();
	}
	int operator--(int) const {
		return in<int>() - 1;
	}
	InputV operator[](int n) const {
		return InputV(n);
	}
	InputV operator[](const pair<int, int>& n) const {
		return InputV(n);
	}
	void operator()() const {}
	template <class H, class... T> void operator()(H&& h, T&&... t) const {
		i(h);
		operator()(forward<T>(t)...);
	}

private:
	template <template <class...> class, class...> struct Multiple;
	template <template <class...> class V, class Head, class... Tail>
	struct Multiple<V, Head, Tail...> {
		template <class... Args> using vec = V<vector<Head>, Args...>;
		using type = typename Multiple<vec, Tail...>::type;
	};
	template <template <class...> class V> struct Multiple<V> { using type = V<>; };
	template <class... T> using multiple_t = typename Multiple<tuple, T...>::type;
	template <size_t N = 0, class T> void in_multiple(T& t) const {
		if constexpr (N < tuple_size_v<T>) {
			auto& vec = get<N>(t);
			using V = typename remove_reference_t<decltype(vec)>::value_type;
			vec.push_back(in<V>());
			in_multiple<N + 1>(t);
		}
	}

public:
	template <class... T> auto multiple(int H) const {
		multiple_t<T...> result;
		while (H--) in_multiple(result);
		return result;
	}
} in;
#define input(T) Input::in<T>()
#define INT input(int)
#define LL input(long long)
#define STR input(string)
#define inputs(T, ...) \
	T __VA_ARGS__;     \
	in(__VA_ARGS__)
#define ini(...) inputs(int, __VA_ARGS__)
#define inl(...) inputs(long long, __VA_ARGS__)
#define ins(...) inputs(string, __VA_ARGS__)
