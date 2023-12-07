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



int maxDepth(node*root){

    if(root==NULL){
        return 0;
    }

    int leftAns=maxDepth(root->left);
    int rightAns=maxDepth(root->right);

    int finalAns=max(leftAns,rightAns);
    return finalAns+1;
}

int Diameter(node*root){

    if(root==NULL){
        return 0;
    }

    int ld= Diameter(root->left);
    int rd=Diameter(root->right);
    int lh= maxDepth(root->left);
    int rh=maxDepth(root->right);
    int selfd=lh+rh+1;
    return max(max(ld,rd),selfd);
}



int main(){
    // 3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
    node*root = NULL;
    cout<<"enter data to build Tree:"<<endl;
    root=buildTree(root);
   int diameter=Diameter(root);
    cout<<"Diameter of the tree is:"<<diameter<<endl;


    return 0;
}