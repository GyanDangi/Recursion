#include <bits/stdc++.h>
using namespace std;

void PrintDec_Inc(int n){

    if(n==0){
        return;
    }

    cout<<n<<" ";
    PrintDec_Inc(n-1);
    cout<<n<<" ";
}

int main(){


    cout<<"enter the value of N:"<<endl;
    int n;
    cin>>n;
    PrintDec_Inc(n);

    return 0;
}