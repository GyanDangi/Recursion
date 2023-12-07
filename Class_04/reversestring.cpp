#include<bits/stdc++.h>

using namespace std;

void reverseStr(string &str,int i, int j){
    
    // base case:
    if(i>=j){
        return;
    }

    // 1 case:
    swap(str[i],str[j]);
    reverseStr(str, i+1, j-1);

}

// approach:02
void reverseSt(string str, int index, string &ans){
    
    if(index==str.length()){
        return ;
    }


    reverseSt(str, index+1,ans);
    ans.push_back(str[index]);

}

int main(){

    string str="Babbar";
    cout<<str<<endl;
    // reverseStr(str,0, str.length()-1);
    string ans="";
    reverseSt(str,0,ans);
    cout<<ans;

    return 0;
}