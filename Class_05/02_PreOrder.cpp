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
    root = new node(data);

    if(data==-1){
        return NULL;
    }

    root->left =buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}

void preOrder(node*root){

    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    // 3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
    node*root =NULL;
    cout<<"enter data to build tree:"<<endl;
    root =buildTree(root);
    cout<<"preOrder Traversal:"<<endl;
    preOrder(root);

    return 0;
}