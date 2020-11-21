#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T> class Compress {
public:
	using value_type = T;

private:
	vector<value_type> v;
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
	template <class U> Compress& add(const vector<U>& a) {
		flag = false;
		for (const auto& i : a) add(i);
		return *this;
	}
	template <class U> Compress& add(const initializer_list<U>& a) {
		flag = false;
		for (const auto& v : a) add(v);
		return *this;
	}
	template <class U> Compress& operator<<(const U& a) {
		add(a);
		return *this;
	}
	void build() {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		flag = true;
	}
	int operator()(const value_type& x) const {
		assert(flag);
		return lower_bound(v.begin(), v.end(), x) - v.begin();
	}
	vector<int> operator()(const vector<value_type>& x) const {
		assert(flag);
		vector<int> res;
		res.reserve(x.size());
		for (const value_type& i : x)
			res.push_back(lower_bound(v.begin(), v.end(), i) - v.begin());
		return res;
	}
	int size() const {
		assert(flag);
		return v.size();
	}
	const vector<value_type>& operator*() const {
		assert(flag);
		return v;
	}
	const value_type& operator[](int i) const {
		assert(flag);
		return v[i];
	}
};
