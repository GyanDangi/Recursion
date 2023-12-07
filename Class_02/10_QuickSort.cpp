#include <bits/stdc++.h>
using namespace std;

int partition(int*arr, int s, int e){

    int pivot= arr[s];
    int cnt=0;
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i]<=pivot)
            cnt++;
    }

    // place pivot at right postion:
    int pivotIndex =s+cnt;
    swap(arr[s],arr[pivotIndex]);

    // Right and left part sambhalna:
    int i=s,j=e;

    while (i<pivotIndex && j>pivotIndex)
    {
        while (arr[i]<=pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }

        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i++],arr[j--]);
        
    }

    return pivotIndex;
    
    
}

void QuickSort(int*arr, int s,int e){

    // Base Case:
    if(s>=e)
        return;

    int p= partition(arr, s,e);

    // leftpart:
    QuickSort(arr, s,p-1);
    QuickSort(arr, p+1,e);    
}

int main(){

    int arr[7]={2,3,1,5,4,7,6};
    int len=7;
    QuickSort(arr,0,len-1);
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    

    return 0;
}