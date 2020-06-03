// shortcut : Imos
// description : いもす法
template<class T>class Imos {
	const int N;
	vector<T> table;
	bool flag = false;
public:
	Imos(int _n) :N(_n), table(_n + 1) {}
	void add(int l, int r, T v = 1) { // [l, r)
		assert(l < r&& r <= N);
		assert(!flag);
		table[l] += v;
		table[r] -= v;
	}
	void add(const pair<int, int>& section, T v = 1) {
		add(section.first, section.second, v);
	}
	void add_closed(int l, int r, T v = 1) {
		add(l, r + 1, v);
	}
	void add_closed(const pair<int, int>& section, T v = 1) {
		add_closed(section.first, section.second, v);
	}
	void build() {
		flag = true;
		for (int i = 1; i < N; ++i) {
			table[i] += table[i - 1];
		}
	}
	T operator[](int i)const {
		assert(flag);
		return table[i];
	}
	const vector<T>& operator*()const {
		assert(flag);
		return table;
	}
	vector<T> get_array()const {
		return vector<T>(table.begin(), table.begin() + N);
	}
};