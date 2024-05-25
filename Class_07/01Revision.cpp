#include <bits/stdc++.h>
using namespace std;

void subsequence(string s,int i,string ans1, vector<string>&ans){

	if(i>=s.length()){
		ans.push_back(ans1);
		return;
	}

	//include
	subsequence(s, i+1, ans1+s[i],ans);
	//exclude:
	subsequence(s, i+1, ans1,ans);
}

int main(){
	string s="abc";
	vector<string>ans;
	string ans1="";
	subsequence(s,0,ans1,ans);
	for (int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
	
	return 0;
}