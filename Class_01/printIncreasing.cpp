#include <bits/stdc++.h>
using namespace std;

void printInc(int n){
    
    // base case:
    if(n==0){
        return;
    }

    printInc(n-1);
    cout<<n<<" ";
}

int main(){

    int n;
    cout<<"enter the value of n:"<<endl;
    cin>>n;
    printInc(n);

    return 0;
}