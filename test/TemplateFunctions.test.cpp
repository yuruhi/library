#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "./../Utility/functions.cpp"
#include <iostream>
using namespace std;

int main() {
	static_assert(div_ceil(9, 3) == 3);
	static_assert(div_ceil(10, 3) == 4);
	static_assert(div_ceil(11, 3) == 4);
	static_assert(div_ceil(12, 3) == 4);
	static_assert(div_ceil(13, 3) == 5);
	static_assert(div_ceil(1000000000000000000ll, 3) == 333333333333333334ll);
	static_assert(div_ceil(3, 1000000000000000000ll) == 1);
	static_assert(div_ceil(1000000000000000000ll, 300000000000000000) == 4);

	static_assert(div_ceil2(9, 3) == 9);
	static_assert(div_ceil2(10, 3) == 12);
	static_assert(div_ceil2(11, 3) == 12);
	static_assert(div_ceil2(12, 3) == 12);
	static_assert(div_ceil2(13, 3) == 15);
	static_assert(div_ceil2(1000000000000000000ll, 3) == 1000000000000000002ll);
	static_assert(div_ceil2(3, 1000000000000000000ll) == 1000000000000000000ll);
	static_assert(div_ceil2(1000000000000000000ll, 300000000000000000) ==
	              1200000000000000000ll);

	static_assert(triangle(0) == 0);
	static_assert(triangle(1) == 1);
	static_assert(triangle(2) == 3);
	static_assert(triangle(3) == 6);
	static_assert(triangle(1000000000ll) == 500000000500000000ll);
	static_assert(triangle(4000000000ll) == 8000000002000000000ll);

	static_assert(nC2(0) == 0);
	static_assert(nC2(1) == 0);
	static_assert(nC2(2) == 1);
	static_assert(nC2(3) == 3);
	static_assert(nC2(1000000000ll) == 499999999500000000ll);
	static_assert(nC2(4000000000ll) == 7999999998000000000ll);

	static_assert(middle(-10, 10) == 0);
	static_assert(middle(10, 10) == 10);
	static_assert(middle(10, 15) == 12);
	static_assert(middle(0, 1000000000000000000ll) == 500000000000000000ll);
	static_assert(middle(1000000000000000000ll, 3000000000000000000ll) ==
	              2000000000000000000ll);

	static_assert(!in_range(-1, 0, 20));
	static_assert(in_range(0, 0, 20));
	static_assert(in_range(19, 0, 20));
	static_assert(!in_range(20, 0, 20));
	static_assert(!in_range(-1, 0, 1000000000000000000ll));
	static_assert(in_range(0, 0, 1000000000000000000ll));
	static_assert(in_range(999999999999999999ll, 0, 1000000000000000000ll));
	static_assert(!in_range(1000000000000000000ll, 0, 1000000000000000000ll));

	static_assert(!is_square(15));
	static_assert(is_square(16));
	static_assert(!is_square(17));
	static_assert(!is_square(996491788296388608ll));
	static_assert(is_square(996491788296388609ll));
	static_assert(!is_square(996491788296388610ll));

	static_assert(BIT<int>(0) == 1);
	static_assert(BIT<int>(1) == 2);
	static_assert(BIT(0) == 1);
	static_assert(BIT(1) == 2);
	static_assert(BIT(32) == 4294967296ll);
	static_assert(BIT(62) == 4611686018427387904ll);

	static_assert(Pow(0, 0) == 1);
	static_assert(Pow(1000000000000000000ll, 0) == 1);
	static_assert(Pow(0, 1) == 0);
	static_assert(Pow(1000000000000000000ll, 1) == 1000000000000000000ll);
	static_assert(Pow(2, 10) == 1024);
	static_assert(Pow(2ll, 62) == 4611686018427387904ll);
	static_assert(Pow(10, 9) == 1000000000);
	static_assert(Pow(10ll, 18) == 1000000000000000000ll);

	static_assert(Powmod(0, 0, 2) == 1);
	static_assert(Powmod(1000000000000000000ll, 0, 2ll) == 1);
	static_assert(Powmod(0, 1, 2) == 0);
	static_assert(Powmod(1000000000000000000ll, 1, 3ll) == 1);
	static_assert(Powmod(2, 10, 1000000000) == 1024);
	static_assert(Powmod(2ll, 998244353, 1000000007ll) == 213467670);
	static_assert(Powmod(10ll, 998244353998244353ll, 1000000007ll) == 821601853);
	static_assert(Powmod(998244353998244353ll, 998244353998244353ll, 1000000007ll) ==
	              55266312);

	static_assert(TEN<int>(0) == 1);
	static_assert(TEN<int>(1) == 10);
	static_assert(TEN<int>(9) == 1000000000);
	static_assert(TEN(0) == 1);
	static_assert(TEN(1) == 10);
	static_assert(TEN(9) == 1000000000);
	static_assert(TEN(18) == 1000000000000000000);

	cout << "Hello World" << endl;
}