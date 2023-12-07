#include <bits/stdc++.h>
using namespace std;


int findFirst(int *arr, int index,int size, int target){

    if(index==size){
        return -1;
    } 

    if(arr[index]==target){
        return index;
    } 
    else{
        findFirst(arr, index+1, size, target);
    }
}

int main(){

    int arr[] ={1,3,4,2,5,6,7,2,2,6};
    int target;
    cout<<"enter the target element of the array:";
    cin>>target;
    cout<<"first occurance index of:"<<target<<" is "<<findFirst(arr, 0, 10,target);


    return 0;
}