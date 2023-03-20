#pragma once
#include <algorithm>

void merge(int* arr, int left, int right)
{
	int i = 0, j = 0;
	int mid = (right + left) / 2;
	
	int size1 = mid - left, size2 = right - mid;

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];

	for (int i1 = 0; i1 < size1; i1++)
		arr1[i1] = arr[left + i1];

	for (int i1 = 0; i1 < size2; i1++)
		arr2[i1] = arr[mid + i1];

	while (i < size1 && j < size2)
	{
		if (arr1[i] < arr2[j])
			arr[left + i + j] = arr1[i++];
		else
			arr[left + i + j] = arr2[j++];
	}

	while (i < size1)
		arr[left + i + j] = arr1[i++];

	while (j < size2)
		arr[left + i + j] = arr2[j++];

	delete[] arr1;
	delete[] arr2;
}

void recMerge(int* arr, int left, int right)
{
	int mid = (right + left) / 2;
	if (right - left > 1)
	{
		recMerge(arr, left, mid);
		recMerge(arr, mid, right);
		
		merge(arr, left, right);
	}
}

void mergeSort(int* arr, size_t size)
{
	recMerge(arr, 0, size);
}