#include <bits/stdc++.h>
using namespace std;

void reversePrinnt(int *arr, int size, int index){

    if(index==size){
        return ;
    }

    reversePrinnt(arr, size, index+1);
    cout<<arr[index]<<" ";
}
// method:02

void reversePrint2(int *arr, int index){

    // base case:
    if(index<0){
        return ;
    }

    cout<<arr[index]<<" ";
    reversePrint2(arr , index-1);
}

int main(){

    int arr[] ={1,2,3,4,5,6,7};
    reversePrinnt(arr,7,0);
    cout<<endl;
    reversePrint2(arr,6);

    return 0;
}