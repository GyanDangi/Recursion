#include<bits/stdc++.h>
using namespace std;

// void reverse(string &s, int i, int j){

// 	if(i>=j){
// 		return ;
// 	}

// 	swap(s[i],s[j]);
// 	reverse(s,++i, --j);
// }

void reverse1(string s, int index, string &ans){

	if(index==s.length()) return;

	reverse1(s, index+1, ans);
	ans.push_back(s[index]); 
}

void subSequence(string s,string ans,int index, vector<string>&output){

	if(index>=s.length()){
		if(ans==" "){
			return;
		}
		output.push_back(ans);
		return ;
	}

	//Include:
	subSequence(s, ans+s[index], index+1,output);
	// exclude:
	subSequence(s, ans, index+1,output);

}

void addString(string s1, string s2, int carry, string&ans, int index1, int index2){

	if(index1<0 && index2<0 && carry==0){
		return;
	}

	int a= 0;
	int b= 0;

	if(index1>=0){
		a= s1[index1]-'0';
	}

	if(index2>=0){
		b=s2[index2]-'0';
	}


	int sum= a+b+carry;
	int lastdigit = sum%10;
	carry=sum/10;
	ans.push_back(lastdigit+'0');
	addString(s1,s2,carry, ans, index1-1, index2-1);


}

int main(){

	string s="abc";
	// cout<<s<<endl;
	// reverse(s,0, s.length()-1);
	// cout<<s<<endl;

	// string ans="";
	// reverse1(s, 0, ans);
	// cout<<ans;

	string ans=" ";
	vector<string>output;
	subSequence(s,ans, 0,output);
	sort(output.begin(),output.end());
	for (int i = 0; i < output.size(); i++)
	{	
		cout<<output[i]<<" ";
	}

	// string s1="4";
	// string s2="";
	// addString(s1,s2,0, ans,s1.length()-1, s2.length()-1);
	// reverse(ans.begin(), ans.end());
	// cout<<ans;
	


	return 0;
}