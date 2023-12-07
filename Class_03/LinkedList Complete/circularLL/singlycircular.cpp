#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value= this->data;
        if(this->next!=NULL){
          delete next;
          next = NULL;
        }
        cout<<"memory is free for data:"<<value<<endl;
    }
};

void insertNode(Node* &tail, int element , int  data){
    // assuming that the element is present in the list:

    //case1: empty list:
    if(tail==NULL){
        Node*newNode= new Node(data);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        // Non empty list:
        Node*curr=tail;
        while (curr->data!=element)
        {
            curr=curr->next;
        }
        // elemment is found: curr is poiting that element:
        Node*temp= new Node(data);
        temp->next=curr->next;
        curr->next=temp;
        
    }
}
void deleteNode(Node* &tail, int val){

    if(tail==NULL){
        cout<<"list is empty"<<" ";
    }
    else{
        // list is non-empty:
        Node*prev=tail;
        Node*curr=prev->next;

        while (curr->data!=val)
        {
            
            prev=curr;
            curr=curr->next;
        }
        // 1 node Linked list:
        if(curr==prev){
            tail=NULL;
        }
        //>=2 node ke liye
        prev->next=curr->next;
        if(tail==curr){
            tail=prev;
        }
        curr->next= NULL;
        delete curr;
        
    }
}

void PrintCL(Node* &tail){
    Node*temp=tail;
    // cout<<tail->data<<" ";
    if(tail==NULL){
        cout<<"circular linked list is empty"<<endl;
    }
    do
    {
       cout<<tail->data<<" ";
       tail=tail->next;
         
    } while (tail!=temp);
    
    cout<<endl;
}


int main(){

    Node*tail=NULL;
    // empty list me insert kr rhe hai:
   insertNode(tail,5,4);
//    cout<<tail->data<<endl;
//    PrintCL(tail);
   insertNode(tail,4,3);
   insertNode(tail,3,5);
//    insertNode(tail,3,6);
//    insertNode(tail,4,2);
   PrintCL(tail);
   deleteNode(tail,5);
   PrintCL(tail);



    return 0;
}