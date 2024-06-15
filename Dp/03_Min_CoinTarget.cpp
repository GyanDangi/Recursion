#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

int solveRec(vector<int> &coins, int amount){

    // base case:
    if(amount==0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;
    }

    int mini= INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int ans= solveRec(coins,amount-coins[i]);
        if(ans!=INT_MAX){
            mini= min(mini, 1+ans);
        }
    }
    return mini;
}

int solveMemo(vector<int> &coins, int amount,vector<int>&dp){

    // base case:
    if(amount==0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;
    }

    if(dp[amount]!=-1){
        return dp[amount];
    }

    int mini= INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int ans= solveMemo(coins,amount-coins[i],dp);
        if(ans!=INT_MAX){
            mini= min(mini, 1+ans);
        }
    }
    //step2: ans store in dp then return:
    dp[amount]= mini;
    return dp[amount];
}


int solveTab(vector<int>& coins, int amount){
    // step11: Create dp array:
    vector<int>dp(amount+1, INT_MAX);

    // step2: Base case analyze:
    dp[0]=0;

    // step3: for loop hadle
    for(int i=1; i<=amount; i++){
        int mini= INT_MAX;
        for(int j=0; j<coins.size(); j++){
            
            if(i-coins[j]>=0){
                int ans= dp[i-coins[j]];
                if(ans!=INT_MAX){
                        mini= min(mini, 1+ans);
                    }
            }
             
        }
    dp[i]= mini;
    }
    if(dp[amount]==INT_MAX){
        return -1;
    }
    return dp[amount];
    
      
}

    int coinChange(vector<int>& coins, int amount) {
                
        return solveTab(coins,amount);
        // if(ans==INT_MAX){
        //     return -1;
        // }
        // else{
        //     return ans;
        // }
    }
};

int main(){


	return 0;
}