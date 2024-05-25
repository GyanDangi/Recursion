#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int curr, int prev, int size){

	if(curr==size){
		return 0;
	}

	int pick=0;
	if(prev==-1 || arr[curr]>arr[prev]){
		pick = 1+solve(arr, curr+1, curr, size);
	}

		int notpick= solve(arr, curr+1, prev,size);


	return max(pick, notpick);
}

int main(){
	int arr[6]={0,1,0,3,2,3};
	int size=6;
	int curr=arr[0];
	int ans=solve(arr, curr, -1, size);
	cout<<ans;

	return 0;
}