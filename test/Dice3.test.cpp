#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_C"
#include "./../Utility/Dice.cpp"
#include <iostream>
using namespace std;

int main() {
	Dice d1, d2;
	cin >> d1 >> d2;
	cout << (d1.same(d2) ? "Yes" : "No") << endl;
}