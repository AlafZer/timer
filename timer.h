#pragma once
#include <chrono>
#include <iostream>
#include <exception>

namespace alf {
	using namespace std::chrono_literals;
	class timer_exception;
	template<typename T> class timer;	
}

class alf::timer_exception : public std::exception {
public:

	timer_exception(const char*);

	const char* what() const noexcept;

private:

	const char* message;
};

template<typename T>
class alf::timer {
public:
	timer(bool = 0);

	~timer();

	void start();

	void end();

private:

	void print() const;

	std::chrono::steady_clock::time_point first;
	bool status;
	bool is_destroy;
};
