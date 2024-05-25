#include <bits/stdc++.h>
using namespace std;

void printDecs(int n){

    if(n==0){
        return;
    }

    cout<<n<<" ";
    printDecs(n-1);
}

void printInc_Desc(int n){

    if(n==0){
        return ;
    }

    printInc_Desc(n-1);
    printDecs(n);
    cout<<n<<" ";
}
// void printIncreasingThenDecreasing(int n) {
//     if (n == 0) // Base case: If n is 0, print it and return
//         std::cout << n << " ";
//     else {
//         std::cout << n << " "; // Print current number
//         printIncreasingThenDecreasing(n - 1); // Recur for the next smaller number
//         std::cout << n << " "; // Print current number again after recursion
//     }
// }

void printIncreasingThenDecreasing(int n) {
    if (n == 0) // Base case: If n is 0, print it and return
        std::cout << n << " ";
    else {
        std::cout << n << " "; // Print current number
        printIncreasingThenDecreasing(n - 1); // Recur for the next smaller number
        if (n != 1) // To avoid printing 1 twice
            std::cout << n << " "; // Print current number again after recursion
    }
}

int main(){
    cout<<"enter the value of n"<<endl;
    int n;
    cin>>n;
    // printInc_Desc(n);
    printIncreasingThenDecreasing(n);
    


    return 0;
}