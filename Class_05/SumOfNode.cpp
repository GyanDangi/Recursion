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
node* buildTree(node*root){
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }
    
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}

int treeSum(node*root){

    if(root==NULL){
        return 0;
    }

    int leftsum=treeSum(root->left);
    int rightsum=treeSum(root->right);

    return leftsum+rightsum+root->data;
}



int main(){
    // 3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
    node*root = NULL;
    cout<<"enter data to build Tree:"<<endl;
    root=buildTree(root);
    int sumofnode=treeSum(root);
    cout<<"the sum of nodes of Tree is:"<<sumofnode<<endl;
    
    


    return 0;
}