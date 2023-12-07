#include <bits/stdc++.h>
using namespace std;

    void printArray(int *arr, int index, int size){

         // Base Case:
         if(index==size){
            return ;
         }

         cout<<arr[index]<<" ";

         printArray(arr, index+1, size);
    }

int main(){

    int arr[]={1,2,3,4,5,6,7};
    printArray(arr,0,7);

    return 0;
}