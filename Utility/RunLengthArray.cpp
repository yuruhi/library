// shortcut : RunLengthArray
// description : RunLength圧縮みたいに保持する配列
template<class value_type, class size_type = size_t>
class RunLengthArray {
	using T = value_type;
	using S = size_type;

	vector<T> value;
	vector<pair<S, S>> index; // [first, second)

	size_t find(S i) {
		int left = 0, right = value.size();
		while (right - left > 1) {
			int mid = left + (right - left) / 2;
			(index[mid].first <= i ? left : right) = mid;
		}
		return left;
	}

public:
	RunLengthArray() {}
	RunLengthArray(const T& val, S size) :value({ val }), index({ {0,size} }) {}
	RunLengthArray(const initializer_list<pair<S, T>>& v) {
		index.reserve(v.size());
		value.reserve(v.size());
		S now = 0;
		for (const auto& p : v) {
			index.emplace_back(now, now + p.first);
			value.push_back(p.second);
			now += p.first;
		}
	}
	S size()const { return empty() ? 0 : index.back().second; }
	bool empty()const { return value.empty() || index.empty(); }
	explicit operator bool()const { return !empty(); }

	const T& operator[](const S i)const {
		assert(i < size());
		return value[find(i)];
	}
	const T& front()const {
		assert(!empty());
		return value.front();
	}
	const T& back()const {
		assert(!empty());
		return value.back();
	}

	pair<T, S> at(const size_t i)const {
		return make_pair(value[i], index[i].second - index[i].first);
	}
	size_t value_size()const {
		return value.size();
	}

	void clear() { value.clear(); index.clear(); }
	RunLengthArray& push_back(const T& val, const S new_size = 1) {
		if (empty() || value.back() != val) {
			value.push_back(val);
			index.emplace_back(size(), size() + new_size);
		} else {
			index.back().second += new_size;
		}
		return *this;
	}
	RunLengthArray& pop_back(const S pop_size = 1) {
		assert(pop_size <= size());
		S until = size() - pop_size;
		while (!empty()) {
			if (index.back().first == until) {
				value.pop_back();
				index.pop_back();
				break;
			} else if (index.back().first <= until && until < index.back().second) {
				index.back().second = until;
				break;
			} else {
				value.pop_back();
				index.pop_back();
			}
		}
		return *this;
	}
};