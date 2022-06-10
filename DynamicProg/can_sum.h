#pragma once
#include <vector>
#include <unordered_map>

namespace __impl {

	template<typename T>
	inline bool can_sum(T target,const std::vector<T>& vec, std::unordered_map<T, bool>& map)
	{
		auto it = map.find(target);
		if (it != map.end())
			return it->second;

		if (target == 0) return true;
		if (target < 0) return false;

		for (auto v : vec)
		{
			auto reminder = target - v;
			if (can_sum(reminder, vec, map))
			{
				map[reminder] = true;
				return true;
			}
		}

		map[target] = false;
		return false;
	}
}

template <typename T>
static bool can_sum(T target,const std::vector<T>& vec)
{
	std::unordered_map<T, bool> map;
	return __impl::can_sum(target,vec,map);
}
