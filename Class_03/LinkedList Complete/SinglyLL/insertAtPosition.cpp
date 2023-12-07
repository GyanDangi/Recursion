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

int main()
{

    Node *head = new Node(10);
    Node *tail = head;

    insertAtTail(tail, 21);
    insertAtTail(tail, 24);
    insertAtTail(tail, 22);
    printLL(head);
    insertAtPosition(tail, head, 3, 45);
    insertAtHead(head, 13);
    printLL(head);
    insertAtPosition(tail, head, 1, 101);
    printLL(head);
    cout << "head:" << head->data << endl;
    cout << "tail:" << tail->data << endl;
    return 0;
}