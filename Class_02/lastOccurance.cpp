#include <bits/stdc++.h>
using namespace std;

int FirstLast(int *arr,  int size, int index,int target){

    // base case:
    if(index<0){
        return -1;
    }
    if(arr[index]==target){
        return index;
    }

    // recursion la ke denga:
    return FirstLast(arr, size, index-1,target);
}
int main(){

    int arr[]={1,2,3,4,2,4,5};
    cout<<FirstLast(arr, 7,7,2);

    return 0;
}