#include <cstdarg>
#include <functional>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Timer {
	clock_t start_time;

public:

	void start() {
		this->start_time = clock();
	}

	void stop(string s = "ms") {
		clock_t end = clock();
		double time = (double)(end - this->start_time);
		if (s == "ms") {
			cout << time / (CLK_TCK / 1000) << endl;
		}
		if (s == "s") {
			cout << time / CLK_TCK << endl;
		}
		if (s == "m") {
			cout << time / 60 / CLK_TCK << endl;
		}
		if (s == "full") {

		}
	}

	void exec_time(int count ...) {
		va_list args;
		va_start(args, count);
		this->start();
		for (int i = 0; i < count; ++i) {
			function<void()> f = va_arg(args, function<void()>);
			f();
		}
		this->stop();
		va_end(args);
	}
};


class Car {
	int power;
	int max_speed;
	int speed;

public:
	Car(int power = 0, int max_speed = 0) {
		this->power = power;
		this->max_speed = max_speed;
		this->speed = 0;
	}

	void start(int speed = 60) {
		cout << "start()\n";
		this->speed = speed;
	}

	void stop() {
		cout << "stop()\n";
		this->speed = 0;
	}

	void accelerate(unsigned speed = 10) {
		printf_s("accelerate(%d)\n", speed);
		if (this->speed != 0) {
			this->speed += speed;
		}
		if (this->speed > this->max_speed) this->speed = this->max_speed;
	}

	int crash() {
		cout << "crash()\n";
		return this->speed;
	}

	void printSpeed() {
		cout << "Speed: " << this->speed << endl;
	}
};

void func() {
	Car car;
	car.printSpeed(); // 0

	car.start(50);
	car.accelerate();
	car.accelerate();
	car.printSpeed(); // 50

	car.accelerate(50);
	car.accelerate(150);
	car.printSpeed(); // 200

	car.stop();
	car.printSpeed(); // 0

	car.start(180);
	car.printSpeed(); // 180
	car.crash();
	car.printSpeed(); // 0
}

int main() {
	Timer timer;
	function<void()> f(func);
	timer.exec_time(2, f, f);
	return 0;
}