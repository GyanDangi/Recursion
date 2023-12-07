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

bool checkMirror(node*root1, node*root2){

    // Base Case:
    if(root1== NULL && root2==NULL)
        return true;
    if(root1!=NULL && root2==NULL)
        return false;
    if(root1==NULL && root2!=NULL)
        return false;
    if(root1->data!=root2->data)
        return false;            


    bool opt1=checkMirror(root1->left,root2->left);
    bool opt2=checkMirror(root1->right, root2->left);
    
    return opt1&&opt2;
}

bool isSymmetricTree(node*root){

    if(root==NULL){
        return true;
    }

    return checkMirror(root->left, root->right);
}


int main(){
    // 3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
    node *root =NULL;
    cout<<"enter data to build tree:"<<endl;
    root =buildTree(root);
    return 0;
}