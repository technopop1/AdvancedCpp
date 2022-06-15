#pragma once
#include <vector>
#include <deque>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include "zbiornikpaliwa.h"

class Silnik
{

public:
	explicit Silnik(unsigned int time, unsigned int value);
	~Silnik();
	void Podlacz(std::shared_ptr<ZbiornikPaliwa>& tk); //ZbiornikPaliwa& tk

private:
	void Pobieranie();
	bool NO_FUEL = false;
	unsigned int time;
	unsigned int value;

	std::mutex mut;
	std::mutex mut2;
	std::thread th;
	std::condition_variable cv;
	std::deque<std::shared_ptr<ZbiornikPaliwa>> tanks;
	//std::queue<std::shared_ptr<ZbiornikPaliwa>> tanks; // = { std::make_unique<ZbiornikPaliwa>(500), std::make_unique<ZbiornikPaliwa>(500), std::make_unique<ZbiornikPaliwa>(500) };

};

