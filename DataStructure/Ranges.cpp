// description : 区間を保持するデータ構造
template <class T> class Ranges {
	set<pair<T, bool>> s;

public:
	bool empty() const {
		return s.empty();
	}
	int size() const {
		return s.size() / 2;
	}
	void clear() const {
		s.clear();
	}
	const auto& operator*() const {
		return s;
	}
	bool cover(const T& x) const {
		auto it = s.upper_bound(make_pair(x, false));
		return it != s.end() && s.upper_bound(make_pair(x, false))->second;
	}
	bool add(const T& x) {
		if (cover(x)) return false;
		auto it = s.upper_bound(make_pair(x, false));
		bool flag1 = it != s.begin() && prev(it)->first + 1 == x;
		bool flag2 = it != s.end() && it->first - 1 == x;
		if (flag1 && flag2) {
			s.erase(prev(it), next(it));
		} else if (flag1) {
			s.erase(prev(it));
			s.emplace(x, true);
		} else if (flag2) {
			s.erase(it);
			s.emplace(x, false);
		} else {
			s.emplace(x, false);
			s.emplace(x, true);
		}
		return true;
	}
	bool add(const initializer_list<T>& init) {
		bool res = false;
		for (const T& x : init) {
			res |= add(x);
		}
		return res;
	}
	bool erase(const T& x) {
		if (!cover(x)) return false;
		auto it = s.upper_bound(make_pair(x, false));
		bool flag1 = prev(it)->first == x;
		bool flag2 = it->first == x;
		if (flag1 && flag2) {
			s.erase(prev(it), next(it));
		} else if (flag1) {
			s.erase(prev(it));
			s.emplace(x + 1, false);
		} else if (flag2) {
			s.erase(it);
			s.emplace(x - 1, true);
		} else {
			s.emplace(x - 1, true);
			s.emplace(x + 1, false);
		}
		return true;
	}
	bool erase(const initializer_list<T>& init) {
		bool res = false;
		for (const T& x : init) {
			res |= erase(x);
		}
		return res;
	}
	T get_next(const T& x) const {
		if (!cover(x)) return x;
		auto it = s.upper_bound(make_pair(x, false));
		return it->first + 1;
	}
	T get_prev(const T& x) const {
		if (!cover(x)) return x;
		auto it = s.upper_bound(make_pair(x, false));
		return prev(it)->first - 1;
	}
};
template <class T> ostream& operator<<(ostream& os, const Ranges<T>& r) {
	const auto& v = *r;
	bool first = true;
	for (auto it = v.begin(); it != v.end(); advance(it, 2)) {
		os << (exchange(first, false) ? "" : ", ") << '[' << it->first << ", " << next(it)->first << ']';
	}
	return os;
}