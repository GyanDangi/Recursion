#include <bits/stdc++.h>
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

	cout<<"enter the data to insert"<<endl;
	int data;
	cin>>data;
	root = new node(data);

	
	// base case: 
	if(data==-1){
		return NULL;
	}

	cout<<"enter the data to insert in left:"<<data<<endl;
	root->left =buildTree(root->left);

	cout<<"enter data to insert in right:"<<data<<endl;
	root->right= buildTree(root->right);

	return root;
}

void inorderTraversal(node*root){

	if(root==NULL){
		return ;
	}

	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}

void preorderTraversal(node*root){

	if(root==NULL){
		return ;
	}

	cout<<root->data<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void postOrder(node*root){
	if(root==NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}



int main(){
	//3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
	node*root= NULL;
	root= buildTree(root);

	 cout<<"Printing inorder:"<<endl;
	inorderTraversal(root);
	cout<<endl;

	cout<<"Printing Preorder:"<<endl;
	preorderTraversal(root);
	cout<<endl;

	cout<<"Printing postOrder:"<<endl;
	postOrder(root);
	return 0;
}