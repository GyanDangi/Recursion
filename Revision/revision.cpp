#include <bits/stdc++.h>
using namespace std;


int getfib(int n){

	if(n==0) return 0;
	if(n==1) return 1;

	int ans= getfib(n-1) + getfib(n-2);

	return ans;
}

void printDescring(int n){
	if(n==0) return;

	cout<<n<<" ";
	printDescring(n-1);
	cout<<n<<" ";
}

void printIncreasing(int n){

	if(n==0)return;
	printIncreasing(n-1);
	cout<<n<<" ";
}

void printBoth(int n){

	if(n==0)return ;
	cout<<n<<" ";
	printBoth(n-1);
	cout<<n<<" ";
}

void printInc_Desc(int n){

    if(n==0){
        return ;
    }

    printInc_Desc(n-1);
    printDescring(n);
    cout<<n<<" ";
}

int main(){
	// 0 1 1 2 3 5 8 13 21 34 55
	// cout<<getfib(6);
	// printDescring(6);
	// cout<<endl;
	// printIncreasing(7);
	// cout<<endl;
	// printBoth(8);
	printInc_Desc(9);
	return 0;
}