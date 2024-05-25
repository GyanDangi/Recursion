#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int size, int index)
{

	if (index == size)
	{
		return;
	}

	cout << arr[index] << " ";
	printArray(arr, size, index + 1);
}

void reverseArray1(int *arr, int size, int index)
{

	if (index == size)
		return;

	reverseArray1(arr, size, index + 1);
	cout << arr[index] << " ";
}

void reverseArray2(int *arr, int index)
{
	if (index < 0)
		return;

	cout << arr[index];
	reverseArray2(arr, index - 1);
}

void reverseprint3(int *arr, int size)
{

	if (size == 0)
	{
		return;
	}

	cout << arr[0] << " ";
	reverseprint3(arr + 1, size - 1);
}

int arraymaxi(int *arr, int index, int size)
{

	if (index == size)
	{
		return INT_MIN;
	}

	int ans = arr[index];
	int rec_ans = arraymaxi(arr, index + 1, size);

	return max(ans, rec_ans);
}


void getMax(int*arr, int size, int index, int &maxi){

	if(index==size){
		return;
	}

	maxi = max(arr[index],maxi);
	getMax(arr,size,index+1, maxi);
}


int main()
{
	int arr[] = {1, 12, 3, 4, 5, 13};

	int size = 6;
	// int ans = arraymaxi(arr, 0, size);
	// cout << ans << endl;


	int maxi=INT_MIN;
	getMax(arr,size, 0,maxi);
	cout<<maxi;
	return 0;
}