#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "./../template.cpp"
#include <iostream>
using namespace std;

int main() {
	int t = in;
	for (int i : times(t)) {
		ll a = in, b = in;
		out(a + b);
	}
}
