#pragma once
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>

template <class T> class step_iterator {
public:
	using value_type = T;
	using difference_type = T;
	using iterator_category = std::random_access_iterator_tag;
	using reference = T&;
	using pointer = T*;

private:
	value_type start_m, size_m, step_m, index_m;

public:
	constexpr step_iterator()
	    : start_m(value_type()), size_m(value_type()), step_m(value_type()), index_m(0) {}
	constexpr step_iterator(value_type _start, value_type _size, value_type _step)
	    : start_m(_start), size_m(_size), step_m(_step), index_m(0) {}
	value_type operator*() const noexcept {
		return value();
	}
	step_iterator& operator++() noexcept {
		++index_m;
		return *this;
	}
	step_iterator& operator++(int) noexcept {
		auto tmp = *this;
		++*this;
		return tmp;
	}
	step_iterator& operator--() noexcept {
		--index_m;
		return *this;
	}
	step_iterator& operator--(int) noexcept {
		auto tmp = *this;
		--*this;
		return tmp;
	}
	step_iterator& operator+=(difference_type n) {
		index_m += n;
		return *this;
	}
	step_iterator operator+(difference_type n) const {
		return step_iterator(*this) += n;
	}
	friend step_iterator operator+(difference_type n, step_iterator i) {
		return i + n;
	}
	step_iterator& operator-=(difference_type n) {
		index_m -= n;
		return *this;
	}
	step_iterator operator-(difference_type n) const {
		return step_iterator(*this) -= n;
	}
	friend step_iterator operator-(difference_type n, step_iterator i) {
		return i - n;
	}
	difference_type operator-(const step_iterator& other) const {
		assert(start_m == other.start_m);
		assert(size_m == other.size_m);
		assert(step_m == other.step_m);
		return index_m - other.index_m;
	}
	bool operator==(const step_iterator& other) const noexcept {
		return value() == other.value();
	}
	bool operator!=(const step_iterator& other) const noexcept {
		return value() != other.value();
	}
	bool operator<(const step_iterator& other) const noexcept {
		return value() < other.value();
	}
	bool operator<=(const step_iterator& other) const noexcept {
		return value() <= other.value();
	}
	bool operator>(const step_iterator& other) const noexcept {
		return value() > other.value();
	}
	bool operator>=(const step_iterator& other) const noexcept {
		return value() >= other.value();
	}
	constexpr value_type value() const noexcept {
		return start_m + step_m * index_m;
	}
};

template <class T> class Step {
public:
	using value_type = T;
	using iterator = step_iterator<value_type>;

private:
	value_type start_m, size_m, step_m;

public:
	constexpr Step(value_type _start, value_type _size, value_type _step)
	    : start_m(_start), size_m(std::max<value_type>(0, _size)), step_m(_step) {}
	constexpr iterator begin() const {
		return iterator(start_m, size_m, step_m);
	}
	constexpr iterator end() const {
		return iterator(start_m, size_m, step_m) + size_m;
	}
	constexpr value_type start() const {
		return start_m;
	}
	constexpr value_type size() const {
		return size_m;
	}
	constexpr value_type step() const {
		return step_m;
	}
	constexpr value_type sum() const {
		return start() * size() + step() * (size() * (size() - 1) / 2);
	}
	operator std::vector<value_type>() const {
		return to_a();
	}
	auto to_a() const {
		std::vector<value_type> result;
		result.reserve(size());
		for (auto i : *this) {
			result.push_back(i);
		}
		return result;
	}
};
template <class T> constexpr auto upto(T from, T to, bool exclusive = true) {
	return Step<T>(from, to - from + exclusive, 1);
}
template <class T> constexpr auto downto(T from, T to, bool exclusive = true) {
	return Step<T>(from, from - to + exclusive, -1);
}
template <class T> constexpr auto times(T n, bool exclusive = false) {
	return Step<T>(0, n + static_cast<T>(exclusive), 1);
}