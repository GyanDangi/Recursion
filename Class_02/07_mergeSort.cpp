#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e){

    int mid= (s+e)/2;

    int len1=mid-s+1;
    int len2= e-mid;

    int *first =new int[len1];
    int *second= new int[len2];

    // copy values:
    int mainArrayIndex=s;
    for (int i = 0; i < len1; i++)
    {
        
        first[i]=arr[mainArrayIndex++];
    }

     mainArrayIndex=mid+1;
    for (int i = 0; i < len2; i++)
    {
        
        second[i]=arr[mainArrayIndex++];
    }
    
    // merge 2 sorted Array:
    mainArrayIndex=s;
    int index1=0;
    int index2=0;
    while (index1 <len1 && index2 <len2)
    {
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++] =first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    // kisi ka length bada rha then:
    while (index1 <len1)
    {
        arr[mainArrayIndex++]= first[index1++];
    }
    while (index2<len2)
    {
        arr[mainArrayIndex++]=second[index2++];
    }
    
    
    delete []first;
    delete []second;


}

void mergeSort(int *arr,int s, int e){

    // base case:
    if(s>=e){
        return ;
    }

    int mid= (s+e)/2;
    // left part:
    mergeSort(arr, s, mid);
    
    // right part:
    mergeSort(arr, mid+1,e);

    merge(arr,s,e);
}


int main(){


    int arr[22]={12,3,11,2,115,23,12,23,132,12,432,543,12,54,65,45,32,43,12,432,421,4322};
   int len=22;
   mergeSort(arr,0,len-1);

   for (int i = 0; i < len; i++)
   {
    cout<<arr[i]<<" ";
   }
   cout<<endl;
   

    return 0;
}