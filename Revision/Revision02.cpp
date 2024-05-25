#include <bits/stdc++.h>
using namespace std;

int get1stIndex(int *arr, int size, int index, int &target)
{

	if (index == size)
	{
		return -1;
	}

	if (target == arr[index])
	{
		return index + 1;
	}

	return get1stIndex(arr, size, index + 1, target);
}

int getlastIndex(int*arr, int size, int index, int &target){

	if(index<0){
		return -1;
	}

	if(arr[index]==target){
		return index;
	}

	return getlastIndex(arr, size, index-1, target);
}

void findAllOccurance(int*arr,int size, int index, vector<int>&ans,int &target){
	if(index==size){
		return;
	}

	if(arr[index]==target){
		ans.push_back(index+1);
	}

	findAllOccurance(arr, size, index+1, ans, target);
}

int main()
{

	int arr[] = {1, 2, 3, 4, 3, 4, 3, 7};
	int size = 8;
	int target = 3;
	// int ans = get1stIndex(arr, size, 0, target);
	// cout << ans;

	// int ans= getlastIndex(arr,size, size-1, target);
	// cout<<ans;
	vector<int>ans;
	findAllOccurance(arr,size, 0, ans, target);

	for (int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i]<<endl;
	}
	

	return 0;
}