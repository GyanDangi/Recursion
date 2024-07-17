#include <bits/stdc++.h>
using namespace std;

string reverseString(string &s)
{

	int i = 0;
	int j = s.length() - 1;
	while (j >= i)
	{
		swap(s[i++], s[j--]);
	}

	return s;
}

string revesreString_2(string &s){
	string ans="";
	for(int i=s.length()-1; i>=0; i--){
		ans.push_back(s[i]);
	}
	return ans;
}

int main()
{

	string s = "Mumbai";
	// cout << reverseString(s);
	cout<<revesreString_2(s);
	// cout<<s<<endl;

	return 0;
}