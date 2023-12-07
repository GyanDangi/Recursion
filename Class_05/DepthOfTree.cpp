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

void Inorder(node*root){

    if(root==NULL){
        return ;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);

}

int maxDepth(node*root){

    if(root==NULL){
        return 0;
    }

    int leftAns=maxDepth(root->left);
    int rightAns=maxDepth(root->right);

    int finalAns=max(leftAns,rightAns);
    return finalAns+1;
}



int main(){
    // 3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
    node*root = NULL;
    cout<<"enter data to build Tree:"<<endl;
    root=buildTree(root);
    cout<<"inoderTraversal:"<<endl;
    Inorder(root);
    cout<<endl;
    int height= maxDepth(root);
    cout<<"Height of the tree is:"<<height<<endl;


    return 0;
}