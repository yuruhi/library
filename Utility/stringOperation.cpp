// description : std::string の操作
void replace_all(string &s, const string &t, const string &u) {
	size_t pos = s.find(t);
	while (pos != string::npos) {
		s.replace(pos, t.size(), u);
		pos = s.find(t, pos + u.size());
	}
}
string replaced_all(string s, const string &t, const string &u) {
	replace_all(s, t, u);
	return s;
}
vector<string> Split(string s, const string &t) {
	vector<string> res;
	for (size_t p = 0; (p = s.find(t)) != string::npos;) {
		res.emplace_back(s.begin(), s.begin() + p);
		s = s.substr(p + t.size());
	}
	res.push_back(s);
	return res;
}