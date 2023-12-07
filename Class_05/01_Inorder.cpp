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

void Inorder(node *root){

    // base case:
    if(root==NULL){
        return ;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main(){
    // 3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
    node *root =NULL;
    cout<<"enter data to build tree:"<<endl;
    root =buildTree(root);
    cout<<"Inorder Traversal:"<<endl; 
    Inorder(root);
    cout<<endl;
    return 0;
}