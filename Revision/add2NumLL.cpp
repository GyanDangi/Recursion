#include <bits/stdc++.h>
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

Node* reverseLL(Node*head){

	if(head==NULL || head->next==NULL)
	{
		return head;
	}

	Node* chotaHead= reverseLL(head->next );
	head->next->next=head;
	head->next=NULL;
	return chotaHead;

}

void add2LL(Node*head1, Node*head2,vector<int>&ans,int carry){

	if(head1==NULL && head2==NULL && carry ==0){
		return;
	}

	int sum = head1->data+head2->data+carry;
	int lastdigit= sum%10;
	carry= sum/10;
	ans.push_back(lastdigit);
	add2LL(head1->next,head2->next,ans, carry);
}

int main()
{	Node*head1=new Node(1);
	Node*tail1=head1;
	// insertAtTail(tail1,2);
	PrintLL(head1);
	Node*reverseh1= reverseLL(head1);
	// PrintLL(reverseh1);

	Node* head2 = new Node(3);
	Node*tail2= head2;
	insertAtTail(tail2,4);
	PrintLL(head2);
	Node*reverseh2=reverseLL(head2);
	// PrintLL(reverseh2);
	vector<int>ans;
	add2LL(reverseh1,reverseh2,ans,0);
	reverse(ans.begin(),ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}