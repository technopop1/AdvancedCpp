#include <iostream>
#include "a.h"
#include <future>
#include <chrono>

int main()
{
	{
		a wyr(10);
		for (double i = 2; i <= 10; ++i) {
			wyr.add_task([=]() { return i * i; });

			//if (i == 5) {
			//	std::this_thread::sleep_for(std::chrono::seconds(1));
			//	double srednia = wyr.average();
			//	std::cout << srednia << "\n";
			//}
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
		double srednia = wyr.average();
		std::cout << srednia << "\n";

		wyr.stop();

		srednia = wyr.average();

		std::cout << srednia << "\n";
	}
	std::cin.get();

}