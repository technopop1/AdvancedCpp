#pragma once
#include <iostream>
#include <mutex>

class ZbiornikPaliwa
{
public:
	ZbiornikPaliwa(unsigned int value, int num);
	unsigned int pobierz(unsigned int value);
private:
	unsigned int fuel = 0;
	int id = 0;
	std::mutex mut;
};
