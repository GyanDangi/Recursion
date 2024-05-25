#include<bits/stdc++.h>
using namespace std;

int partition(int*arr, int s, int e){

	// Pivot:
	int pivot= arr[s];
	int cnt=0;
	for (int i = s+1; i <=e; i++)
	{
		if(arr[i]<=pivot){
			cnt++;
		}
	}

	// placing pivot at right position:
	int pivotIndex= s+cnt;
	swap(arr[s],arr[pivotIndex]);

	// sorting left and right part of the pivotIndex element:
	int i=s, j=e;
	while (i<pivotIndex && j>pivotIndex)
	{
		while (arr[i]<pivot)
		{
			i++;
		}
		while (arr[j]>pivot)
		{
			j--;
		}
		// yaha log faste hai:
		if(i<pivotIndex && j>pivotIndex){
			swap(arr[i++],arr[j--]);
		}
		
		
	}
	
	
}
void quickSort(int*arr, int s, int e){

	// base case:
	if(s>=e){
		return;
	}

	int p = partition(arr, s, e);

	// left side of P:
	quickSort(arr, s, p-1);

	// rightside of p:
	quickSort(arr, p+1,e);
}
int main(){

	int size=12;
	int arr[size]={12,23,21,2,5,3,4,-3,4,3,2,-1};
	quickSort(arr,0,size-1);
	for (int i = 0; i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	

	return 0;
}