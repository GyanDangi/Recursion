#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(vector<int>& nums, int i, int j){

        if(i>j){
            return 0;
        }

        int opt1 = nums[i] + min(solve(nums, i+2,j),solve(nums,i+1,j-1));
        int opt2 = nums[j] + min(solve(nums,i,j-2), solve(nums,i+1,j-1));

        int p1score =max(opt1, opt2);
        return p1score;
    }
    bool predictTheWinner(vector<int>& nums) {
        int p1score =solve(nums,0,nums.size()-1);
        int total=0;
        for(int i=0; i<nums.size(); i++){
            total +=nums[i];
        }
        int p2Score= total-p1score;

        if(p1score>=p2Score){
            return true;
        }
        else{
           return  false;
        }
    }
};