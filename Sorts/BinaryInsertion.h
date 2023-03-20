#pragma once
#include <algorithm>

int binarySearch(int* arr, int find, int left, int right)
{
	if (right <= left)
		return find > arr[left] ? (left + 1) : left;

	int mid = (left + right) / 2;

	if (find == arr[mid])
		return mid + 1;

	if (find > arr[mid])
		return binarySearch(arr, find, mid + 1, right);
	else
		return binarySearch(arr, find, left, mid - 1);
}

void binarySort(int* arr, size_t size)
{
	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];
		int i1 = i - 1;
		
		int place = binarySearch(arr, temp, 0, i1);

		for (; i1 >= place; i1--)
			arr[i1 + 1] = arr[i1];

		arr[i1 + 1] = temp;
	}
}