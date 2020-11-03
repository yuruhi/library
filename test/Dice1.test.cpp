#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_A"
#include "./../Utility/Dice.cpp"
#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	string s;
	cin >> s;
	Dice dice(a, b, c, d, e, f);
	for (char c : s) {
		dice.roll(c);
	}
	cout << dice.top << endl;
}