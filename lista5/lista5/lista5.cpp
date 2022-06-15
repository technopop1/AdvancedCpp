#include <iostream>
#include <thread>
#include <mutex>    
#include <future>

// zad 1 A
int th_id(){
    static int i = 0; // local static - zmienna będzie jedna dla wszystkich wywołań
    thread_local int id = ++i;
    return i;
}
// zad 1 B
void f(std::string tekst)
{
    static std::mutex mut; // https://stackoverflow.com/questions/62829474/difference-between-global-local-static-mutex
    std::lock_guard<std::mutex> lock(mut); // objekt lockguard pobiera mutex i uwalnia go w momencie wyjscia z bloku przy swojej destrukcji (mozna uzyc .lock() .unlock())
    std::cout << "thread id -> " << th_id() << "   " << tekst << "\n";
}
// zad 1 C
void C3(std::launch pol)
{
    auto fff = std::async(pol, &f, "jakis tekst 3");
    fff.get();
}
void C2(std::launch pol)
{
    auto fff = std::async(pol, &f, "jakis tekst 2");
    C3(pol);
    fff.get();
} 
void C1(std::launch pol)
{
    auto fff = std::async(pol, &f, "jakis tekst 1");
    C2(pol);
    fff.get();
}

int main() {
    // definicja obiektu zarządzajacego funkcją wywoływaną współbieżnie // Konstruktor std::thread to szablon o dowolnej liczbie parametrów
    std::thread th1( &f, "c++ jest fajny");
    std::thread th2(&f, "multithreading nie jest fajny");
    std::thread th3(&f, "raz dwa trzy");

    // synchronizacja z wątkiem głównym, join czeka na zakończenie funkcji, którą zarządza dany obiekt i dopiero wtedy sama kończy swoje działanie
    th1.join();
    th2.join();
    th3.join();
    std::cout << "\n";
    C1(std::launch::async);     //	uruchamiany jest nowy wątek, aby wykonać zadanie asynchronicznie
    C1(std::launch::deferred);  // nie tworzy osobnego wątku, wywołanie następuje na metodzie get obiektu typu std::future

    std::cin.get();
}