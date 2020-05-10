// shortcut : Imos
// description : いもす法
template<class T>class Imos {
	const int N;
	vector<T> table;
	bool flag = false;
public:
	Imos(int _n) :N(_n), table(_n + 1) {}
	// [l, r)
	void add(int l, int r, T v = 1) {
		assert(l < r&& r <= N);
		assert(!flag);
		table[l] += v;
		table[r] -= v;
	}
	void build() {
		flag = true;
		for (int i = 1; i < N; ++i) {
			table[i] += table[i - 1];
		}
	}
	T operator[](int i)const { assert(flag); return table[i]; }
	const vector<T>& operator*()const { assert(flag); return table; }
};