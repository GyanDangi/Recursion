#include <bits/stdc++.h>
using namespace std;

class Node{


	public:
	int data;
	Node*next;

	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};

void insertAtHead(Node* &head, int data){

	Node*temp= new Node(data);
	temp->next=head;
	head=temp;
}

void insertAtTail(Node*&tail, int data){

	Node*temp = new Node(data);
	tail->next=temp;
	tail=temp;
}

void insertAtPosition(Node*&tail,Node* &head, int position , int data){

	if(position==1){
		insertAtHead(head, data);
		return;
	}
	 Node*temp =head;
	int cnt=1;
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}

	if(temp->next==NULL){
		insertAtTail(tail,data);
		return;
	}

	Node*nodeToInsert =new Node(data);
	nodeToInsert->next=temp->next;
	temp->next= nodeToInsert;
}

void PrintLL(Node* head){
	Node*temp= head;

	while (temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	
}

void PrintLLUsingRecur(Node* head){

	if(head==NULL){
		return ;
	}

	cout<<head->data<<" ";
	PrintLLUsingRecur(head->next);
}


void printKfromLast(Node*head,int &k){

	if(head==NULL){
		return;
	}

	printKfromLast(head->next, k);
	k--;

	if(k==0){
		cout<<head->data;
	}

}

Node* reverseLL(Node*head){

	// base case:
	if(head==NULL || head->next==NULL){
		return head;
	}

	Node*chotaHead = reverseLL(head->next);
	head->next->next= head;
	head->next=NULL;
	return chotaHead;
	
}

int main(){

	Node* node1= new Node(10);
	Node*head = node1;
	Node*tail=node1;
	PrintLL(head);
	insertAtTail(tail ,12);
	insertAtTail(tail ,42);
	insertAtTail(tail,89);
	insertAtTail(tail ,23);
	PrintLL(head);
	insertAtPosition(tail,head, 6,87);
	PrintLL(head);
	cout<<head->data<<endl;
	cout<<tail->data<<endl;
	PrintLLUsingRecur(head);
	cout<<endl;
	// int k;
	// cout<<"enter the value of K:"<<endl;
	// cin>>k;
	// printKfromLast(head,k);
	head=reverseLL(head);
	PrintLL(head);

	return 0;
}