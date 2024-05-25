#include <bits/stdc++.h>
using namespace std;

int getLast(int *arr, int size, int index, int target){

    if(index<0){
        return -1;
    }

    if(arr[index]==target){
        return index;
    }
    else{
       return getLast(arr, size, index-1, target);
    }
}

int main(){

    int arr[] ={1,23,2,3,2,4,2,5};
    int size=8;
    int target=5;
    cout<<getLast(arr,size,size-1,target);

    return 0;
}