#include <bits/stdc++.h>
using namespace std;

void solve(string& str, int i , int j){

	// base case:
	if(i>=j){
		return ;
	}

	swap(str[i], str[j]);
	solve(str, i+1, j-1);
}

void method2(string s, int index, string& ans){

	// base case:
	if(index==s.length()){
		return;
	}

	method2(s, index+1, ans);
	// waps atte wqt store krwa liya:
	ans.push_back(s[index]);

}

int main(){
	string str="abcd";
	int j=str.length()-1;
	solve(str, 0, j);
	cout<<str<<endl;
	string s="Gyan";
	string ans="";
	method2(s, 0, ans);
	cout<<ans<<endl;

	return 0;
}