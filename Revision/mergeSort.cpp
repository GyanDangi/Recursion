#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{

	int mid = s + (e - s) / 2;

	// getting the length of the array:
	int len1 = mid - s + 1;
	int len2 = e - mid;

	// Creating two new array:
	int *arr1 = new int[len1];
	int *arr2 = new int[len2];

	// copying main array values to the array1:
	int mainArrayindex = s;
	for (int i = 0; i < len1; i++)
	{
		arr1[i] = arr[mainArrayindex++];
	}

	// copying main array values to the array2:
	mainArrayindex = mid + 1;
	for (int i = 0; i < len2; i++)
	{
		arr2[i] = arr[mainArrayindex++];
	}

	// merge two sorted array:
	int index1 = 0;
	int index2 = 0;
	mainArrayindex=s;

	while (index1 < len1 && index2 < len2)
	{
		if (arr1[index1] <= arr2[index2])
		{
			arr[mainArrayindex++] = arr1[index1++];
		}
		else
		{
			arr[mainArrayindex++] = arr2[index2++];
		}
	}

	// if len1 is greater than len2 :
	while (index1 < len1)
	{
		arr[mainArrayindex++] = arr1[index1++];
	}

	while (index2 < len2)
	{
		arr[mainArrayindex++] = arr2[index2++];
	}

	delete []arr1;
	delete []arr2;
}

void mergeSort(int *arr, int s, int e)
{

	// base case:
	if (s >= e)
	{
		return;
	}

	int mid = s + (e - s) / 2;

	// leftpart sort:
	mergeSort(arr, s, mid);

	// right part sort:
	mergeSort(arr, mid + 1, e);

	// merging both array:
	merge(arr, s, e);
}

int main()
{
	int arr[4]={3,2,1,5};
    int size=4;
    mergeSort(arr,0,size-1);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }	
	
	return 0;
}