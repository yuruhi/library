#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <cassert>
#include <climits>
#include <optional>
using namespace std;

namespace Debug {

	struct AtFirst {
		AtFirst() { cerr << fixed << setprecision(6); }
	};
	//AtFirst at_first;

	string BeginLine = "..|", EndLine = "\n" + BeginLine;
	string Begin = "{ ", End = " }";
	string Empty = "{ empty }", Separate = ", ", Indent = "  ";
	string True = "O", False = "X";
	void FirstLine(int line, string func) {
		cerr << BeginLine + string(15, '-') << line << " : " << func << string(15, '-') << EndLine;
	}

	template<class T>void DebugPrint(const T& v);
	void DebugPrint(const int v);
	void DebugPrint(const long long v);
	void DebugPrint(const bool v);
	void DebugPrint(const char v);
	void DebugPrint(const char* v);
	void DebugPrint(const string& v);
	template<class T, class U>void DebugPrint(const pair<T, U>& v);
	template<class T>void DebugPrint(const optional<T>& v);
	template<class T>void DebugPrint(const vector<T>& v);
	template<class T, size_t N>void DebugPrint(const array<T, N>& v);
	template<class T>void DebugPrint(const vector<vector<T>>& v);
	template<class T, class U>void DebugPrint(const map<T, U>& v);
	template<class T>void DebugPrint(const set<T>& v);
	template<class T>void DebugPrint(const multiset<T>& v);
	template<class T>void DebugPrint(const list<T>& v);
	template<class T>void DebugPrint(stack<T> v);
	template<class T>void DebugPrint(queue<T> v);
	template<class T, class U, class V>void DebugPrint(priority_queue<T, U, V> v);
	template<class T>void DebugPrint(deque<T> v);

	template<class T>void DebugPrint(const T& v) { cerr << v; }
	void DebugPrint(const int v) {
		if (v == inf || v == INT_MAX) {
			cerr << "MAX";
		} else if (v == -inf || v == INT_MIN) {
			cerr << "MIN";
		} else {
			cerr << v;
		}
	}
	void DebugPrint(const long long v) {
		if (v == inf_ll || v == LLONG_MAX) {
			cerr << "MAX";
		} else if (v == -inf_ll || v == LLONG_MIN) {
			cerr << "MIN";
		} else {
			cerr << v;
		}
	}
	void DebugPrint(const bool v) { cerr << (v ? True : False); }
	void DebugPrint(const char v) { cerr << '\'' << v << '\''; }
	void DebugPrint(const char* v) { cerr << '\"' << v << '\"'; }
	void DebugPrint(const string& v) { cerr << '\"' << v << '\"'; }
	template<class T, class U>void DebugPrint(const pair<T, U>& v) {
		cerr << "(";
		DebugPrint(v.first); cerr << ", "; DebugPrint(v.second);
		cerr << ")";
	}
	template<class T>void DebugPrint(const optional<T>& v) {
		if (v) { DebugPrint(*v); } else { cerr << '-'; }
	}
	template<class T>void DebugPrint(const vector<T>& v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin;
			for (int i = 0; i < (int)v.size(); ++i) {
				if (i)cerr << Separate; DebugPrint(v[i]);
			}
			cerr << End;
		}
	}
	template<class T, size_t N>void DebugPrint(const array<T, N>& v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin;
			for (int i = 0; i < N; ++i) {
				if (i)cerr << Separate; DebugPrint(v[i]);
			}
			cerr << End;
		}
	}
	template<class T>void DebugPrint(const vector<vector<T>>& v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin << EndLine;
			for (int i = 0; i < (int)v.size(); i++) {
				cerr << Indent << "[" << i << "] "; DebugPrint(v[i]); cerr << EndLine;
			}
			cerr << End;
		}
	}
	template<class T, class U>void DebugPrint(const map<T, U>& v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin << EndLine;
			for (const auto& i : v) {
				cerr << Indent;
				DebugPrint(i.first); cerr << " : ";
				DebugPrint(i.second); cerr << EndLine;
			}
			cerr << End;
		}
	}
	template<class T>void DebugPrint(const set<T>& v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin;
			for (auto it = v.begin(); it != v.end(); ++it) {
				if (it != v.begin())cerr << Separate; DebugPrint(*it);
			}
			cerr << End;
		}
	}
	template<class T>void DebugPrint(const multiset<T>& v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin;
			for (auto it = v.begin(); it != v.end(); ++it) {
				if (it != v.begin())cerr << Separate; DebugPrint(*it);
			}
			cerr << End;
		}
	}
	template<class T>void DebugPrint(const list<T>& v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin;
			for (auto it = v.begin(); it != v.end(); ++it) {
				if (it != v.begin())cerr << Separate; DebugPrint(*it);
			}
			cerr << End;
		}
	}
	template<class T>void DebugPrint(stack<T> v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin;
			while (!v.empty()) {
				DebugPrint(v.top()); v.pop(); if (!v.empty())cerr << Separate;
			}
			cerr << End;
		}
	}
	template<class T>void DebugPrint(queue<T> v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin;
			while (!v.empty()) {
				DebugPrint(v.front()); v.pop(); if (!v.empty())cerr << Separate;
			}
			cerr << End;
		}
	}
	template<class T, class U, class V>void DebugPrint(priority_queue<T, U, V> v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin;
			while (!v.empty()) {
				DebugPrint(v.top()); v.pop(); if (!v.empty())cerr << Separate;
			}
			cerr << End;
		}
	}
	template<class T>void DebugPrint(deque<T> v) {
		if (v.empty()) {
			cerr << Empty;
		} else {
			cerr << Begin;
			while (!v.empty()) {
				DebugPrint(v.front()); v.pop_front(); if (!v.empty())cerr << Separate;
			}
			cerr << End;
		}
	}

	queue<string> Name;
	void SetName(const string& s) {
		int size = s.size(), par = 0;
		string name;
		for (int i = 0; i < size; i++) {
			if (s[i] == '(' || s[i] == '{' ||
				(s[i] == '<' && s[i + 1] != '=' && s[i - 1] != ' ' && s[i + 1] != ' ')) {
				par++;
			} else if (s[i] == ')' || s[i] == '}' ||
				(s[i] == '>' && s[i + 1] != '=' && s[i - 1] != ' ' && s[i + 1] != ' ')) {
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
	template<class H>void Dump(H&& h) {
		assert(!Name.empty());
		cerr << Name.front() << " = "; DebugPrint(h); cerr << endl;
		Name.pop();
	}
	template<class H, class... T>void Dump(H&& h, T&& ...t) {
		assert(!Name.empty());
		cerr << Name.front() << " = "; DebugPrint(h); cerr << EndLine;
		Name.pop(); Dump(forward<T>(t)...);
	}
};

#define dump(...)									\
	do {											\
		Debug::FirstLine(__LINE__, __FUNCTION__);	\
		Debug::SetName(#__VA_ARGS__);				\
		Debug::Dump(__VA_ARGS__);					\
	} while (false)