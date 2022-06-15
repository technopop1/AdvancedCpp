// lista6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.


#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <mutex>
#include <array>
#include <exception>
#include <stdexcept>

void f(std::vector<double> const v1, std::vector<double> const v2, std::promise<double> p) {
    //static std::mutex mut;
    double suma = 0.0;
    //std::lock_guard<std::mutex> lock(mut);
    
    if ( v1.size() != v2.size() || v1.empty() || v2.empty()){
            
        p.set_exception(std::make_exception_ptr(std::runtime_error("Zle rozmiary wektorow lub ktorys jest pusty!!!\n")));
        //throw std::runtime_error("Zle rozmiary wektorow lub ktorys jest pusty!!!");
    }
    else {

        for (size_t i = 0; i < v1.size(); ++i) {
            suma += v1[i] * v2[i];
        }
        p.set_value(suma);
    } 
}

int main()
{
    try {
        std::vector<double> v1{ 1.0, 5.0, 3.3, 3.66, 7.7 };     // 
        std::vector<double> v2{ 7.44, 5.5, 6.1, 2.22, 2.99 };    //
        std::vector<double> v3{};     // 
        double suma = 0.0;
        std::vector<std::thread> threads;
        std::array<std::promise<double>, 10> promises;
        std::vector<std::future<double>> futures;
        for (int i = 0; i < 10; ++i) {

            futures.push_back(promises[i].get_future());
            if (i == 0 )    // if dla sprawdzenia wyjatku :)
                threads.push_back(std::thread(f, v1, v3, std::move(promises[i])));
            else
                threads.push_back(std::thread(f, v1, v2, std::move(promises[i])));
        }
        for ( std::future<double> &fut : futures) {
            try {
                suma += fut.get();
            }
            catch (std::exception& e) {
                std::cout << e.what();
            }
        }
        for (auto &th : threads) {
                th.join();
        }
        std::cout << "Suma iloczynow skalarnych obliczonych przez 10 watkow = " << suma << "\n";
    }
    catch (std::future_error & e) {
        std::cout << e.what();
    }
    catch (std::exception & e) {
        std::cout << e.what();
    }
    std::cin.get();
}