// shortcut : BracketsPos
// description : 対応する括弧の場所
size_t BracketsPos(const string &s, size_t pos, char c1 = '(', char c2 = ')') {
	assert(s[pos] == c1);
	int p = 1;
	for (size_t i = pos + 1; i < s.size(); ++i) {
		if (s[i] == c1) {
			p++;
		} else if (s[i] == c2) {
			if (p == 1) {
				return i;
			}
			p--;
		}
	}
	return string::npos;
}

pair<size_t, size_t> BracketsPos2(const string &s, size_t pos, char c1 = '(', char c2 = ')') {
	size_t l = s.find(c1, pos);
	if (l != string::npos) {
		size_t r = BracketsPos(s, l, c1, c2);
		if (r != string::npos) {
			return {l, r};
		} else {
			return {string::npos, string::npos};
		}
	} else {
		return {string::npos, string::npos};
	}
}

vector<int> AllBracketsPos(const string &s, char c1 = '(', char c2 = ')') {
	int n = s.size();
	vector<int> res(n, -1);
	stack<int> st;
	rep(i, n) {
		if (s[i] == c1) {
			st.push(i);
		} else if (s[i] == c2) {
			assert(st.size());
			res[st.top()] = i;
			st.pop();
		}
	}
	return res;
}