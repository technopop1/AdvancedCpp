#include "silnik.h"
#include <iostream>

Silnik::Silnik(unsigned int time, unsigned int value) : time(time), value(value)
{
	th = std::thread(&Silnik::Pobieranie, this);
}

void Silnik::Pobieranie() {
	
	auto t0 = std::chrono::high_resolution_clock::now();
	while (!NO_FUEL) {
		{
			auto t1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed(t1 - t0);

			{
				std::unique_lock lock(mut);
				cv.wait(lock, [&] {return NO_FUEL || !tanks.empty(); });
				if (!tanks.empty()) {
					if (elapsed.count() >= time) {
						for (size_t i = 0; i < tanks.size(); ++i) {
							int takenfuel;
								
							takenfuel = tanks.front()->pobierz(value);

							if (takenfuel == 0) {						// Jeœli zbiornik jest pusty
								std::cout << "ZBIORNIK ODLACZONY Z SILNIKA nr " << time << "\n";
								tanks.pop_front();
							}
							else if (takenfuel > 0) {					// Je¿eli pobrano paliwo
								i = tanks.size();
								t0 = std::chrono::high_resolution_clock::now();
								std::cout << "Silnik nr " << time << " pobiera " << takenfuel << " po czasie " << elapsed.count() << "\n";
							}
						}
					}
				}

			}

			if (tanks.empty()) {
				std::cout << "Silnik nie moze pobrac paliwa ze zbiornikow \n";
				NO_FUEL = true;
			}
		}
	}
}
Silnik::~Silnik()
{
	if(th.joinable())
		th.join();
}

void Silnik::Podlacz(std::shared_ptr<ZbiornikPaliwa>& tk)
{
	{
		std::unique_lock lock(mut);
		tanks.push_back(tk);
	}
	cv.notify_all();
}