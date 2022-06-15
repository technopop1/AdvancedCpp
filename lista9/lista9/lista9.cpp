#include <iostream>
#include <static.lib>

int main()
{
	std::cout << &Singleton::instance << "\n";

	calls1 call;
	//
	//	lista nie dokończona bo mam problem żeby użyć ten biblioteki statycznej w visualu, spróbuje jeszcze później to przetestować
	//
	std::cin.get();
}
