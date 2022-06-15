#include "a.h"
#include <iostream>

a::a(int n) : n(n), ready(false) {
	for (int i = 0; i < n; ++i) {
		std::thread th(&a::put_task, this);
		threads.push_back(std::move(th));
	}
}

a::~a()
{
	stop();
}

void a::add_task(std::function<double()> task) {

	{
		std::unique_lock<std::mutex> lock(mut);
		funs.push(std::move(task));
	}
	cv.notify_one();
}

void a::put_task() {
		std::function<double()> task;
		while (!ready) 
		{
			{
				std::unique_lock<std::mutex> lock(mut);
				cv.wait(lock, [&] { return ready || !funs.empty(); });

				if ( !funs.empty() ) {
					task = std::move(funs.front());
					funs.pop(); 
				}
			}

			if ( task ) {
				double t = task();

				std::unique_lock<std::mutex> lock2(mut2);
				ave.push_back(t);
			}
		}
}

double a::average() const {

	double sr = 0.0;
	std::unique_lock<std::mutex> lock(mut2);
	if (!ave.empty()) {
		double size = ave.size();

		for (size_t i = 0; i < size; i++)
		{
			sr += ave[i];
		}

		double result = sr / size;
		return result;
	}
	else
		return 0;
}

void a::stop() {
	{
		std::unique_lock<std::mutex> lock(mut);
		ready = true;
	}
	cv.notify_all();
	for (auto& thread : threads) {
		if(thread.joinable())
			thread.join();
	}
	//threads.clear();
}