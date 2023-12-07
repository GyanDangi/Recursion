#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* next;

    // constructor:
    node(int data){
        this->data=data;
        this->next =NULL;
    }
};

void insertAtHead(node* &head, int data){
    node* temp =new node(data);
   temp->next=head;
    head=temp;
}

void insertAttail(node* &tail, int data){
    node* temp = new node(data);
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(node* &tail, node*  &head, int data, int position){

    // Special Case:
    if(position==1){

        insertAtHead(head,data);
        return;
    }
    node*temp =head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    // when position is last:
    if(temp->next==NULL){
        insertAttail(tail,data);
        return;
    }
    node* nodeToInsert=new node(data);
    nodeToInsert->next=temp->next;
    temp->next= nodeToInsert;
}

void printLL(node* head){
    node*temp =head;

    while (temp!=NULL)
    {   
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;
}

void printLLRecur(node* &head){
    // Base Case:
    node*temp =head;
    if(temp==NULL){
        return;
    }

    cout<<temp->data<<" ";
    printLLRecur(head->next);
}

void kthNodefromlast(node* &head, int &k){

    // base case:
    if(head==NULL){
        return;
    }

    kthNodefromlast(head->next,k);

    // Wapas:
    k--;
    if(k==0){
        cout<<"kth node form end:"<<head->data<<" ";
    }

}
int main(){

    node *head= new node(10);
    node*tail=head;
    printLL(head);
    insertAtHead(head, 90);
    printLL(head);
    insertAttail(tail,78);
    printLL(head);
    insertAtPosition(tail,head, 12,3);
    insertAtPosition(tail,head, 126,1);
    // printLL(head);
    printLLRecur(head);
    cout<<endl;
    int k=4;
    kthNodefromlast(head,k);







    return 0;
}