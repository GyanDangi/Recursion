#include <bits/stdc++.h>
using namespace std;

void allOccurance(int*arr, int size, int index, int target,vector<int>&ans){

    if(index==size){
        return ;
    }

    if(arr[index]==target){
        ans.push_back(index);
    }
 
        allOccurance(arr,size,index+1,target,ans);


}



int main(){

    int arr[]={1,2,3,2,4,2,5,6,3,2};
    vector<int>ans;
    allOccurance(arr,10,0,2,ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

    return 0;
}