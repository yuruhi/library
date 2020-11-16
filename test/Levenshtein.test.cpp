#define PROBLEM "https://yukicoder.me/problems/no/225"
#include "./../DP/Levenshtein.cpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	cout << Levenshtein(s, t) << '\n';
}