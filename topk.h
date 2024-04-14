#pragma once

#include <algorithm>
#include <vector>

namespace base {
template<typename Iter>
std::vector<int> topk(Iter first, Iter last, const uint k)
{
	auto items = std::distance(first, last);
	auto take = std::min(static_cast<uint>(items), k);
	if (take == 0)
	{
		return std::vector<int>{};
	}
	std::vector<int> top(first, first + take);
	std::advance(first, take);

	std::make_heap(top.begin(), top.end(), std::greater<>{});
	while (first != last) {
		if (*first <= top[0])
		{
			++first;
			continue;
		}
		top.push_back(*first);
		std::push_heap(top.begin(), top.end(), std::greater<>{});
		
		std::pop_heap(top.begin(), top.end(), std::greater<>{});
		top.pop_back();
		++first;
	}
	std::sort_heap(top.begin(), top.end(), std::greater<>{});
	return top;
}
}

namespace opt {
template<typename Iter>
std::vector<int> topk(Iter first, Iter last, const uint k)
{
	auto items = std::distance(first, last);
	auto take = std::min(static_cast<uint>(items), k);
	if (take == 0)
	{
		return std::vector<int>{};
	}
	std::vector<int> top;
	top.reserve(2*k);
	std::copy(first, first + take, std::back_inserter(top));
	std::advance(first, take);

	auto pivot_v = *std::min_element(top.begin(), top.end());
	while (first != last) {
		if (*first <= pivot_v)
		{
			++first;
			continue;
		}
		top.push_back(*first);
		if (top.size() == 2*k)
		{
			std::nth_element(top.begin(), top.begin() + k, top.end(), std::greater<>{});
			pivot_v = top[k];
			top.resize(k);
		}
		++first;
	}
	std::sort(top.begin(), top.end(), std::greater<>{});
	top.resize(k);
	return top;
}
}
