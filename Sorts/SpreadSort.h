#pragma once
#include <algorithm>

void spreadSort(int* arr, size_t size)
{
	int max = arr[0], min = arr[0];

	for (int i = 1; i < size; i++)
		max = arr[i] > max ? arr[i] : max, min = arr[i] < min ? arr[i] : min;

	size_t* count = new size_t[max - min + 1]{ 0 };

	int* prom = new int[size];
	memcpy(prom, arr, size * sizeof(int));

	for (int i = 0; i < size; i++)
		++count[arr[i] - min];

	for (int i = 1; i < max - min + 1; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; --i)
		arr[--count[prom[i] - min]] = prom[i];

	delete[] count;
	delete[] prom;
}