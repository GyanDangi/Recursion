#include <bits/stdc++.h>

using namespace std;

int main(){


    // for (int i = 0; i <5; i++)
    // { 
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout<<"1"<<" ";
    //     }
        
    //     cout<<endl;
    // }

    string str="Gyan Prakash";
    // transform(str.begin(), str.end(),str.begin(), ::_tolower);
    cout<<str<<endl;
    transform(str.begin(), str.end(),str.begin(), ::toupper);
    
    cout<<str;
    
}