#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int*arr, int s, int e, int target){

	if(s>e){
		return false;
	}

	int mid=s+(e-s)/2;

	if(target==arr[mid]){
		return true;
	}
	else if(target<arr[mid]){
		return binarySearch(arr, s, mid-1, target);
	}
	else{
		return binarySearch(arr, mid+1, e,target);
	}
}
int main(){

	int arr[5]={1,3,4,6,7};
	int size=5;
	cout<<binarySearch(arr,0,size-1,1);

	return 0;
}