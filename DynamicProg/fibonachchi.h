#pragma once

#include <unordered_map>

namespace __impl {
	template<typename T>
	inline T fibonachchi(int n, std::unordered_map<int, T>& map)
	{
		// 1 1 2 3 5 8 ...
		auto it = map.find(n);
		if (it != map.end())
			return it->second;

		if (n < 2)
			return 1;

		auto res = fibonachchi(n - 1, map) + fibonachchi(n - 2, map);
		map[n] = res;
		return res;

	}
}

template<typename T>
static T find_fibonachchi_number(int n)
{
	std::unordered_map<int, T> map;
	return __impl::fibonachchi(n,map);
}