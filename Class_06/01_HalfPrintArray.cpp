#include <bits/stdc++.h>
using namespace std;

void Solve(int*arr, int size){
    if(size<1){
        cout<<arr[size]<<endl;
        return ;
    }

    for (int i = 0; i <=size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    Solve(arr,size/2);
    
}

// Method:02
void solve2(int*arr, int s, int e){

    // base case:
    if(s>=e){
        // single element wala case handle:
        cout<<arr[s]<<endl;
        return;
    }

    int mid=s +(e-s)/2;
    for (int i = s; i <=e; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    solve2(arr, s, mid);
    
}


int main(){

    int arr[7]={1,23,4,3,5,6,7};
    int size=7;
    // solve2(arr,0,size);
    Solve(arr,size);
    return 0;
}