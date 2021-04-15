#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <type_traits>

#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#define fwrite_unlocked fwrite
#define fflush_unlocked fflush
#endif
class Scanner {
	template <class T, class = void> struct has_scan : std::false_type {};
	template <class T>
	struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner>()))>>
	    : std::true_type {};

public:
	int gc() const {
		return getchar_unlocked();
	}
	char next_char() const {
		char c;
		scan(c);
		return c;
	}
	void scan(char& v) const {
		while (std::isspace(v = gc()))
			;
	}
	void scan(bool& v) const {
		v = next_char() != '0';
	}
	void scan(std::vector<bool>::reference v) const {
		bool b;
		scan(b);
		v = b;
	}
	void scan(std::string& v) const {
		v.clear();
		for (char c = next_char(); !std::isspace(c); c = gc()) v += c;
	}
	void scan(int& v) const {
		v = 0;
		bool neg = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; std::isdigit(c); c = gc()) v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	void scan(long long& v) const {
		v = 0;
		bool neg = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; std::isdigit(c); c = gc()) v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	void scan(double& v) const {
		v = 0;
		double dp = 1;
		bool neg = false, after_dp = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; std::isdigit(c) || c == '.'; c = gc()) {
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
	void scan(long double& v) const {
		v = 0;
		long double dp = 1;
		bool neg = false, after_dp = false;
		char c = next_char();
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; std::isdigit(c) || c == '.'; c = gc()) {
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
	template <class T, class U> void scan(std::pair<T, U>& v) const {
		scan(v.first);
		scan(v.second);
	}
	template <class T, std::enable_if_t<!std::is_same_v<bool, T>, std::nullptr_t> = nullptr>
	void scan(std::vector<T>& v) const {
		for (auto& e : v) scan(e);
	}
	template <class T, std::enable_if_t<std::is_same_v<bool, T>, std::nullptr_t> = nullptr>
	void scan(std::vector<T>& v) const {
		for (auto e : v) scan(e);
	}

private:
	template <std::size_t N = 0, class T> void scan_tuple_impl(T& v) const {
		if constexpr (N < std::tuple_size_v<T>) {
			scan(std::get<N>(v));
			scan_tuple_impl<N + 1>(v);
		}
	}

public:
	template <class... T> void scan(std::tuple<T...>& v) const {
		scan_tuple_impl(v);
	}
	template <class T, std::enable_if_t<has_scan<T>::value, std::nullptr_t> = nullptr>
	void scan(T& v) const {
		v.scan(*this);
	}
	template <class T, std::enable_if_t<!has_scan<T>::value, std::nullptr_t> = nullptr>
	void scan(T& v) const {
		std::cin >> v;
	}

private:
	struct Read2DVectorHelper {
		std::size_t h, w;
		Read2DVectorHelper(std::size_t _h, std::size_t _w) : h(_h), w(_w) {}
		template <class T> operator std::vector<std::vector<T>>() {
			std::vector vector(h, std::vector<T>(w));
			scan(vector);
			return vector;
		}
	};
	struct ReadVectorHelper {
		std::size_t n;
		ReadVectorHelper(std::size_t _n) : n(_n) {}
		template <class T> operator std::vector<T>() {
			std::vector<T> vector(n);
			scan(vector);
			return vector;
		}
		auto operator[](std::size_t m) {
			return Read2DVectorHelper(n, m);
		}
	};

public:
	template <class T> T read() const {
		T result;
		scan(result);
		return result;
	}
	template <class T> auto read(std::size_t n) const {
		std::vector<T> result(n);
		scan(result);
		return result;
	}
	template <class T> auto read(std::size_t h, std::size_t w) const {
		std::vector result(h, std::vector<T>(w));
		scan(result);
		return result;
	}
	std::string read_line() const {
		std::string v;
		for (char c = gc(); c != '\n' && c != '\0'; c = gc()) v += c;
		return v;
	}
	template <class T> operator T() const {
		return read<T>();
	}
	int operator--(int) const {
		return read<int>() - 1;
	}
	auto operator[](std::size_t n) const {
		return ReadVectorHelper(n);
	}
	auto operator[](const std::pair<std::size_t, std::size_t>& nm) const {
		return Read2DVectorHelper(nm.first, nm.second);
	}
	void operator()() const {}
	template <class H, class... T> void operator()(H&& h, T&&... t) const {
		scan(h);
		operator()(std::forward<T>(t)...);
	}

private:
	template <template <class...> class, class...> struct Column;
	template <template <class...> class V, class Head, class... Tail>
	struct Column<V, Head, Tail...> {
		template <class... Args> using vec = V<std::vector<Head>, Args...>;
		using type = typename Column<vec, Tail...>::type;
	};
	template <template <class...> class V> struct Column<V> { using type = V<>; };
	template <class... T> using column_t = typename Column<std::tuple, T...>::type;
	template <std::size_t N = 0, class T> void column_impl(T& t) const {
		if constexpr (N < std::tuple_size_v<T>) {
			auto& vec = std::get<N>(t);
			using V = typename std::remove_reference_t<decltype(vec)>::value_type;
			vec.push_back(read<V>());
			column_impl<N + 1>(t);
		}
	}

public:
	template <class... T> auto column(std::size_t h) const {
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
#define ins(...) inputs(std::string, __VA_ARGS__)
