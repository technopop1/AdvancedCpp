#include <iostream>
#include "zbiornikpaliwa.h"
#include "silnik.h"
#include <chrono>


int main()
{

	Silnik HEMI(1, 1);
	Silnik tdi(2, 5);
	Silnik Sdi(3, 2);

	std::deque<std::shared_ptr<ZbiornikPaliwa>> tanks;

	std::this_thread::sleep_for(std::chrono::seconds(1));
	for (int i = 0; i < 10; ++i) {
		tanks.push_back(std::make_shared<ZbiornikPaliwa>(10, i));
	}

	for (int i = 0; i < 10; ++i) {
		tdi.Podlacz(tanks[i]);
		HEMI.Podlacz(tanks[i]);
		Sdi.Podlacz(tanks[i]);
	}

	std::cin.get();
	return 0;
}
