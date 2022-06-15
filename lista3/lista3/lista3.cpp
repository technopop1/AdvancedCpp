#include <iostream>
#include "a.h"

a copy(const a& obj) {
    return a(obj);
}
a copy(a && obj) {
    return a(std::move(obj));
}

template<typename T>
a copy2(T&& obj) {
    return std::forward<T>(obj);
}

int main()
{
    // zadanie 1
    std::string tekst = "siema kto PL";
    a obj(tekst);
    std::cout << obj.get() << "\n";
    a obj2(obj);
    std::cout << obj2.get() << "\n";
    a obj3(std::move(obj)); //std::move zawsze zwraca jako rvalue
    std::cout << obj3.get() << "\n";

    std::cout << "\n\n";

    // zadanie 2
    tekst = "1k gold please";
    a obj4(tekst);
    std::cout << obj4.get() << "\n";
    a copied = copy(obj4);
    std::cout << copied.get() << "\n";
    a moved = copy(std::move(obj4)); 
    std::cout << moved.get() << "\n";

    std::cout << "\n\n";

    // zadanie 3
    tekst = "tralalalal";
    a obj5(tekst);
    std::cout << obj5.get() << "\n";
    a z3a = copy2(obj5);
    std::cout << z3a.get() << "\n";
    a z3b = copy2(std::move(obj5));
    std::cout << z3b.get() << "\n";

    std::cin.get();
}