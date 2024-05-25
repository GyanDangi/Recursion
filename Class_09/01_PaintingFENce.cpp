#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k){

    // base case:
    if(n==1){
        return k;
    }
    if(n==2){
        return k*k;
    }

    int same = solve(n-2,k)*(k-1);
    int diff = solve(n-1,k)*(k-1);

    return same+diff;
}

int main(){

    int n=4;
    int k=3;
    int ans =solve(n,k);
    cout<<ans;

    return 0;
}