#pragma once
#include <vector>
#include <initializer_list>
#include <utility>
#include <cassert>

template <class value_type, class size_type = std::size_t> class RunLengthArray {
	std::vector<value_type> value;
	std::vector<std::pair<size_type, size_type>> index;  // [first, second)

	std::size_t find(size_type i) {
		int left = 0, right = value.size();
		while (right - left > 1) {
			int mid = left + (right - left) / 2;
			(index[mid].first <= i ? left : right) = mid;
		}
		return left;
	}

public:
	RunLengthArray() {}
	RunLengthArray(const value_type& val, size_type size) : value({val}), index({{0, size}}) {}
	RunLengthArray(const std::initializer_list<std::pair<size_type, value_type>>& v) {
		index.reserve(v.size());
		value.reserve(v.size());
		size_type now = 0;
		for (const auto& p : v) {
			index.emplace_back(now, now + p.first);
			value.push_back(p.second);
			now += p.first;
		}
	}
	size_type size() const {
		return empty() ? 0 : index.back().second;
	}
	bool empty() const {
		return value.empty() || index.empty();
	}
	explicit operator bool() const {
		return !empty();
	}

	const value_type& operator[](const size_type i) const {
		assert(i < size());
		return value[find(i)];
	}
	const value_type& front() const {
		assert(!empty());
		return value.front();
	}
	const value_type& back() const {
		assert(!empty());
		return value.back();
	}

	auto at(const std::size_t i) const {
		return std::pair(value[i], index[i].second - index[i].first);
	}
	std::size_t value_size() const {
		return value.size();
	}

	void clear() {
		value.clear();
		index.clear();
	}
	RunLengthArray& push_back(const value_type& val, const size_type new_size = 1) {
		if (empty() || value.back() != val) {
			value.push_back(val);
			index.emplace_back(size(), size() + new_size);
		} else {
			index.back().second += new_size;
		}
		return *this;
	}
	RunLengthArray& pop_back(const size_type pop_size = 1) {
		assert(pop_size <= size());
		size_type until = size() - pop_size;
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
