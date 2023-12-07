// print the kth node from the last of the linked list;

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
    cout<<head->data<<" ";
    PrintLLRecur(head->next);
}

void kNodeformLast(Node* &head, int &k){

    // base case:
    if(head==NULL){
        return ;
    }

    // recursive call:
    kNodeformLast(head->next,k);

    k--;
    if(k==0){
        cout<< head->data;
    }
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
cout<<"Node form end"<<endl;
int k=2;
kNodeformLast(head,k);
return 0;
}