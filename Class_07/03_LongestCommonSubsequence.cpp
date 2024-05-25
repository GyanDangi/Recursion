#include <bits/stdc++.h>
using namespace std;

int longestcommonSequence(string s, string t, int i, int j){

    // base case:
    if(i==s.length()){
        return 0;
    }

    if(j==t.length()){
        return 0;
    }

    int ans=0;
    // recursive call:
    if(s[i]==s[j]){
        ans = 1+ longestcommonSequence(s,t,i+1,j+1);
    }
    else{

        ans= max(longestcommonSequence(s,t,i+1,j), longestcommonSequence(s,t,i,j+1));
    }
    return ans;
}


int main(){

    string s="axceg";
    string t="abxceg";
    int i=0; int j=0;
    int ans= longestcommonSequence(s,t,i,j);
    cout<<"length of common longest subSequence present is both strings is:"<<ans;
    return 0;
}