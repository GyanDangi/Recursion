#include <bits/stdc++.h>
using namespace std;

string reverseString(string&s){

	int i=0;
	int j=s.length()-1;
	while (j>=i){

		swap(s[i++],s[j--]);
		
	}
	
	return s;
	
}

int main(){

	string s="Mumbai";
	cout<<reverseString(s);
	// cout<<s<<endl;

	return 0;
}