#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_7_C"
#include "./../Utility/Scanner.cpp"
#include "./../Utility/Printer.cpp"
#include "./../Utility/Ruby.cpp"
#include <iostream>
using namespace std;

int main() {
	int h = in, w = in;
	vector<vector<int>> a = in[h][w];
	a << (a | Transpose | Map([](const auto& b) { return b | Sum; }));
	for (auto& v : a) {
		v << (v | Sum);
	}
	out(a);
}