#pragma once
#include <vector>
#include <iterator>
#include <utility>
using namespace std;

template <class InputIterator, class value_type = typename InputIterator::value_type>
auto RunLengthEncoding(InputIterator first, InputIterator last) {
	vector<pair<size_t, value_type>> result;
	for (; first != last; ++first) {
		if (result.empty() || result.back().second != *first) {
			result.emplace_back(1, *first);
		} else {
			result.back().first++;
		}
	}
	return result;
}

template <class Container, class value_type = typename Container::value_type>
auto RunLengthEncoding(const Container& a) {
	return RunLengthEncoding(a.begin(), a.end());
}

template <class InputIterator, class value_type = typename InputIterator::value_type>
auto RunLengthEncoding_pair(InputIterator first, InputIterator last) {
	vector<size_t> count;
	vector<value_type> value;
	for (; first != last; ++first) {
		if (value.empty() || value.back() != *first) {
			count.push_back(1);
			value.push_back(*first);
		} else {
			count.back()++;
		}
	}
	return pair(count, value);
}

template <class Container, class value_type = typename Container::value_type>
auto RunLengthEncoding_pair(const Container& a) {
	return RunLengthEncoding_pair(a.begin(), a.end());
}
