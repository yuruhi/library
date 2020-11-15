#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include "./../DataStructure/PersistentQueue.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int q;
	cin >> q;
	vector<PersistentQueue<int>> s(q + 1);
	for (int i = 1; i <= q; ++i) {
		int com, t;
		cin >> com >> t;
		++t;
		if (com == 0) {
			int x;
			cin >> x;
			s[i] = s[t].push(x);
		} else {
			cout << s[t].front() << endl;
			s[i] = s[t].pop();
		}
	}
}