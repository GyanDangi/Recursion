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

void postOrder(node *root){

    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
 

int main(){

     // 3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
    node*root=NULL;
    cout<<"Enter the data to build Tree:"<<endl;
    root= buildTree(root);
    cout<<"PostOrder Traversal:"<<endl;
    postOrder(root);
    cout<<endl;


    return 0;
}