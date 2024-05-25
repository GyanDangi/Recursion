// Longest Common Subsequence:

#include <bits/stdc++.h>
using namespace std;

int solve(int*arr, int i, int diff){

	if(i<0){
		return 0;
	}

	int ans=0;
	for (int k =i-1; k >=0; k--)
	{
		if(arr[i]-arr[k]==diff){
			// number mil gaya:
			ans= max(ans, 1+solve(arr,k,diff));
		}
		
	}
	return ans;
	
}


int main(){
	int arr[5]={9,4,7,2,10};
	int size=5;
	int ans=0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{	
			int diff= arr[j]-arr[i];
			ans =max(ans,2+solve(arr,i,diff));
		}
		
	}

	cout<<ans<<endl;
	
	return 0;
}