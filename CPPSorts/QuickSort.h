#pragma once

//declarations
void QuickSort(int *arr, int low, int high);
int partition(int *arr, int low, int high);

void QuickSort(int *arr, int low, int high)
{
	if (low < high)
	{
		int mid = partition(arr, low, high);
		QuickSort(arr, low, mid - 1);
		QuickSort(arr, mid + 1, high);

	}
}

int partition(int *arr, int low, int high)
{
	int pivot = arr[high];
	int i = low;
	int temp;
	for (int j = low; j < high; ++j)
	{
		if (arr[j] <= pivot)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
		}
	}
	temp = arr[i];
	arr[i] = arr[high];
	arr[high] = temp;

	return (i);
}