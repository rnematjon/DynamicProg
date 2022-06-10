#pragma once
#include<string>
#include <unordered_map>

namespace __impl {

	template <typename T>
	inline T grid_traveler(int n, int m, std::unordered_map<std::string, T> & map)
	{
		auto key = std::to_string(n) + "," + std::to_string(m);
		auto it = map.find(key);
		if (it != map.end())
			return it->second;

		if (n == 0 || m == 0) return 0;
		if (n == 1 || m == 1) return 1;
	
		auto res=grid_traveler(m - 1, n,map) + grid_traveler(m, n - 1,map);
		map[key] = res;
		return res;
	}
}

template <typename T>
static T find_grid_traveler(int n, int m)
{
	std::unordered_map<std::string, T> map;
	return __impl::grid_traveler(n, m,map);
}