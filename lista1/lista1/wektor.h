#pragma once
#ifndef wektor_h
#define wektor_h

#include <iostream>
#include <vector>

using namespace std;



    template<typename T, size_t N, T W = 0>
    class wektor
    {
        public:
            typedef T value_type;
            wektor() {
                for (int i = 0; i < N; i++) {
                    vec.push_back(W);
                }
            }
            size_t mySize() const { return size; }
            T& operator [] (int index) {
                return vec[index];
        }
            // friend udziela dostepu do prywatnych zmiennych metodom ktore sa zadeklarowane w innej klasie
            friend ostream& operator<<(ostream& out, wektor<T, N, W>& w) {
            
                for (auto i : w.vec)
                    out << i << " ";
                return out;
            }
        private:
            int size = N;
            vector<T> vec;
    };

    template<typename T, size_t N, T W = 0, typename TT>
    auto operator *(wektor<T, N, W>& lVec, vector<TT>& rVec) {  /// zadanie 4 ( jeszcze nie skonczone )
        decltype(lVec[0] * rVec[0]) suma = 0;
        if (N < rVec.size()) {
            for (size_t i = 0; i < N; i++)
                suma += lVec[i] * rVec[i];
        }
        else {
            for (size_t i = 0; i < rVec.size(); i++)
                suma += lVec[i] * rVec[i];
        }
        return suma;
    }

#endif // !wektor_h

