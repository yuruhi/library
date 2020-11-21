#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

class Radix {
public:
	using value_type = long long;

private:
	static string Str;
	static map<char, int> Map;

public:
	static void Init(string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
		Str = s;
		for (int i = 0; i < (int)Str.size(); i++) {
			Map[Str[i]] = i;
		}
	}
	// value(R) -> res(10)
	static value_type to10(const string& value, int R) {
		value_type res = 0, p = 1;
		for (int i = (int)value.size() - 1; i >= 0; --i) {
			assert(Map.count(value[i]));
			res += Map[value[i]] * p;
			p *= R;
		}
		return res;
	}
	// value(10) -> res(N)
	static string toN(value_type value, int N) {
		string res;
		value_type m = value;
		do {
			res += Str[m % N];
			m /= N;
		} while (m);
		reverse(res.begin(), res.end());
		return res;
	}
	// value(R) -> res(N)
	static string toN(const string& value, int R, int N) {
		return toN(to10(value, R), N);
	}
};
string Radix::Str;
map<char, int> Radix::Map;
