#include <bits/stdc++.h>
using namespace std;

int factorial(int n){

    if(n==0){
        return 1;
    }

    int ans = n*factorial(n-1);
    return ans;
}

int main(){

    cout<<"enter the value of n:"<<endl;
    int n;
    cin>>n;
    int ans= factorial(n);
    cout<<ans;


    return 0;
}