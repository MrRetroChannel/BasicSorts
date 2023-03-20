#pragma once
#include <algorithm>
#include <vector>

void bucketSort(int* arr, size_t size, bool ascending = true)
{
	int max = arr[0], min = arr[0];

	for (int i = 1; i < size; i++)
		max = max < arr[i] ? arr[i] : max, min = min > arr[i] ? arr[i] : min;

	std::vector<int>* buckets = new std::vector<int>[size];

	for (int i = 0; i < size; i++)
	{
		int idx = (arr[i] - min) * (size - 1) / (max - min);
		buckets[idx].push_back(arr[i]);
	}

	for (int i = 0; i < size; i++)
		if (buckets[i].size() > 1)
			std::sort(buckets[i].begin(), buckets[i].end(), [](int l, int r) {return l < r; });

	for (int i = 0, idx = 0; i < size; i++)
		for (int i1 = 0; i1 < buckets[i].size(); i1++)
			arr[idx++] = buckets[i][i1];

	delete[] buckets;
}