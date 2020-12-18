#pragma once

void SelectionSort(int *arr, int size)
{
	int temp;
	for (int i = 0; i < size; ++i)
	{
		int idx = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[idx] > arr[j])
				idx = j;
		}

		if (idx != i)
		{
			temp = arr[idx];
			arr[idx] = arr[i];
			arr[i] = temp;
		}
		
	}
}