#pragma once
#include <list>
#include <algorithm>

void listInsertionSort(std::list<int>& list)
{
	for (auto i = ++list.begin(); i != list.end(); )
	{
		int temp = *i;
		
		i = list.erase(i);

		auto i1 = i;

		--i1;

		for (; temp < *i1 && i1 != list.begin(); --i1)
		{}

		if (temp < *i1 && i1 == list.begin())
			list.insert(list.begin(), temp);
		else
		list.insert(++i1, temp);
	}
}