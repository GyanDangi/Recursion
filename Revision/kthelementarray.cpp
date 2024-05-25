#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&v, int &k, int index, int &ans){

	if(index==v.size()) return;

	solve(v, k , index+1,ans);

	k--;
	if(k==0){
		ans=v[index];
		// cout<<v[index];
	}
}

int main(){
	vector<int> v={1,2,3,4,5};
	int k=2;
	int ans=0;
	solve(v,k,0,ans);
	cout<<ans;
	return 0;
}