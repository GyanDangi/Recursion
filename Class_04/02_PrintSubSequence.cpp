#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string s, string ans, int index){

    // base case:
    if(index ==s.length()){

       cout<<ans<<endl;
       return;
    }

    printSubsequence(s, ans+s[index], index+1);

    //Exclude:
    printSubsequence(s,ans, index+1);
}


void subSquences(string s, string ans, int index, vector<string>&output){

    if(index==s.length()){
        output.push_back(ans);
        return;
    }

    // Include:
    subSquences(s,ans+s[index],index+1,output);

    // Exclude:
    subSquences(s,ans,index+1,output);
}       

int main(){


    string s="gyan";
    string ans="";
    vector<string>output;
    subSquences(s,ans,0,output);
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    
    // printSubsequence(s,ans,0);



    return 0;
}