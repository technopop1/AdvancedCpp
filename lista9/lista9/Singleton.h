#pragma once
#include <iostream>
class Singleton
{

public:
	Singleton* instance();
	void calls();

private:
	Singleton();
	~Singleton();
};

