#include<bits/stdc++.h>
using namespace std;

int elimination_lastRemaining(int n){
	

	

	// base case:
	if(n==1){
		return n;
	}

	return 2*(1+n/2 -elimination_lastRemaining(n/2));
}

int main(){

	int arr[] ={1,2,3,4,5,6,7,8,9};
	int n=9;

	return 0;
}