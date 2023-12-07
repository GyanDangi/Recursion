//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  void Subsequence(string s, int index, string ans, vector<string>&output){
      
      if(index==s.length()){
          output.push_back(ans);
          return;
      }
      //Include:
      Subsequence(s, index+1,ans+s[index],output);
      // Exclude:
      Subsequence(s,index+1,ans,output);
      
  }
  
	int distinctSubsequences(string s)
	{   
	    string ans=" ";
	   vector<string>output;
	   Subsequence(s,0,ans,output);
	   unordered_map<string, int> map;
	   int cnt=0;
	   for(int i=0; i<output.size(); i++){
	       map[output[i]]++;
	   }
	   for(auto it:map){
	       if(it.first==" "){
	           cnt++;
	       }
	       
	       if(it.second==1){
	           cnt++;
	       }
	   }
	   return cnt;
	   
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends