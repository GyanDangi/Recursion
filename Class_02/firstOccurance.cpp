#include <bits/stdc++.h>
using namespace std;

int firstOccurance(int *arr, int size, int index, int target){

    // base case:
    if(index==size){
        return -1;
    }
    if(arr[index]==target){
        return index;
    }
    // nhi to recursion lake dega:
    else{
        return firstOccurance(arr, size, index+1, target);
    }
}

int main(){

    int arr[]={1,3,4,2,4,5,6,7,8,2,2,1};
    int target=8;
    cout<<firstOccurance(arr,12,0, target);

    return 0;
}