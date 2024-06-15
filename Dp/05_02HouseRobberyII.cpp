#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int solveSpace(vector<int>nums){
    int n= nums.size();
    int prev2=0;
    int prev1=nums[0];


    for(int i=1; i<n; i++){
        int inc= nums[i]+ prev2;
        int exc= 0+ prev1;
        int ans= max(inc, exc);
        prev2= prev1; 
        prev1= ans;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
        int n= nums.size();

        if(n==1){
            return nums[0];
        }
        // return solveTab(nums);


        vector<int>first;
        vector<int> second;
        for(int i=0; i<n; i++){
            if(i!= n-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                second.push_back(nums[i]);
            }
        }
        

        return max(solveSpace(first), solveSpace(second));
    }
};

int main(){


	return 0;
}