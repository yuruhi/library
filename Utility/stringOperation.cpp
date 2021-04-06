#pragma once
#include <vector>
#include <string>

void replace_all(std::string& s, const std::string& t, const std::string& u) {
	std::size_t pos = s.find(t);
	while (pos != std::string::npos) {
		s.replace(pos, t.size(), u);
		pos = s.find(t, pos + u.size());
	}
}
std::string replaced_all(std::string s, const std::string& t, const std::string& u) {
	replace_all(s, t, u);
	return s;
}
std::vector<std::string> Split(std::string s, const std::string& t) {
	std::vector<std::string> result;
	for (std::size_t p = 0; (p = s.find(t)) != std::string::npos;) {
		result.emplace_back(s.begin(), s.begin() + p);
		s = s.substr(p + t.size());
	}
	result.push_back(s);
	return result;
}
