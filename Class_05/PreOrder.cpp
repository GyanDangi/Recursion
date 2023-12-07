#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node*left;
    node*right;

    node(int data){

        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }



};

node *buildTree(node*root){
    int data;
    cin>>data;
    root = new node (data);

    if (data==-1){
        return NULL;
    }
    root->left=buildTree(root->left);
    root->right= buildTree(root->right);
    return root;
}

void preOrder(node *root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


int main(){

    node*root=NULL;
    cout<<"Enter the data to build Tree:"<<endl;
    root= buildTree(root);
    cout<<"PreOrder Traversal:"<<endl;
    preOrder(root);
    cout<<endl;


    return 0;
}