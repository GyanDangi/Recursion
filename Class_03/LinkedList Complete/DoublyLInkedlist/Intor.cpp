#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*prev;
    Node*next;


    // constructor:
    Node(int data){
        this->data =data;
        this->next = NULL;
        this->prev =NULL;
    }


};

void PrintLL(Node* &head){

    Node*temp = head;

    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;
    
    
}

int getLength(Node* &head){

    Node*temp =head;
    int len=0;
    while (temp!=NULL)
    {
        len++;
        temp =temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,int data){
    Node*temp =new Node(data);
    temp->next =head;
    head->prev=temp;
    head=temp;
}

void insertAtTail(Node* &tail, int data){
    Node*temp = new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtPosition(Node*&tail, Node*&head,int data, int position){
     
     if(position==1){
        insertAtHead(head,data);
        return;
     }
     Node*temp =head;
     int cnt=1;
     while (cnt<position-1)
     {
        temp= temp->next;
        cnt++;
     }
    
     if(temp->next==NULL){
        insertAtTail(tail,data);
       return;
     }
     
     Node*nodetoInsert = new Node(data);
     nodetoInsert->next =temp->next;
     temp->next->prev=nodetoInsert;
     temp->next=nodetoInsert;
     nodetoInsert->prev=temp;
     

     
}

int main(){

    Node*head= new Node(10);
    Node*tail=head;
    insertAtHead(head,12);
    PrintLL(head);
    insertAtTail(tail,32);
    PrintLL(head);
    insertAtPosition(tail,head,23,4);
    PrintLL(head);

    cout<<getLength(head);


    return 0;
}