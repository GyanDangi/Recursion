// reverse LInked list given by value k:

// Reverse linked list using recrusion:


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

    // condition jaha code fasega:
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}
void insertAtTail(Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node *&tail, Node *&head, int pos, int data)
{
    // insert at Head
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Tail:
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    // new node to insert
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void printLL(Node *&head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print LL using Recursion:
void PrintLLRecur(Node* &head){

   
    // base case:
    if(head==NULL){
        return ;
    }
    cout<<head->data<<"->";
    PrintLLRecur(head->next);
}

Node* reverseLL(Node* &head){

    if(head==NULL || head->next==NULL){

        return head ;
    }

    Node*chotaHead = reverseLL(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotaHead;
}

Node* reverseByk(Node*head, int k){

    // base case:
    if(head==NULL){
        return NULL;
    }

    Node*prev=NULL;
    Node*curr=head;
    Node*forward;
    int count=0;

    // 1st k group ko reverse kr rhe hai:
    while (curr!=NULL && count<k)
    {
       forward=curr->next;
       curr->next=prev;
       prev=curr;
       curr=forward;
       count++;
    }

    // baki recursion sambhal lega
    if(forward!=NULL){
        head->next =reverseByk(forward,k);
    }

    return prev;
    

}

int main()
{
Node*head=NULL;
Node*tail=NULL;
Node*root=new Node(5);
head=tail=root;
insertAtTail(tail,4);
insertAtTail(tail,1);
insertAtTail(tail,3);
insertAtTail(tail,2);
// printLL using recursion:
PrintLLRecur(head);
cout<<endl;
// head= reverseLL(head);
int k=2;
 head =reverseByk(head, k);
PrintLLRecur(head);
return 0;
}