#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2880"
#include "./../DataStructure/RangeSet.cpp"
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

struct Data {
	bool query;
	int a, b, i;
	Data() = default;
	Data(bool _q, int _a, int _b, int _i) : query(_q), a(_a), b(_b), i(_i) {}
	friend bool operator<(const Data& d1, const Data& d2) {
		return !d1.query < !d2.query;
	}
};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m, q;
	cin >> n >> m >> q;
	map<int, vector<Data>> data_map;
	for (int i = 0; i < m; ++i) {
		int d, a, b;
		cin >> d >> a >> b;
		data_map[d].emplace_back(false, a, b, i);
	}
	for (int i = 0; i < q; ++i) {
		int e, s, t;
		cin >> e >> s >> t;
		data_map[e].emplace_back(true, s, t, i);
	}

	vector<bool> ans(q);
	RangeSet<int> range_set;
	for (auto [time, datas] : data_map) {
		sort(datas.begin(), datas.end());
		for (const Data& data : datas) {
			if (data.query) {
				if (data.a < data.b) {
					ans[data.i] = range_set.contains(data.a, data.b - 1);
				} else {
					ans[data.i] = true;
				}
			} else {
				range_set.insert(data.a, data.b - 1);
			}
		}
	}
	for (bool f : ans) {
		cout << (f ? "Yes" : "No") << '\n';
	}
}