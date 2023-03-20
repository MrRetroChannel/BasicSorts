#pragma once
#include <algorithm> // 2

void shakerSort(int* arr, size_t size)
{
	size_t left = 1, right = size - 1;

	while (left < right)
	{
		for (int i = left; i <= right; i++)
			if (arr[i - 1] > arr[i])
				std::swap(arr[i - 1], arr[i]);

		right--;

		for (int i = right; i >= left; i--)
			if (arr[i - 1] > arr[i])
				std::swap(arr[i - 1], arr[i]);

		left++;
	}
}