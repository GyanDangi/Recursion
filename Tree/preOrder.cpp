#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>

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
node* buildTree(node*root){
    int data;
    cin>>data;
    root= new node(data);

    if(data==-1){
        return NULL;
    }
    //left tree build:
    root->left= buildTree(root->left);
    // right tree build:
    root->right=buildTree(root->right);

    return root;
}

void preOrder(node *root){
    if(root== NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root){
    if(root==NULL){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void inOrder(node*root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){

    node*root=NULL;
    cout<<"enter the data:"<<endl;
    root=buildTree(root);
    cout<<"printing preorderTraversal:"<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"printing postorderTraversal:"<<endl;
    postOrder(root);
    cout<<endl;
    cout<<"printing InorderTraversal:"<<endl;
    inOrder(root);
    cout<<endl;


    return 0;
}