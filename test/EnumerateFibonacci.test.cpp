#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A"
#include "./../math/Fibonacci.cpp"
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << EnumerateFibonacci<long long>(n + 1)[n + 1] << '\n';
}