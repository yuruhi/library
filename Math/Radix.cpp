// description : N進数変換
class Radix {
	using Type = long long;
	static string Str;
	static map<char, int> Map;

public:
	static void Init(string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
		Str = s;
		for (int i = 0; i < (int)Str.size(); i++) {
			Map[Str[i]] = i;
		}
	}
	// Num(R) -> res(10)
	static Type to10(const string& Num, int R) {
		Type res = 0, p = 1;
		for (int i = (int)Num.size() - 1; i >= 0; --i) {
			assert(Map.count(Num[i]));
			res += Map[Num[i]] * p;
			p *= R;
		}
		return res;
	}
	// Num(10) -> res(N)
	static string toN(Type Num, int N) {
		string res;
		Type m = Num;
		do {
			res += Str[m % N];
			m /= N;
		} while (m);
		reverse(res.begin(), res.end());
		return res;
	}
	// Num(R) -> res(N)
	static string toN(const string& Num, int R, int N) {
		return toN(to10(Num, R), N);
	}
};
string Radix::Str;
map<char, int> Radix::Map;