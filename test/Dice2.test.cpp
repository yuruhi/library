#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_B"
#include "./../Utility/Dice.cpp"
#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	Dice dice(a, b, c, d, e, f);
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (dice.left == a) dice.roll_right();
		if (dice.right == a) dice.roll_left();
		while (dice.top != a)
			dice.roll_front();
		while (dice.front != b)
			dice.rotate_left();
		cout << dice.right << endl;
	}
}