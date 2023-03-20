#pragma once
#include <algorithm>

void mainSort(int* arr, int left, int right)
{
	if (right - left > 0)
	{
		int i = left + 1, j = right - 1;

		while (i <= j)
		{
			if (arr[left] > arr[i])
				++i;
			else
			if (arr[left] <= arr[j])
				--j;
			else
				std::swap(arr[i], arr[j]);
		}

		std::swap(arr[left], arr[j]);

		mainSort(arr, left, j);
		mainSort(arr, j + 1, right);
	}
}

void quickSort(int* arr, size_t size)
{
	mainSort(arr, 0, size);
}

void quickSortNoBarrier(int* arr, int left, int right) {
	if (right - left > 0) {
		int i = left, j = right;

		while (i < j) {
			while (i < j && arr[j] >= arr[i])
				j--;

			std::swap(arr[i], arr[j]);

			while (i < j && arr[j] >= arr[i])
				i++; 

			std::swap(arr[i], arr[j]);
		}

		quickSortNoBarrier(arr, left, i - 1);
		quickSortNoBarrier(arr, j + 1, right);
	}

}

void quickSortWithoutBarrier(int* arr, size_t size)
{
	quickSortNoBarrier(arr, 0, size);
}