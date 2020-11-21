#pragma once
#include "./PersistentArray.cpp"
#include <cassert>

template <class T> class PersistentQueue {
public:
	using value_type = T;
	using data_type = PersistentArray<value_type, 2>;

private:
	data_type data;
	size_t begin, end;  // [begin, end)
	PersistentQueue(const data_type& _data, size_t _begin, size_t _end)
	    : data(_data), begin(_begin), end(_end) {}

public:
	PersistentQueue() : data(), begin(0), end(0) {}
	bool empty() const {
		return begin == end;
	}
	size_t size() const {
		return end - begin;
	}
	value_type front() const {
		assert(!empty());
		return data[begin];
	}
	value_type back() const {
		assert(!empty());
		return data[end - 1];
	}
	value_type operator[](size_t i) const {
		assert(i < size());
		return data[begin + i];
	}
	value_type at(size_t i) const {
		return operator[](i);
	}
	PersistentQueue push(const T& val) const {
		return PersistentQueue(data.set(end, val), begin, end + 1);
	}
	PersistentQueue pop() const {
		assert(!empty());
		return PersistentQueue(data.set(begin, value_type()), begin + 1, end);
	}
};
