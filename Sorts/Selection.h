#pragma once
#include <algorithm>

void selectionSort(int* arr, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		int imax = 0;

		for (int i1 = 0; i1 < size - i; i1++)
			if (arr[imax] < arr[i1])
				imax = i1;

		std::swap(arr[imax], arr[size - i - 1]);
	}
}