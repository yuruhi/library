// shortcut : ZAlgorithm
// description : res[i] := S と S[i:] の最長共通接頭辞
template <class T> vector<int> ZAlgorithm(const T &s) {
	int n = s.size(), i = 1, j = 0;
	vector<int> res(n);
	res[0] = n;
	while (i < n) {
		while (i + j < n && s[j] == s[i + j]) j++;
		res[i] = j;
		if (j == 0) {
			i++;
			continue;
		}
		int k = 1;
		while (i + k < n && k + res[k] < j) {
			res[i + k] = res[k];
			k++;
		}
		i += k;
		j -= k;
	}
	return res;
}