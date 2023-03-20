#pragma once
#include <algorithm>

void heapify(int* arr, size_t size, int _root)
{
	int root = _root;

	int l = 2 * root + 1, r = 2 * root + 2;

	if (l < size && arr[l] > arr[root])
		root = l;

	if (r < size && arr[r] > arr[root])
		root = r;

	if (root != _root)
	{
		std::swap(arr[_root], arr[root]);
		heapify(arr, size, root);
	}
}

void heapSort(int* arr, size_t size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	for (int i = size - 1; i >= 0; i--)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}