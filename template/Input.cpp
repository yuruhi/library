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
	int gc() const {
		return getchar_unlocked();
	}
	template <class T> void read(T& v) const {
		cin >> v;
	}
	void read(char& v) const {
		while (isspace(v = gc()))
			;
	}
	void read(bool& v) const {
		v = read<char>() != '0';
	}
	void read(string& v) const {
		v.clear();
		for (char c = read<char>(); !isspace(c); c = gc()) v += c;
	}
	void read(int& v) const {
		v = 0;
		bool neg = false;
		char c = read<char>();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c); c = gc()) v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	void read(long long& v) const {
		v = 0;
		bool neg = false;
		char c = read<char>();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c); c = gc()) v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	void read(double& v) const {
		v = 0;
		double dp = 1;
		bool neg = false, after_dp = false;
		char c = read<char>();
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
	void read(long double& v) const {
		v = 0;
		long double dp = 1;
		bool neg = false, after_dp = false;
		char c = read<char>();
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
	template <class T, class U> void read(pair<T, U>& v) const {
		read(v.first);
		read(v.second);
	}
	template <class T> void read(vector<T>& v) const {
		for (auto& e : v) read(e);
	}
	template <size_t N = 0, class T> void read_tuple_impl(T& v) const {
		if constexpr (N < tuple_size_v<T>) {
			read(get<N>(v));
			read_tuple_impl<N + 1>(v);
		}
	}
	template <class... T> void read(tuple<T...>& v) const {
		read_tuple_impl(v);
	}
	struct ReadVectorHelper {
		size_t n;
		ReadVectorHelper(size_t _n) : n(_n) {}
		template <class T> operator vector<T>() {
			vector<T> v(n);
			read(v);
			return v;
		}
	};
	struct Read2DVectorHelper {
		size_t n, m;
		Read2DVectorHelper(const pair<size_t, size_t>& nm) : n(nm.first), m(nm.second) {}
		template <class T> operator vector<vector<T>>() {
			vector<vector<T>> v(n, vector<T>(m));
			read(v);
			return v;
		}
	};

public:
	string read_line() const {
		string v;
		for (char c = read<char>(); c != '\n' && c != '\0'; c = gc()) v += c;
		return v;
	}
	template <class T> T read() const {
		T v;
		read(v);
		return v;
	}
	template <class T> vector<T> read_vector(size_t n) const {
		vector<T> a(n);
		read(a);
		return a;
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
		read(h);
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
	template <size_t N = 0, class T> void multiple_impl(T& t) const {
		if constexpr (N < tuple_size_v<T>) {
			auto& vec = get<N>(t);
			using V = typename remove_reference_t<decltype(vec)>::value_type;
			vec.push_back(read<V>());
			multiple_impl<N + 1>(t);
		}
	}

public:
	template <class... T> auto multiple(size_t h) const {
		multiple_t<T...> result;
		while (h--) multiple_impl(result);
		return result;
	}
} in;
#define inputs(T, ...) \
	T __VA_ARGS__;     \
	in(__VA_ARGS__)
#define ini(...) inputs(int, __VA_ARGS__)
#define inl(...) inputs(long long, __VA_ARGS__)
#define ins(...) inputs(string, __VA_ARGS__)
