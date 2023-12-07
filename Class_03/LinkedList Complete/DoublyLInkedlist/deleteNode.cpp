#include <bits/stdc++.h>

using namespace std;

class Node{

    public:
    int data;
    Node*prev;
    Node*next;

    Node(int data){
        this->data=data;
        this->next =NULL;
        this->prev =NULL;
    }

    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next =NULL;
        }
        cout<<"Memory free for:"<<value<<endl;
    }
};

void insertAtHead(Node* &head, int data){

    Node* temp =new Node(data);
    temp->next =head;
    head->prev=temp;
    head=temp;
}

void insertAtTail(Node* &tail, int data){
    Node*temp =new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtPosition(Node* &tail, Node* &head, int pos, int data){

    if(pos==1){
        insertAtHead(head,data);
        return ;
    }

    Node*temp=head;
    int cnt=1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* nodetoInsert= new Node(data);
    nodetoInsert->next=temp->next;
    temp->next->prev=nodetoInsert;
    temp->next=nodetoInsert;
    nodetoInsert->prev=temp;

    
}
void printLL(Node* &head, Node* &tail){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
    cout<<"Head:"<<head->data<<endl;
    cout<<"tail:"<<tail->data<<endl;
}

void deleteNode(int position, Node* &head){

    // deleting 1st node
    if(position==1){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node*curr=head;
        Node*prev=NULL;
        int cnt=1;

        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        // curr->next->prev=prev;
        prev->next=curr->next;
        curr->prev=NULL;
        curr->next=NULL;
        delete curr;
    }
}

int main(){

    Node*head= new Node(10);
    Node*tail=head;
    insertAtPosition(tail, head, 1,19);
    insertAtPosition(tail, head, 3,29);
    insertAtPosition(tail, head, 2,12);
    printLL(head,tail);
    insertAtHead(head,23);
    printLL(head,tail);
    deleteNode(5,head);
    printLL(head,tail);



    return 0;
}