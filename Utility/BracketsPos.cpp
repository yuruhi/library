#pragma once
#include <vector>
#include <string>
#include <stack>
#include <utility>
#include <cassert>
using namespace std;

size_t BracketsPos(const string& s, size_t pos, char left = '(', char right = ')') {
	assert(s[pos] == left);
	int p = 1;
	for (size_t i = pos + 1; i < s.size(); ++i) {
		if (s[i] == left) {
			p++;
		} else if (s[i] == right) {
			if (p == 1) {
				return i;
			}
			p--;
		}
	}
	return string::npos;
}

pair<size_t, size_t> BracketsPosPair(const string& s, size_t pos, char left = '(',
                                     char right = ')') {
	size_t l = s.find(left, pos);
	if (l != string::npos) {
		size_t r = BracketsPos(s, l, left, right);
		if (r != string::npos) {
			return {l, r};
		} else {
			return {string::npos, string::npos};
		}
	} else {
		return {string::npos, string::npos};
	}
}

vector<int> AllBracketsPos(const string& s, char left = '(', char right = ')') {
	int n = s.size();
	vector<int> result(n, -1);
	stack<int> st;
	for (int i = 0; i < n; ++i) {
		if (s[i] == left) {
			st.push(i);
		} else if (s[i] == right) {
			assert(st.size());
			result[st.top()] = i;
			st.pop();
		}
	}
	return result;
}
