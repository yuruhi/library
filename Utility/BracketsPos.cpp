#pragma once
#include <vector>
#include <string>
#include <stack>
#include <utility>
#include <cassert>

std::size_t BracketsPos(const std::string& s, std::size_t pos, char left = '(',
                        char right = ')') {
	assert(s[pos] == left);
	int p = 1;
	for (std::size_t i = pos + 1; i < s.size(); ++i) {
		if (s[i] == left) {
			p++;
		} else if (s[i] == right) {
			if (p == 1) {
				return i;
			}
			p--;
		}
	}
	return std::string::npos;
}

std::pair<std::size_t, std::size_t> BracketsPosPair(const std::string& s, std::size_t pos,
                                                    char left = '(', char right = ')') {
	std::size_t l = s.find(left, pos);
	if (l != std::string::npos) {
		std::size_t r = BracketsPos(s, l, left, right);
		if (r != std::string::npos) {
			return {l, r};
		} else {
			return {std::string::npos, std::string::npos};
		}
	} else {
		return {std::string::npos, std::string::npos};
	}
}

std::vector<int> AllBracketsPos(const std::string& s, char left = '(', char right = ')') {
	int n = s.size();
	std::vector<int> result(n, -1);
	std::stack<int> st;
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
