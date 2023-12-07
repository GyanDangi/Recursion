// print subsequence of string using recursion:

#include<bits/stdc++.h>

using namespace std;

void subSquence(string str, int index, string ans){
    int count=0;
    // base Case:
    if(index==str.length()){
        cout<<ans<<endl;
        return;
    }
    // Include:
    subSquence(str,index+1, ans+ str[index]);
    // Exclude:
    subSquence(str, index+1, ans);
}

// Storing in Vector<string>
void PrintSubsequence(string str, int index, string ans, vector<string>& output){

    if(index==str.length()){
        output.push_back(ans);
        return ;
    }

    // Include:
    PrintSubsequence(str, index+1,ans+str[index],output);
    //Exclude:
    PrintSubsequence(str, index+1,ans,output);
}

int main(){

    string str="Gyan";
    string ans="";
    vector<string> outPut;
    // subSquence(str,0,ans);
    PrintSubsequence(str, 0, ans, outPut);

    for (int i = 0; i < outPut.size(); i++)
    {
       cout<<outPut[i]<<" "<<endl;
    }
    cout<<endl;
    



    return 0;
}