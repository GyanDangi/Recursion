#include<bits/stdc++.h>
using namespace std;

class Node
{

public:
	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void insertAtHead(Node *&head, int data)
{

	Node *temp = new Node(data);
	temp->next = head;
	head = temp;
}

void insertAtTail(Node *&tail, int data)
{

	Node *temp = new Node(data);
	tail->next = temp;
	tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int data)
{

	if (position == 1)
	{
		insertAtHead(head, data);
		return;
	}
	Node *temp = head;
	int cnt = 1;
	while (cnt < position - 1)
	{
		temp = temp->next;
		cnt++;
	}

	if (temp->next == NULL)
	{
		insertAtTail(tail, data);
		return;
	}

	Node *nodeToInsert = new Node(data);
	nodeToInsert->next = temp->next;
	temp->next = nodeToInsert;
}

void PrintLL(Node *head)
{
	Node *temp = head;

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


Node* reverseIterative(Node* head){

	Node*curr= head;
	Node*prev=NULL;
	Node*forward;
	
	while (curr!=NULL)
	{
		forward = curr->next;
		curr->next=prev;
		prev=curr;
		curr= forward;
	
	}

	return prev;

}

Node* kreverse(Node* head, int &k){

	if(head==NULL){
		return NULL;
	}

	// 1 case:
	Node*curr=head;
	Node*prev=NULL;
	Node*forward;
	int count=0;

	while(curr!=NULL && count<k){
		forward=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forward;
		count++;
	}

	// Recursion ka kaam:
	if(forward!=NULL){
		head->next= kreverse(forward, k);
	}

	return prev;
}

int main(){

	Node*head= new Node(10);
	Node*tail=head;
	insertAtTail(tail,12);
	insertAtTail(tail,13);
	insertAtTail(tail,14);
	PrintLL(head);
	// Node*prev= reverseIterative(head);
	int k=2;
	head =kreverse(head,k);
	PrintLL(head);
	// PrintLL(prev);
	return 0;
}