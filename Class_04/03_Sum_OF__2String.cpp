#include <bits/stdc++.h>
using namespace std;

void sumString(string s1, string s2, int i, int j, int carry,string &ans){

    // base case:
    if(i<0 && j<0 && carry==0){
        return;
    }

    int first=0;
    int second=0;
    // outof Bond nhi chala jaye:
    if(i>=0){
        first =s1[i]-'0';
    }
    if(j>=0){
        second =s2[j]-'0';
    }
    int sum =first+second+carry;
    int lastdigit=sum%10;
    carry =sum/10;
    ans.push_back(lastdigit+'0');
    sumString(s1,s2,i-1,j-1,carry,ans);

}

int main(){

    string s1="12";
    string s2="07";
    int carry=0;
    string ans="";
    sumString(s1,s2,s1.length()-1, s2.length()-1,carry,ans);
    reverse(ans.begin(),ans.end());
    cout<<"Sum is:"<<ans<<endl;











    return 9;
}