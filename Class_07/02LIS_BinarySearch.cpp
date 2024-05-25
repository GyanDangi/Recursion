#include<bits/stdc++.h>
using namespace std;
//Not solved: error:
int solve(int*arr, int s,int e){
	if(s>e){
		return 0;
	}

	
	int mid= s+(e-s)/2;
	int leftans=0;
	if(arr[s]>arr[mid-1]){
		
		leftans = 1+solve(arr,s+1, mid);
	}

	int rightans=0;
	if(arr[mid+1]>arr[e]){
		cout<<"HI";
		rightans =1+solve(arr, mid,e-1);
	}

	return leftans+rightans;
}
int main(){
	int arr[6]={0,1,0,3,2,3};
	int size=6;
	int ans= solve(arr,0,size-1);
	cout<<ans;
	return 0;
}