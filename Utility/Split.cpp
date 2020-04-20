// shortcut : Split
// description : split
vector<string> Split(const string& s, char c) {
	vector<string> res;
	for (size_t l = 0, i = 0; i <= s.size(); ++i) {
		if (i == s.size() || s[i] == c) {
			res.push_back(s.substr(l, i - l));
			l = i + 1;
		}
	}
	return res;
}