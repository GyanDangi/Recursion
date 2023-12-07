#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){

        this->data= data;
        this->next =NULL;
    }
    // destructor:
    ~Node(){
        int value =this->data;
        if(this->next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for data :"<<value<<endl;
    }
};

void insertAtHead(Node*&head, int data){

    Node *temp = new Node(data);
    temp->next =head;
    head=temp;
}

void insertAtTail(Node*&tail, int data){

    Node *temp = new Node(data);
    tail->next = temp;
    tail=temp;
}

void insertAtPosition(Node *&tail, Node*&head, int pos, int data){

    if(pos==1){
        insertAtHead(head,data);
        return ;
    }

    Node *temp =head;
    int cnt=1;
    while(cnt<pos-1){
        temp= temp->next;
        cnt++;
    }

    if(temp->next== NULL){
        insertAtTail(tail, data);
        return ;
    }

    Node *nodeToInsert= new Node(data);
    nodeToInsert->next = temp->next;
    temp->next =nodeToInsert;
}

void deleteNode(Node* &head, int pos){

        
    // 1st position:

    if(pos==1){
       Node * temp =head;
       head = head->next;
       temp->next = NULL;
        delete temp; 
    }
    else{
        Node*curr= head;
        Node*prev= NULL;

        int cnt=1;
        while(cnt<pos){
            prev =curr;
            curr= curr->next;
            cnt++;
        }
        prev->next =curr->next;
        curr->next =NULL;
        delete curr;
    }
}

void PrintLL(Node*&head){

    Node*temp =head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;

    }
    cout<<endl;
}

int main(){

    Node *head= new Node(10);
    Node*tail= head;
    insertAtHead(head,12);
    insertAtHead(head,72);
    PrintLL(head);
    insertAtTail(tail,23);
    insertAtTail(tail,24);
    PrintLL(head);
    cout<<"insert At poistion:"<<endl;
    insertAtPosition(tail,head,1,89);
    PrintLL(head);
    deleteNode(head,6);
    cout<<"After deleting the Node"<<endl;
    PrintLL(head);

    return 0;
}