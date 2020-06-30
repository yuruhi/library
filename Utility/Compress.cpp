// shortcut : Compress
// description : 座標圧縮
template <class T> class Compress {
	vector<T> v;
	bool flag = false;

public:
	Compress() {}
	template <class U> Compress(const U &a) {
		add(a);
	}
	Compress &add(const T &a) {
		flag = false;
		v.push_back(a);
		return *this;
	}
	template <class U> Compress &add(const vector<U> &a) {
		flag = false;
		for (const auto &i : a) add(i);
		return *this;
	}
	template <class U> Compress &add(const initializer_list<U> &a) {
		flag = false;
		for (const auto &v : a) add(v);
		return *this;
	}
	template <class U> Compress &operator<<(const U &a) {
		add(a);
		return *this;
	}
	void build() {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		flag = true;
	}
	int operator()(const T &x) const {
		assert(flag);
		return lower_bound(v.begin(), v.end(), x) - v.begin();
	}
	vector<int> operator()(const vector<T> &x) const {
		assert(flag);
		vector<int> res;
		res.reserve(x.size());
		for (const T &i : x) res.push_back(lower_bound(v.begin(), v.end(), i) - v.begin());
		return res;
	}
	int size() const {
		assert(flag);
		return v.size();
	}
	const vector<T> &operator*() const {
		assert(flag);
		return v;
	}
	const T &operator[](int i) const {
		assert(flag);
		return v[i];
	}
};