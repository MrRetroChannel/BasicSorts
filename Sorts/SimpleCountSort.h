#pragma once
#include <algorithm>

void countSort(int* arr, size_t size)
{
	int* count = new int[size] {0};

	int el1 = 0, el2 = 0;

	for (int i = size - 1; i > 0; i--)
	for (int j = 0; j < i; j++)
		if (arr[i] >= arr[j])
			++count[i];
		else
			++count[j];
	
	int i = 0, j = 0, k = 0;

	while (i < size)
	{
		el1 = arr[i];
		j = count[i];

		while (i != j)
		{
			el2 = arr[j];
			arr[j] = el1;
			el1 = el2;

			k = count[j];

			count[j] = j;
			j = k;
		}

		arr[i] = el1;

		count[i] = i++ - 1;
	}

	delete[] count;
}