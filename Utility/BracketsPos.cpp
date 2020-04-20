// shortcut : BracketsPos
// description : 対応する括弧の場所
pair<int, int> BracketsPos(const string& s, size_t pos, char c1 = '(', char c2 = ')') {
	size_t be = s.find(c1, pos);
	if (be == string::npos)return { be,string::npos };
	int par = 1;
	for (size_t i = be + 1; i < s.size(); ++i) {
		if (s[i] == c1) {
			par++;
		} else if (s[i] == c2) {
			if (par == 1)return { be,i };
			par--;
		}
	}
	return { string::npos,string::npos };
}