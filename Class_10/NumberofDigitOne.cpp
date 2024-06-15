/*
Leetcode:
233. Number of Digit One: Leetcode

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

 

Example 1:

Input: n = 13
Output: 6
Example 2:

Input: n = 0
Output: 0
*/
#include <bits/stdc++.h>
using namespace std;

int countDigitOne(int n) {
        if(n<=0){
            return 0;
        }
        if( n<10 ){
            return 1;
        }

        int len= to_string(n).length();
        int base = pow(10,len-1);
        int firstdigit= n/base;
        int remainder= n%base;
        int oneInbase=0;

        if(firstdigit==1){
             oneInbase= n-base+1;
           
        }
        else{
             oneInbase=base;
        }

        return countDigitOne(remainder) +oneInbase + firstdigit*countDigitOne(base-1);

    }
int main(){

	int n;
	cout<<"enter the number:"<<endl;
	cin>>n;
	int ans= countDigitOne(n);
	cout<<ans;
	return 0;
}
