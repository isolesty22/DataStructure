#include <iostream>
#include "Heap.h"

void heapSort(int* arr, int n);

int main()
{
	int data[10];

	for (int i = 0; i < 10; i++)
	{
		data[i] = rand() % 10;
		std::cout << data[i] << ' ';
	}

	std::cout << '\n';

	heapSort(data, 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << data[i] << ' ';
	}


}

void heapSort(int* arr, int n)
{
	Heap h;
	for (int i = 0; i < n; i++)
		h.insert(arr[i]);
	
	for (int i = 0; i < n; i++)
		arr[i] = h.remove().getKey();

}
