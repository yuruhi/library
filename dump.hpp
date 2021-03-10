#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <cassert>
#include <climits>
#ifdef __cpp_lib_optional
#include <optional>
#endif

namespace Debug {
	struct AtFirst {
		AtFirst() {
			std::cerr << std::fixed << std::setprecision(6);
		}
	};
	AtFirst at_first;

	const std::string BeginLine = "..|", EndLine = "\n" + BeginLine;
	const std::string Begin = "{ ", End = " }";
	const std::string Empty = "{ empty }", Separate = ", ", Indent = "  ";
	const std::string True = "O", False = "X";
	void FirstLine(int line, std::string func) {
		std::cerr << BeginLine + std::string(15, '-') << line << " : " << func
		          << std::string(15, '-') << EndLine;
	}

	template <class T> void DebugPrint(const T& v);
	void DebugPrint(const int v);
	void DebugPrint(const long long v);
	void DebugPrint(const bool v);
	void DebugPrint(const char v);
	void DebugPrint(const char* v);
	void DebugPrint(const std::string& v);
	template <class T, class U> void DebugPrint(const std::pair<T, U>& v);
#ifdef __cpp_lib_optional
	template <class T> void DebugPrint(const std::optional<T>& v);
#endif
#ifdef __cpp_if_constexpr
	template <std::size_t N = 0, class T> void print_tuple_impl(const T& v);
	template <class... T> void DebugPrint(const std::tuple<T...>& v);
#endif
	template <class T> void DebugPrint(const std::vector<T>& v);
	template <class T, std::size_t N> void DebugPrint(const std::array<T, N>& v);
	template <class T> void DebugPrint(const std::vector<std::vector<T>>& v);
	template <class T, class U> void DebugPrint(const std::map<T, U>& v);
	template <class T> void DebugPrint(const std::set<T>& v);
	template <class T> void DebugPrint(const std::multiset<T>& v);
	template <class T> void DebugPrint(const std::unordered_set<T>& v);
	template <class T> void DebugPrint(const std::list<T>& v);
	template <class T> void DebugPrint(std::stack<T> v);
	template <class T> void DebugPrint(std::queue<T> v);
	template <class T, class U, class V> void DebugPrint(std::priority_queue<T, U, V> v);
	template <class T> void DebugPrint(std::deque<T> v);

	template <class T> void DebugPrint(const T& v) {
		std::cerr << v;
	}
	void DebugPrint(const int v) {
		if (v == INT_MAX) {
			std::cerr << "MAX";
		} else if (v == INT_MIN) {
			std::cerr << "MIN";
		} else {
			std::cerr << v;
		}
	}
	void DebugPrint(const long long v) {
		if (v == LLONG_MAX) {
			std::cerr << "MAX";
		} else if (v == LLONG_MIN) {
			std::cerr << "MIN";
		} else {
			std::cerr << v;
		}
	}
	void DebugPrint(const bool v) {
		std::cerr << (v ? True : False);
	}
	void DebugPrint(const char v) {
		std::cerr << '\'' << v << '\'';
	}
	void DebugPrint(const char* v) {
		std::cerr << '\"' << v << '\"';
	}
	void DebugPrint(const std::string& v) {
		std::cerr << '\"' << v << '\"';
	}
	template <class T, class U> void DebugPrint(const std::pair<T, U>& v) {
		std::cerr << "(";
		DebugPrint(v.first);
		std::cerr << ", ";
		DebugPrint(v.second);
		std::cerr << ")";
	}
#ifdef __cpp_lib_optional
	template <class T> void DebugPrint(const std::optional<T>& v) {
		if (v) {
			DebugPrint(*v);
		} else {
			std::cerr << '-';
		}
	}
#endif
#ifdef __cpp_if_constexpr
	template <std::size_t N = 0, class T> void print_tuple_impl(const T& v) {
		if constexpr (N < std::tuple_size_v<T>) {
			DebugPrint(std::get<N>(v));
			if constexpr (N < std::tuple_size_v<T> - 1) {
				std::cerr << Separate;
			}
			print_tuple_impl<N + 1>(v);
		}
	}
	template <class... T> void DebugPrint(const std::tuple<T...>& v) {
		std::cerr << Begin;
		print_tuple_impl(v);
		std::cerr << End;
	}
#endif
	template <class T> void DebugPrint(const std::vector<T>& v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin;
			for (std::size_t i = 0; i < v.size(); ++i) {
				if (i) std::cerr << Separate;
				DebugPrint(v[i]);
			}
			std::cerr << End;
		}
	}
	template <class T, std::size_t N> void DebugPrint(const std::array<T, N>& v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin;
			for (std::size_t i = 0; i < N; ++i) {
				if (i) std::cerr << Separate;
				DebugPrint(v[i]);
			}
			std::cerr << End;
		}
	}
	template <class T> void DebugPrint(const std::vector<std::vector<T>>& v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin << EndLine;
			for (std::size_t i = 0; i < v.size(); i++) {
				std::cerr << Indent << "[" << i << "] ";
				DebugPrint(v[i]);
				std::cerr << EndLine;
			}
			std::cerr << End;
		}
	}
	template <class T, class U> void DebugPrint(const std::map<T, U>& v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin << EndLine;
			for (const auto& i : v) {
				std::cerr << Indent;
				DebugPrint(i.first);
				std::cerr << " : ";
				DebugPrint(i.second);
				std::cerr << EndLine;
			}
			std::cerr << End;
		}
	}
	template <class T> void DebugPrint(const std::set<T>& v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin;
			for (auto it = v.begin(); it != v.end(); ++it) {
				if (it != v.begin()) std::cerr << Separate;
				DebugPrint(*it);
			}
			std::cerr << End;
		}
	}
	template <class T> void DebugPrint(const std::multiset<T>& v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin;
			for (auto it = v.begin(); it != v.end(); ++it) {
				if (it != v.begin()) std::cerr << Separate;
				DebugPrint(*it);
			}
			std::cerr << End;
		}
	}
	template <class T> void DebugPrint(const std::unordered_set<T>& v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin;
			for (auto it = v.begin(); it != v.end(); ++it) {
				if (it != v.begin()) std::cerr << Separate;
				DebugPrint(*it);
			}
			std::cerr << End;
		}
	}
	template <class T> void DebugPrint(const std::list<T>& v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin;
			for (auto it = v.begin(); it != v.end(); ++it) {
				if (it != v.begin()) std::cerr << Separate;
				DebugPrint(*it);
			}
			std::cerr << End;
		}
	}
	template <class T> void DebugPrint(std::stack<T> v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin;
			while (!v.empty()) {
				DebugPrint(v.top());
				v.pop();
				if (!v.empty()) std::cerr << Separate;
			}
			std::cerr << End;
		}
	}
	template <class T> void DebugPrint(std::queue<T> v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin;
			while (!v.empty()) {
				DebugPrint(v.front());
				v.pop();
				if (!v.empty()) std::cerr << Separate;
			}
			std::cerr << End;
		}
	}
	template <class T, class U, class V> void DebugPrint(std::priority_queue<T, U, V> v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin;
			while (!v.empty()) {
				DebugPrint(v.top());
				v.pop();
				if (!v.empty()) std::cerr << Separate;
			}
			std::cerr << End;
		}
	}
	template <class T> void DebugPrint(std::deque<T> v) {
		if (v.empty()) {
			std::cerr << Empty;
		} else {
			std::cerr << Begin;
			while (!v.empty()) {
				DebugPrint(v.front());
				v.pop_front();
				if (!v.empty()) std::cerr << Separate;
			}
			std::cerr << End;
		}
	}

	std::queue<std::string> Name;
	void SetName(const std::string& s) {
		int par = 0;
		std::string name;
		for (size_t i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '{' ||
			    (s[i] == '<' && s[i + 1] != '=' && s[i - 1] != ' ' && s[i + 1] != ' ')) {
				par++;
			} else if (s[i] == ')' || s[i] == '}' ||
			           (s[i] == '>' && s[i + 1] != '=' && s[i - 1] != ' ' &&
			            s[i + 1] != ' ')) {
				par--;
			}
			if (!par && s[i] == ',') {
				Name.push(name.front() == ' ' ? name.substr(1) : name);
				name.clear();
			} else {
				name += s[i];
			}
		}
		Name.push(name.front() == ' ' ? name.substr(1) : name);
	}

	template <class Head> void Dump(Head&& h) {
		assert(!Name.empty());
		std::cerr << Name.front() << " = ";
		DebugPrint(h);
		std::cerr << "\n";
		Name.pop();
	}
	template <class Head, class... Tail> void Dump(Head&& h, Tail&&... t) {
		assert(!Name.empty());
		std::cerr << Name.front() << " = ";
		DebugPrint(h);
		std::cerr << EndLine;
		Name.pop();
		Dump(std::forward<Tail>(t)...);
	}
};  // namespace Debug

#define dump(...)                                 \
	do {                                          \
		Debug::FirstLine(__LINE__, __FUNCTION__); \
		Debug::SetName(#__VA_ARGS__);             \
		Debug::Dump(__VA_ARGS__);                 \
	} while (false)

#define dump2(...)                    \
	do {                              \
		Debug::SetName(#__VA_ARGS__); \
		Debug::Dump(__VA_ARGS__);     \
	} while (false)
