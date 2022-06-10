// DynamicProg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "fibonachchi.h"
#include "grid_traveler.h"
#include "can_sum.h"
#include "how_sum.h"

template<typename T>
inline void print_vector(const std::vector<T>& vec)
{
	std::cout << "[";
	for (const T& t : vec)
	{
		std::cout << t;
		if (&t != &vec.back())
		{
			std::cout << " , ";
		}
	}
	std::cout << "]" << std::endl;
}

int main()
{
    //auto x = find_fibonachchi_number<uint64_t>(50);
    //auto x = find_grid_traveler<uint64_t>(18,18);
    //auto x = can_sum<int64_t>(301, { 7, 14 });
    auto x = how_sum<int64_t>(301, {7,14});

	print_vector<int64_t>(x);
    std::cout << "Res=" << x.size() << std::endl;
    std::cout << "Hello World!\n";
}

