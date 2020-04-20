// shortcut : ReplaceAll
// description : s に含まれる t を u に置き換え
void replace_all(string& s, const string& t, const string& u) {
	size_t pos = s.find(t);
	while (pos != string::npos) {
		s.replace(pos, t.size(), u);
		pos = s.find(t, pos + u.size());
	}
}
string replaced_all(string s, const string& t, const string& u) {
	replace_all(s, t, u);
	return s;
}