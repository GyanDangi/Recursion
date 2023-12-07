#include <bits/stdc++.h>
using namespace std;


int getmax(int *arr, int index, int size){

    if(index==size){
        return INT_MIN;
    }

    int ans = arr[index];
    int recuAns =getmax(arr, index+1, size);
    return max(ans, recuAns);
}

// Method:02

void getmaxi(int *arr, int index, int size, int &maxi){

    if(index==size){

        return ;
    }

    maxi= max(maxi, arr[index]);
    getmaxi(arr,index+1,size, maxi);

}

int main(){

    int arr[] ={1,23,3,56,5,65,7};
    cout<<"ans is:"<<getmax(arr,0,7);
    int maxi = INT_MIN;
    getmaxi(arr,0,7, maxi);
    cout<<endl;
    cout<<maxi<<endl;

    return 0;
}