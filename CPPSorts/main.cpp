#define ARRAY_SIZE(array) (sizeof(array)/sizeof((array)[0]))

#include <stdio.h>
#include <iostream>
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
using namespace std;

int main(int argc, char **argv)
{
	cout << "Uncomment the other methods to see the other results" << endl;
	//int arr[] = { 4, 9, 1, 3, 6, 8, 2, 7, 10, 5 };
	int arr[] = { 15, 34, 84, 7, 46, 55, 24, 3, 0, 1};
	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = ARRAY_SIZE(arr);

	/* Uncomment sorting methods below */

		SelectionSort(arr, size); cout << endl << "Selection Sort: " <<endl;
	//	MergeSort(arr, 0, ARRAY_SIZE(arr) - 1);	cout << endl << "Merge Sort: " <<endl;
	//	InsertionSort(arr, size);	cout << endl << "Insertion Sort: " <<endl;
	//	QuickSort(arr, 0, (ARRAY_SIZE(arr) - 1));	cout << endl << "Quick Sort: " <<endl;

	
	cout << endl << "Sorted array  ";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
	getchar();
	return 0;
}