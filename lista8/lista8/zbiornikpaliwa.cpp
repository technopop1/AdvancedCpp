#include "zbiornikpaliwa.h"

ZbiornikPaliwa::ZbiornikPaliwa(unsigned int value, int num) : fuel(value), id(num)
{

}
unsigned int ZbiornikPaliwa::pobierz(unsigned int value)
{
	std::unique_lock lock(mut);
	if (value <= fuel) {
		fuel -= value;
		std::cout << "Zbiornik " << id << " posiada " << fuel << " jednostek paliwa\n";
		return value;
	}
	else {
		return 0;
	}
}
