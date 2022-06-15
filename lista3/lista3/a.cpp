#include "a.h"

a::a(const std::string & tekst) {
	//std::string* str = new std::string(tekst);
	this->chr = new char[tekst.length() + 1];
	memcpy(this->chr, tekst.c_str(), tekst.length() + 1);
	std::cout << "pierwszy\t";
}

a::a(const a & obj) {
	this->chr = new char[strlen(obj.chr) + 1];
	memcpy(this->chr, obj.chr, strlen(obj.chr) + 1);
	std::cout << "kopiujacy\t";
}

a::a(a && obj) noexcept {
	this->chr = obj.chr;	// przenosze zawartoœæ pola
	obj.chr = nullptr;	// kasuje zawartoœæ pola
	std::cout << "przenoszacy\t";
}

char* a::get() const {
	return this->chr;
}

a::~a() {
	delete[] this->chr;
}