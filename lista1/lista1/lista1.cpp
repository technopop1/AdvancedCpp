#include <iostream>
#include <iomanip>
#include <vector>
#include "wektor.h"

using namespace std;

/// zadanie 1
template<typename T, typename D>
auto add1(T arg1, D arg2) {
    return arg1 + arg2;
}
/// zadanie 2
template<typename T, typename D, typename C>
auto add2(T arg1, D arg2, C op) {
    return op(arg1, arg2);
}

int main()
{
    string wwww = "lubie ";
    string wwww1 = "nie lubie";
    // sprawdzenie zadania 1
    cout << add1(1, 3) <<"\n";
    cout << add1(5, 7.777) << "\n";
    cout << add1(wwww, wwww1) << "\n";
    cout << "\n";
    // sprawdzenie zadania 2
    cout << add2(3, 3, [](auto a, auto b) { return a + b; }) << "\n";
    cout << add2(5, 6.4, [](auto a, auto b) { return a * b; }) << "\n";
    cout << add2(wwww, wwww1, [](auto a, auto b) { return a + b; }) << "\n";
    cout << "\n";
    // sprawdzenie zadania 3
    wektor<int, 10, 17> w;
    wektor<int, 10, 0> w2;
    wektor<double, 10, 7.5> w3;
    cout << w;
    cout << "\n";
    cout << w2;
    cout << "\n";
    cout << w3;
    cout << "\n";
    cout << w[5];
    cout << "\n";
    w2[5] = 666;
    w2[1] += 55;
    w2[7] -= 25;
    w2[3] *= 2137;
    //w3[3] *= 5.3543;  // wynik bedzie zmiennoprzecinkowy bo typ wektora3 jest doublem
    w2[9] = 5;
    w2[9] *= w[5];
    w3[9] *= w2[5];
    // sprawdzenie zadania 4
    vector<double> ww{ 4.7, 2.7, 0.0 };
    wektor<int, 3, 3> w4;
    //w4[0] = 5.41;
    //w4[1] = 4.5;
    //w4[2] = 7;
    cout << "\n";
    cout << "\n";
    cout << w4*ww;
    cout << "\n";
    cout << "\n";
    cout << w;
    cout << "\n";
    cout << w2;
    cout << "\n";
    cout << w3;

    cin.get();
    return 0;
}
