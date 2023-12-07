#include <bits/stdc++.h>
using namespace std;

void printDecreasing(int n){

    // BAse Case:
    if(n==1){
        cout<<n<<" ";
        return;
    }

    cout<<n<<" ";
    // Recursivve Relation:
    printDecreasing(n-1);
}
int main(){
    cout<<"enter the value of n:"<<endl;

    int n;
    cin>>n;
    printDecreasing(n);


}