#pragma once
#include <vector>
#include <unordered_map>

namespace __impl {

	template<typename T>
	inline std::pair<bool, std::vector<T>> best_sum(T target, const std::vector<T>& vec, std::unordered_map<T, std::pair<bool, std::vector<T>>>& map)
	{
		auto it = map.find(target);
		if (it != map.end())
			return it->second;

		std::vector<T> empty;
		if (target == 0)
			return std::make_pair(true, empty);

		if (target < 0)
			return std::make_pair(false, empty);

		auto shortest_comb= std::make_pair(false, empty);

		for (auto v : vec)
		{
			auto reminder = target - v;
			auto res = best_sum(reminder, vec, map);
			if (res.first)
			{
				res.second.push_back(v);
				if (!shortest_comb.first || shortest_comb.second.size() > res.second.size())
				{
					shortest_comb = res;
				}
			}
		}

		map[target] = shortest_comb;
		return shortest_comb;
	}
}

template <typename T>
static std::vector<T> best_sum(T target, const std::vector<T>& vec)
{
	std::unordered_map<T, std::pair<bool, std::vector<T>>> map;
	auto res = __impl::best_sum(target, vec, map);
	return res.first ? res.second : std::vector<T>{};
}
