#include <bits/stdc++.h>
using namespace std;

void reverseArray(int*arr, int index, int size){

    // base case:
    if(index== size){
        return ;
    }
    reverseArray(arr, index+1, size);
    cout<<arr[index]<<" ";
}
// methods_2
void method_2(int *arr, int index){
    // base case:
    if(index<0){
        return ;
    }
    cout<<arr[index]<<" ";
    method_2(arr,index-1);
}
void method_03(int *arr, int size){

    // base case:
    if(size==0){
        return;
    }
    method_03(arr+1,size-1);
    cout<<arr[0]<<" ";
}
int main(){

    int arr[]={1,2,3,7,9};
    int size =sizeof(arr)/sizeof(arr[0]);
    cout<<"using method:01"<<endl;
    reverseArray(arr, 0, 5);
    cout<<endl;
    cout<<"using method:02"<<endl;
    method_2(arr, size-1);
    cout<<endl;
    cout<<"using method:03"<<endl;
    method_03(arr, size);


    return 0;
}