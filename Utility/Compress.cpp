#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

template <class T> class Compress {
public:
	using value_type = T;

private:
	std::vector<value_type> v;
	bool flag = false;

public:
	Compress() {}
	template <class U> Compress(const U& a) {
		add(a);
	}
	Compress& add(const value_type& a) {
		flag = false;
		v.push_back(a);
		return *this;
	}
	template <class U> Compress& add(const std::vector<U>& a) {
		flag = false;
		for (const auto& i : a) add(i);
		return *this;
	}
	template <class U> Compress& add(const std::initializer_list<U>& a) {
		flag = false;
		for (const auto& v : a) add(v);
		return *this;
	}
	template <class U> Compress& operator<<(const U& a) {
		add(a);
		return *this;
	}
	void build() {
		std::sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		flag = true;
	}
	int operator()(const value_type& x) const {
		assert(flag);
		return std::lower_bound(v.begin(), v.end(), x) - v.begin();
	}
	std::vector<int> operator()(const std::vector<value_type>& x) const {
		assert(flag);
		std::vector<int> result;
		result.reserve(x.size());
		for (const value_type& i : x) {
			result.push_back(std::lower_bound(v.begin(), v.end(), i) - v.begin());
		}
		return result;
	}
	int lower(const value_type& x) const {
		assert(flag);
		return std::lower_bound(v.begin(), v.end(), x) - v.begin();
	}
	int upper(const value_type& x) const {
		assert(flag);
		return std::upper_bound(v.begin(), v.end(), x) - v.begin();
	}
	int size() const {
		assert(flag);
		return v.size();
	}
	const std::vector<value_type>& operator*() const {
		assert(flag);
		return v;
	}
	const value_type& operator[](int i) const {
		assert(flag);
		return v[i];
	}
};
