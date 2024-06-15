#include<bits/stdc++.h>
using namespace std;

int main(){

	for (int i = 0; i < 5; i++)
	{
		if(i==4){
			continue; // continue is used for skipping:
		}

		cout<<i<<endl;
	}
	cout<<endl;

	int n=984329;
	int len= to_string(n).length();
	int base = pow(10,len-1);
	cout<<"base is:"<<base<<endl;
	cout<<len<<endl;
	
	return 0;
}