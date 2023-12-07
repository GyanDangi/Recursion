#include <bits/stdc++.h>
using namespace std;

void SubString(string s,int index, string ans, vector<string>&output){

    if(index==s.length()){
        output.push_back(ans);
        return;
    }

    // include:
    SubString(s,index+1, ans+s[index], output);
    // Exclude:
    SubString(s,index+1, ans, output);
}
long long int SubString(string s,int k){

    
    
}
int main(){
    string s="aba";
    vector<string>output;
    string ans="";
    SubString(s, 0, ans,output);


    for (int i = 0; i< output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
    


    return 0;
}



/*

//User function template for C++

class Solution
{
  public:
    long long int solve(string &s,int k){
        int cnt=0,dis=0;
    	int i=0,j=0;
    	vector<int> freq(26,0);
    	int n=s.size();
    	while(i<n){
    	    if(freq[s[i]-'a']==0) dis++;
    	    freq[s[i]-'a']++;
    	    while(dis>k){
    	        freq[s[j]-'a']--;
    	        if(freq[s[j]-'a']==0) dis--;
    	        j++;
    	    }
    	    if(dis<=k){
    	        cnt+=i+1-j;
    	    }
    	    i++;
    	}
    	return cnt;
    }
    long long int substrCount (string s, int k) {
        return solve(s,k)-solve(s,k-1);
    }
};



*/