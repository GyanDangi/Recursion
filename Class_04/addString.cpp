#include<bits/stdc++.h>
using namespace std;


void AddString(string a, string b, int carry, int i, int j, string &ans){

    // Base Case:
    if(i<0 && j<0 && carry==0){
        return;
    }
    int first=0;
    int second=0;
    if(i>=0){
        first= a[i]-'0';
    }
    if(j>=0){
        second=b[j]-'0';
    }
    int sum= first+second+carry;
    int lastdigit= sum%10;
    carry =sum/10;

    ans.push_back(lastdigit+'0');
    AddString(a,b,carry, i-1, j-1, ans);
}

int main(){

    string a="34";
    string b="345";
    string ans="";
    AddString(a,b,0,a.length()-1,b.length()-1,ans);
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;

    return 0;
}