#include "timer.h"

alf::timer_exception::timer_exception(const char* message) :message{ message } {};

const char* alf::timer_exception::what() const noexcept {
	return message;
}


alf::timer::timer(bool condition) : status{ condition }, is_destroy{0} {
	if (status == 1)
		first = std::chrono::steady_clock::now();
}

alf::timer::~timer() {
	if (status == 1 && !is_destroy) {
		print();
		is_destroy = 1;
		status = 0;
	}	
}

void alf::timer::start() {
	if (status == 0) {
		first = std::chrono::steady_clock::now();
		status = 1;
	}else
		throw alf::timer_exception("Starting a running timer");

}

void alf::timer::end() {
	if (status == 1) {
		print();
		status = 0;
	}else
		throw timer_exception("Ending a timer that has not started");
}

void alf::timer::print() const {

	const auto last = std::chrono::steady_clock::now();

	std::cout << "=====================================\n" << \
		std::chrono::duration_cast<std::chrono::milliseconds>(last - first).count() << " ms\n" << "=====================================\n";

}