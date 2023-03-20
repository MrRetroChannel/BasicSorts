#include <iostream>
#include "AllSorts.h"

bool cmpMass(int* arr1, int* arr2, size_t size)
{
	bool ret = true;
	for (int i = 0; i < size; i++)
		ret *= arr1[i] == arr2[i];
	return ret;
}

void printArr(int* arr, size_t size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ' ';
}

int main()
{
	int test[] = { 1, 7, 14, 0, 9, 4, 18, 18, 2, 4, 5, 5, 1, 7, 1, 11, 15, 2, 7, 16, 11, 4, 2, 13, 12, 2, 1, 16, 18, 15 };
	size_t size = sizeof(test) / 4;

	int sorted[30];

	memcpy(sorted, test, sizeof(test));

	std::sort(sorted, sorted + size);

	bucketSort(test, size);

	printArr(test, size);

	std::cout << (cmpMass(test, sorted, size) ? "Correct" : "Ne rabotaet blyat");
}