#include <bits/stdc++.h>
using namespace std;


void reverseStr(string &s, int i, int j){

    // base case:
    if(i>=j){
        return;
    }

    swap(s[i],s[j]);
    reverseStr(s,i+1,j-1);
}


// Method 2:
void reverseString(string str,int index,string&ans){

    if(index==str.length()){
        return;
    }

    //Head Recursion:
    reverseString(str,index+1,ans);
    //Processing:
    ans.push_back(str[index]);
}


int main(){

    string str="Gyan";
    reverseStr(str,0,str.length()-1);
    cout<<str<<endl;
    string s="abcd";
    string ans="";
    reverseString(s,0,ans);
    cout<<ans;


    return 0;
}