#pragma once
#include <algorithm>

void merge(int* arr, int size, int left, int mid, int right)
{
	int l = left, r = mid + 1;
	int* b = new int[size];

	for (int i = left; i <= right; i++)
		if (r > right || (l <= mid && arr[l] <= arr[r]))
			b[i] = arr[l++];
		else
			if (l > mid || (r <= right && arr[r] <= arr[l]))
				b[i] = arr[r++];

	for (int i = left; i <= right; i++)
		arr[i] = b[i];

	delete[] b;
}

void naturalMergeSort(int* arr, size_t size)
{
	int left = 0, right = size - 1;
	bool sorted = false;
	int l = left, r = right;

	do
	{
		sorted = true;
		left = 0;

		while (left < right)
		{
			l = left;

			while (l < right && arr[l] <= arr[l + 1])
				++l;

			r = l + 1;

			while (r == right - 1 || r < right && arr[r] <= arr[r + 1])
				++r;

			if (r <= right)
			{
				merge(arr, size, left, l, r);
				sorted = false;
			}

			left = r + 1; 
		}

	} while (!sorted);
}