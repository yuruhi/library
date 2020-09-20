// description : { 1,2,3,2,1,2,1 } -> { [0-2], [2-4], [4-5], [5-6] }
vector<Range> split(const vector<int>& v) {
	int n = v.size();
	vector<Range> res;
	if (n <= 1) {
		res.emplace_back(0, n - 1);
		return res;
	}
	int x = 0;
	bool flag = v[0] < v[1];
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || !((flag && v[i] < v[i + 1]) || (!flag && v[i] > v[i + 1]))) {
			flag = flag ? false : true;
			res.emplace_back(x, i);
			x = i;
		}
	}
	return res;
}