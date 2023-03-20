#pragma once
#include <algorithm>

void shellSort(int* arr, size_t size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)
		for (int i = gap; i < size; i++)
		{
			int temp = arr[i];
			int i1 = i;
			for (; i1 >= gap && arr[i1 - gap] > temp; i1 -= gap)
				arr[i1] = arr[i1 - gap];
			arr[i1] = temp;
		}
}