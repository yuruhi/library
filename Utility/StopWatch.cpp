#pragma once
#include <chrono>

class StopWatch {
	std::chrono::system_clock::time_point start_time;

	template <class T> T get_time() const {
		auto now = std::chrono::system_clock::now();
		return std::chrono::duration_cast<T>(now - start_time);
	}

public:
	StopWatch(bool start_immediately = false) {
		if (start_immediately) start();
	}
	void start() {
		start_time = std::chrono::system_clock::now();
	}
	int ms() const {
		return static_cast<int>(get_time<std::chrono::milliseconds>().count());
	}
	long long ms64() const {
		return static_cast<long long>(get_time<std::chrono::milliseconds>().count());
	}
	int s() const {
		return static_cast<int>(get_time<std::chrono::seconds>().count());
	}
	long long s64() const {
		return static_cast<long long>(get_time<std::chrono::seconds>().count());
	}
};
