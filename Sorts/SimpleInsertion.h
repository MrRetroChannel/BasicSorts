#pragma once
#include <algorithm>

void insertionSort(int* arr, size_t size)
{
	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];
		int i1 = i - 1;
		for (; temp < arr[i1]; i1--)
			arr[i1 + 1] = arr[i1];

		arr[i1 + 1] = temp;
	}
}