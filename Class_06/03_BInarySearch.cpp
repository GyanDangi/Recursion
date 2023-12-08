#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int*arr, int s,int e, int target){

    // base case:
    if(s>e){
        return false;
    }

    int mid= s+(e-s)/2;

    if(target==arr[mid]){
        return true;
    }
    else if(target<arr[mid]){
        return binarySearch(arr, s, mid-1,target);
    }
    else{
        return binarySearch(arr, mid+1,e,target);
    }
}


int main(){

    int arr[7]={3,4,5,6,9,12,29};
    int size=7;
    int target=2;
    cout<<"ans is:"<<binarySearch(arr,0,size-1,target);

    return 0;
}