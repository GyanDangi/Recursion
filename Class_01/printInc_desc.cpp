#include <bits/stdc++.h>
using namespace std;

void printDecs(int n){

    if(n==0){
        return;
    }

    cout<<n<<" ";
    printDecs(n-1);
}

void printInc_Desc(int n){

    if(n==0){
        return ;
    }

    printInc_Desc(n-1);
    printDecs(n);
    cout<<n<<" ";
}

int main(){
    cout<<"enter the value of n"<<endl;
    int n;
    cin>>n;
    printInc_Desc(n);


    return 0;
}