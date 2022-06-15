#pragma once
#include <iostream>

class a
{
	public:
		a(const std::string & tekst);
		a(const a & obj);
		a(a&& obj) noexcept;
		~a();
		char* get() const;
	private:
		char* chr;
};

