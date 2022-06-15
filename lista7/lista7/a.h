#pragma once

#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>

class a
{
	public:
		explicit a(int n) ;
		~a();
		void add_task(std::function<double()> task);
		double average() const;
		void stop();

	private:
		void put_task();

		int n = 0;
		std::mutex mut;
		mutable std::mutex mut2;	// mutable - ominiêcie consta
		std::vector<double> ave;
		bool ready = false;
		std::condition_variable cv;
		std::vector<std::thread> threads;
		
		std::queue< std::function<double()> > funs;

};		
		
