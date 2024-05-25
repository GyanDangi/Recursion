#include<bits/stdc++.h>
using namespace std;

void permutaion(string &s, int index, vector<string>&output){

	if(index==s.length()){
		output.push_back(s);
		return;
	}

	for (int j = index; j < s.length(); j++)
	{
		swap(s[index], s[j]);
		permutaion(s,index+1, output);
		// backtracking:
		swap(s[index], s[j]);
	}
	
}

int main(){

		string s= "abc";
		vector<string>output;
		int index=0;
		permutaion(s,index,output);
		for (int i = 0; i < output.size(); i++)
		{
			cout<<output[i]<<" ";
		}
		
	return 0;
}