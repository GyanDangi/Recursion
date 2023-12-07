#include <bits/stdc++.h>
using namespace std;


class Node{


    public:
    int data;
    Node*next;

    Node(int data){

        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int data){

    Node *temp = new Node(data);
    tail->next =temp;
    tail =temp;
}

void printLL(Node* &head){

    Node*temp =head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;
}


int main(){

    Node* node1 = new Node(10);
    Node*head = node1;
    Node*tail =node1;
    insertAtTail(tail,15);
    insertAtTail(tail,25);
    insertAtTail(tail,45);
    insertAtTail(tail,65);
    printLL(head);


    return 0;
}