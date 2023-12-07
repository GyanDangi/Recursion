#include <bits/stdc++.h>
using namespace std;

void allOccurance(int *arr, int size,int index, int target, vector<int>&ans){

    // base case:
    if(index==size){
        return ;
    }

    if(arr[index]==target){
        ans.push_back(index);
    }
    //baki bacche hue apna recursion le ayenga
 
        allOccurance(arr, size, index+1,target,ans);
}

int main(){
    // cout<<"hello jei kaise ho"<<endl;
    int arr[]={1,2,24,5,3,2,2,4};
    int target=2;
    vector<int>ans;
    allOccurance(arr, 8,0,target,ans);
    cout<<"printing all index of the given target:"<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}