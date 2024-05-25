#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *next;

    // constructor:
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertAttail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(node *&tail, node *&head, int data, int position)
{

    // Special Case:
    if (position == 1)
    {

        insertAtHead(head, data);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // when position is last:
    if (temp->next == NULL)
    {
        insertAttail(tail, data);
        return;
    }
    node *nodeToInsert = new node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void printLL(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printLLRecur(node *&head)
{
    // Base Case:
    node *temp = head;
    if (temp == NULL)
    {
        return;
    }

    cout << temp->data << " ";
    printLLRecur(head->next);
}
node *reverseLL(node *&head)
{

    node *curr = head;
    node *prev = NULL;
    node *forward;
    node *temp = head;
    while (temp != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

node *kReverse(node *head, int k)
{

    if(head==NULL || head->next==NULL){
        return head;
    }

    // 1 case hum solve kr rhe hai:
    node *prev = NULL;
    node *curr = head;
    node *forward;
    int cnt = 0;
    node *temp = head;
    while (temp != NULL && cnt < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    // Baki recursion kr denga:
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }

    return prev;
}
int main()
{

    node *head = new node(1);
    node *tail = head;
    // printLL(head);
    // insertAtHead(head, 90);
    // printLL(head);
    insertAttail(tail, 2);
    insertAttail(tail, 3);
    insertAttail(tail, 4);
    insertAttail(tail, 5);
    insertAttail(tail, 6);
    // printLL(head);
    // insertAtPosition(tail,head, 12,3);
    // insertAtPosition(tail,head, 126,1);
    // insertAtPosition(tail,head, 126,1);
    printLL(head);
    int k = 2;
    head = kReverse(head, 6);
    printLL(head);
    // printLLRecur(head);

    return 0;
}