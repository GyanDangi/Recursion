#include <bits/stdc++.h>

using namespace std;

void printArray(int *arr, int size, int index){

    if(index==size){
        return ;
    }

    cout<<arr[index]<<" ";
    printArray(arr, size, index+1);
}
// method:02

void printArray2(int *arr,int size){

    // base case:
    if(size<=0){
        return ;
    }

    cout<<arr[0]<<" ";
    printArray2(arr+1,size-1);
}

int main(){

    int arr[] ={1,2,3,4,5,6,7,8,9};
    printArray(arr,9,0);
    cout<<endl;
    printArray2(arr,9);

    return 0;
}