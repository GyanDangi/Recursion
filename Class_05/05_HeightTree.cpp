#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node*left;
    node*right;

    // constructor:
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node*root){

    int data;
    cin>>data;
    root =new node(data);

    if(data==-1){
        return NULL;
    }

    // left tree bulid:
    root->left =buildTree(root->left);
    // right tree build:
    root->right= buildTree(root->right);
    return root;
}
    int maxHeight(node*root){
        if(root ==NULL){
            return 0;
        }

        int leftHt= maxHeight(root->left);
        int rightHt= maxHeight(root->right);
        int ans= max(leftHt,rightHt);
        return ans+1;
    }

int main(){
    // 3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
    node *root =NULL;
    cout<<"enter data to build tree:"<<endl;
    root =buildTree(root);
    int ans=maxHeight(root);
    cout<<ans<<endl;
    return 0;
}