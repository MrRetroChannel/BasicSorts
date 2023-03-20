#pragma once
#include <algorithm>

bool getDigit(int num, size_t razr)
{
	return num & (1 << (31 - razr));
}

void bitWiseSort(int* arr, int left, int right, int digit = 0)
{
	int i = left, j = right;
	
	if (left <= right && digit < sizeof(int) * 8)
	{
		while (i != j)
		{
			while (!getDigit(arr[i], digit) && i < j)
				++i;

			while (getDigit(arr[j], digit) && j > i)
				--j;

			std::swap(arr[i], arr[j]); 
		}

		if (!getDigit(arr[right], digit))
			++j;

		bitWiseSort(arr, left, j - 1, digit + 1);
		bitWiseSort(arr, j, right, digit + 1);
	}
}