#include <bits/stdc++.h>
using namespace std;

/*
Leetcode:392 solved Using recursive approach:
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false



*/

bool isSubsequence(string &a, string &b,int i, int k){

    if(i==a.length() ){
        return true;
    }

    if(k==b.length()){
        return false;
    }
    

    if(a[i]==b[k]){
        return isSubsequence(a,b,i+1,k+1);
    }
    else{
    
       return isSubsequence(a,b,i,k+1);
    }
}

int main(){
    string s="abc";
    string t="aghbc";
    string s1="axe";
    string t1="mnoe";
    cout<<isSubsequence(s,t,0,0);
    cout<<endl;
    cout<<isSubsequence(s1,t1,0,0);
    return 0;
}