#include <iostream>
#include <type_traits>
#include <string>

/// zadanie 1
template<typename T, typename D>
auto add1(T &arg1, D &arg2) {
    std::cout << "pierwszy" << "\n";
    return arg1 + arg2;
}

template<typename T, typename D>
auto add1(const T* const& arg1, const D* const& arg2) { 
    // komentarz do uwagi 
    // const T* const& arg1 ---- arg1 jest stałym wskaźnikiem na stały typ T
    // const T* & arg1 ---- arg1 jest wskaźnikiem na stały typ T
    std::cout << "drugi"<<"\n";
    return *arg1 + *arg2;
}

template<> //std::enable_if<std::_Is_character<T>::type> czy std::enable_if<std::is_same<T, char*>::type>
auto add1( const char* &arg1,const char* &arg2) {
    std::cout << "trzeci" << "\n";

    const int rozmiar1 = strlen(arg1); //(static_cast<std::string>(arg1)).length();
    const int rozmiar2 = strlen(arg2); //(static_cast<std::string>(arg2)).length();
    
    std::string joined;

    for (int i = 0; i < rozmiar1; i++) {
        joined += arg1[i];
    }
    for (int i = 0; i < rozmiar2; i++) {
        joined += arg2[i];
    }

    return joined;

}

template<typename T>
constexpr T hiperszescian(T dl,T wym) {
    int wynik = 1;
    if (wym > 0) {
        for (int i = 1; i <= wym; i++) {
            wynik *= dl;
        }
    }
    else {
        wynik = -1;
    }
    return wynik;
}

template<typename T, typename ...Args>
auto suma(T first, Args... args) {
    if constexpr (sizeof...(args) == 0)// && std::is_same<std::string, Args>)
        return first;
    else
        return first + suma(args...);
}


int main()
{
    int a = 1;
    float b = 5.6f;
    double c = 6.66;

    //std::string tekst1 = "c++ jest fajny,";
   // std::string tekst2 = " a javascript posysa";
    const char* tekst1 = "c++ jest fajny,";
    const char* tekst2 = " a javascript nie";

    std::cout << "zadanie1" << "\n";
    std::cout << add1(a, b);
    std::cout << "\n";
    std::cout << add1(&a, &c);
    std::cout << "\n";

    std::cout << add1(tekst1, tekst2);

    // zad 2
    std::cout << "\n\n";
    std::cout << "zadanie2" << "\n";

    // w czasie kompilacji zostaną obliczone wartości z1, z2, z3, wiec przy wykonywaniu programu zmienne będą miały już wartość
    // może być static_assert(hiperszescian(2, 2), "no nie pykło byczku");     ->  static_assert wykonuje sie w czasie kompilacji i jeżeli true to wykonuje sie dalej a jeśli false to kończy kompilacje i wywala błąd/tekst podany 
    constexpr int z1 = hiperszescian(2, 2); 
    constexpr int z2 = hiperszescian(2, 5);
    constexpr int z3 = hiperszescian(2, -4);
    std::cout << z1 << "\n";
    std::cout << z2 << "\n";
    std::cout << z3;

    // zad 3 
    std::cout << "\n\n";
    std::cout << "zadanie3" << "\n";
    std::cout << suma(1, 2.22f, 3, 4.5f, 5.5);

    std::cin.get();
}