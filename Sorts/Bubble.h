#pragma once // 1
#include <algorithm>

void bubbleSort(int* arr, size_t size)
{
	for (int i = 0; i < size; i++)
		for (int i1 = 1; i1 < size - i; i1++) // size - i будет с барьером
			if (arr[i1 - 1] > arr[i1])
				std::swap(arr[i1 - 1], arr[i1]);
}

void bubbleBarrier(int* arr, size_t size)
{
	int i = 0;
	while (i < size)
	{
		int barrier = 0;
		for (int i1 = size - 1; i1 > i; i1--)
			if (arr[i1 - 1] > arr[i1])
			{
				std::swap(arr[i1 - 1], arr[i1]);
				barrier = i1;
			}
		++i;
		i = barrier > i ? barrier : i;
	}
}