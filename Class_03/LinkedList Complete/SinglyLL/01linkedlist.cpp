#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node* next;

    // constructor:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAthead(Node* &head, int data){
    Node*temp = new Node(data);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail, int data){
    Node *temp = new Node(data);
    tail->next =temp;
    tail=temp;
}


void printLL(Node* &head){
    Node*temp = head;

    while(temp!=NULL){

    cout<<temp->data<<" ";
    temp = temp->next;
    }

    cout<<endl;
}

int main()
{   
    // Node*node1= new Node();

    Node *node1 = new Node(10);
    // Node *node2 = new Node(12);
//    cout << node1->data<<endl;
   Node*head = node1;
   Node *tail =node1;
//    cout<<"Insert at head before:";
//    printLL(head);
//    insertAthead(head,12);
//    insertAthead(head,15);
//    insertAthead(head,13);
//    cout<<"Insert at Head after:";
//    printLL(head);
   cout<<"Before Inserting at Tail:"<<endl;
   printLL(head);
   insertAtTail(tail,24);
   insertAtTail(tail,25);
   insertAtTail(tail,234);
   cout<<"After inserting at Tail:"<<endl;
   printLL(head);

//     int a=9;
//    int*ptr=&a;
//    cout<<ptr<<endl;

    return 0;
}