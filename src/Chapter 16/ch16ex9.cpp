#include "chapter16_exercises.h"

static const int k_Size = 1000000;

void ch16ex9(void)
{
	// init
	std::default_random_engine rand;
	std::vector<long> vi0;
	std::uniform_int_distribution<long> distribution(0,k_Size);
	for (int i = 0; i < k_Size; ++i)
	{
		vi0.push_back(distribution(rand));
	}
	std::vector<long> vi1(vi0.begin(), vi0.end());
	std::list<long> li(vi0.begin(), vi0.end());

	// STL::sort on vector
	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	std::sort(vi1.begin(), vi1.end());
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::milliseconds time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << time_span.count() << std::endl;

	// list sort
	begin = std::chrono::high_resolution_clock::now();
	li.sort();
	end = std::chrono::high_resolution_clock::now();
	time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << time_span.count() << std::endl;

	// copy and then sort
	begin = std::chrono::high_resolution_clock::now();
	std::list<long> li2(vi0.begin(), vi0.end());
	std::vector<long> vi3;
	std::copy(li2.begin(), li2.end(), std::insert_iterator<std::vector<long>>(vi3, vi3.begin()));
	end = std::chrono::high_resolution_clock::now();
	time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << time_span.count() << std::endl;
}