#include "Singleton.h"

Singleton::Singleton()
{
	std::cout << this << " + ";
}

Singleton::~Singleton()
{
	std::cout << this << " - ";
}

Singleton* Singleton::instance() 
{
	static Singleton* instancja;
	if (instancja == nullptr) {
		instancja = this;
	}
	return instancja;
}

void Singleton::calls()
{
	static int wywolania = 0;
	std::cout << " Adres obiektu " << this << ", ilo�� wywo�a� " << ++wywolania << "\n";
}