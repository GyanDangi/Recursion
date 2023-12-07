#include <bits/stdc++.h>
using namespace std;

void printArray(int*arr, int index, int size){

    // base case:
    if(index ==size){
        return ;
    }
    cout<<arr[index];
    // recursive call:
    printArray(arr, ++index, size);
}

int main(){
    cout<<"Hello ji kaise ho"<<endl;

    int arr[]={2,3,5,6,7};
    // int size= int/arr[0];
    // cout<<"size"<<endl;
    printArray(arr, 0,5);

    return 0;
}