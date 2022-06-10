#pragma once
#include <vector>
#include <unordered_map>

namespace __impl {

	template<typename T>
	inline std::pair<bool,std::vector<T>> how_sum(T target, const std::vector<T>& vec, std::unordered_map<T, std::pair<bool, std::vector<T>>>& map)
	{
		auto it = map.find(target);
		if (it != map.end())
			return it->second;

		std::vector<T> empty;
		if (target == 0)
			return std::make_pair(true, empty);
		
		if (target < 0) 
			return std::make_pair(false, empty);

		for (auto v : vec)
		{
			auto reminder = target - v;
			auto res = how_sum(reminder, vec, map);
			if (res.first)
			{
				res.second.push_back(v);
				map[target] = res;
				return map[target];
			}
		}

		map[target] = std::make_pair(false, empty);
		return map[target];
	}
}

template <typename T>
static std::vector<T> how_sum(T target, const std::vector<T>& vec)
{
	std::unordered_map<T, std::pair<bool, std::vector<T>>> map;
	auto res=__impl::how_sum(target, vec, map);
	return res.first ? res.second : std::vector<T>{};
}
