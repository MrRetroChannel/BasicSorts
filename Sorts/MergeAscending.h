#pragma once
#include <algorithm>

void mergeAscending(int* arr, int* tmp, int left, int mid, int right)
{
	for (int i = left; i <= right; i++)
		tmp[i] = arr[i];
	
	int i = left, j = mid + 1, k = left;

	while (k <= right)
		if (i > mid)
			arr[k++] = tmp[j++];
		else
		if (j > right)
			arr[k++] = tmp[i++];
		else 
		if (tmp[i] < tmp[j])
			arr[k++] = tmp[i++];
		else
			arr[k++] = tmp[j++];
}

void mergeSortAscending(int* arr, int size)
{
	int* tmp = new int[size];
	int length = 1;
	int left = 0;
	
	while (length < size)
	{
		left = 0;
		while (left < size - length)
		{
			mergeAscending(arr, tmp, left, left + length - 1, std::min(left + 2 * length - 1, size - 1));
			left += 2 * length;
		}
		length *= 2;
	}


	delete[] tmp;
}