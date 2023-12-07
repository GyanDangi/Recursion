#include <bits/stdc++.h>
using namespace std;

int getMax(int *arr, int index,int size){

    // base case:
    if(index==size){
        return INT_MIN;
    }
    int meraAns= arr[index];
    int recursiveAns= getMax(arr, index+1, size);

    return max(meraAns,recursiveAns);
}

void method_02(int *arr ,int size, int index,int &maxi){

    if(index==size){
        return;
    }
    maxi=max(maxi, arr[index]);
    method_02(arr, size,index+1, maxi);
}
int main(){

    int arr[]={12,32,41,421,12,23};
    cout<<"using method 01:"<<endl;
    cout<<getMax(arr,0,6);
    cout<<endl;
    int maxi=INT_MIN;
    cout<<"using method 02:"<<endl;
    method_02(arr,6,0,maxi);
    cout<<maxi<<endl;

    return 0;
}