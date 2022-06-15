#include <iostream> 
#include <stdio.h>
#include <time.h>
#include <omp.h>


int main()
{
	/*
		// 1.
		// - Wynik działania nie zawsze jest taki sam, ponieważ parallel definiuje region równoległy, czyli kod, który będzie wykonywany równolegle przez wiele wątków
		// - Komunikaty nie są wykonywane po kolei według wątków, może to być spowodowane tym, że niektóre wątki mogą wykonywać procesy szybciej, a niektóre wolniej lub robią coś innego 
#pragma omp parallel			// można też określić liczbę wątków #pragma omp parallel num_threads(4)
	{
		std::cout << "parallel -> Witaj z watku nr " << omp_get_thread_num() << " sposrod " << omp_get_num_threads() << "\n";
	}
	// Umożliwia określenie, że sekcja kodu powinna być wykonywana w jednym wątku, niekoniecznie wątku głównego
	// np. użycie pragma omp single w derektywie parallel spowoduje wykonanie kodu w jednym wątku tylko raz niezależnie od paralella
#pragma omp single
	{
		std::cout << "single -> Witaj z watku nr " << omp_get_thread_num() << " sposrod " << omp_get_num_threads() << "\n";
	}
	// #pragma omp master określa, że tylko wątek główny powinien wykonać sekcję programu
#pragma omp master
	{
		std::cout << "master -> Witaj z watku nr " << omp_get_thread_num() << " sposrod " << omp_get_num_threads() << "\n";
	}
	// #pragma omp critical określa, że kod jest wykonywany tylko w jednym wątku na raz
	// np. wyświetla wyniki wątków po kolei, czyli używając criticala w parallelu
#pragma omp critical
	{
		std::cout << "critical -> Witaj z watku nr " << omp_get_thread_num() << " sposrod " << omp_get_num_threads() << "\n";
	} 
	*//**/
	const int N = 1'000'000'000;
	int i = 0;
	double sum2 = 0;
	clock_t t0 = clock();

	// z openmp
	#pragma omp parallel for private(i) reduction(+:sum2) //num_threads(12) <- zmiana ilości użytych wątków () 
	for (i = 0; i <= N - 1; ++i) {
		sum2 += 1.0 / (i + 1.0);
	}
	clock_t t1 = clock();
	std::cout << "rownolegle\ns = " << sum2 << "\n";
	std::cout << "t = " << ((double)t1 - t0) / CLOCKS_PER_SEC << "\n";

	// bez openmp 
	i = 0, sum2 = 0, t0 = clock();
	for (i = 0; i <= N - 1; ++i)
	{
		sum2 += 1.0 / (i + 1.0);
	}
	t1 = clock();
	std::cout << "szeregowo\ns = " << sum2 << "\n";
	std::cout << "t = " << ((double)t1 - t0) / CLOCKS_PER_SEC << "\n\n";
	i = 0;
	float sum = 0;
#pragma omp parallel for private(i) reduction(+:sum) num_threads(1)
	for (i = 0; i <= N - 1; ++i) {
		sum += 1.0f / (i + 1.0f);
	}
	t1 = clock();
	std::cout << "1 watek\ns = " << sum << "\n";
	std::cout << "t = " << ((double)t1 - t0) / CLOCKS_PER_SEC << "\n";
	sum = 0, t0 = clock();
#pragma omp parallel for private(i) reduction(+:sum) num_threads(2)
	for (i = 0; i <= N - 1; ++i) {
		sum += 1.0f / (i + 1.0f);
	}
	t1 = clock();
	std::cout << "2 watki\ns = " << sum << "\n";
	std::cout << "t = " << ((double)t1 - t0) / CLOCKS_PER_SEC << "\n";
	sum = 0, t0 = clock();
#pragma omp parallel for private(i) reduction(+:sum) num_threads(4)
	for (i = 0; i <= N - 1; ++i) {
		sum += 1.0f / (i + 1.0f);
	}
	t1 = clock();
	std::cout << "4 watki\ns = " << sum << "\n";
	std::cout << "t = " << ((double)t1 - t0) / CLOCKS_PER_SEC << "\n";
	sum = 0, t0 = clock();
#pragma omp parallel for private(i) reduction(+:sum) num_threads(8)
	for (i = 0; i <= N - 1; ++i) {
		sum += 1.0f / (i + 1.0f);
	}
	t1 = clock();
	std::cout << "8 watkow\ns = " << sum << "\n";
	std::cout << "t = " << ((double)t1 - t0) / CLOCKS_PER_SEC << "\n";
	sum = 0, t0 = clock();
#pragma omp parallel for private(i) reduction(+:sum) num_threads(12)
	for (i = 0; i <= N - 1; ++i) {
		sum += 1.0f / (i + 1.0f);
	}
	t1 = clock();
	std::cout << "12 watkow\ns = " << sum << "\n";
	std::cout << "t = " << ((double)t1 - t0) / CLOCKS_PER_SEC << "\n";
	t0 = clock();

	// równoległa wersja jest szybsza (0.305) niż szeregowa (2.784)
	// 
	// wyniki czasu są zależne od użytego rdzenia oraz od innych procesów wykonywanych równolegle przez dany rdzeń
	// im więcej wątków tym szybciej i dokładniej zostają obliczone wartości sumy
	//
	// clock() nie jest czasem rzeczywistym, może on przyspieszać szybciej lub wolniej w zależności od zasobów przyznanych programowi przez system operacyjny
	// clock() zwraca ilość klatek od początku trwania programu
	// CLOCKS_PER_SEC zwraca ilość klatek na sekundę 
	// clock() nie jest czasem rzeczywistym
	// clock() nadaje się do oceny przyspieszenia wersji równoległej programu, bo można sprawdzić, który z nich był szybszy
	// 
	// /usr/bin/time - nie zawiera informacji o liczbie wątków
	// /usr/bin/time  - %E (Elapsed real time) zwraca czas rzeczywisty
	std::cin.get();
}