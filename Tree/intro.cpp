#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    // constructor to build node:
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{

    // cout << "enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    // left tree build:
    // cout << "enter the data to insert in left of tree:" << data << endl;
    root->left = buildTree(root->left);

    // right tree build:
    // cout << "enter the data to inert in right of tree:" << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void leverlOrderTraversal(node *root)
{
    queue<node *> q;
    // if(root==NULL){
    //     return;
    // }

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void levelOrderTraversal2(node *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL;
    cout<<"enter the data:"<<endl;
    root = buildTree(root);
    cout << "printing level order traversal:" << endl;
    // leverlOrderTraversal(root);
    levelOrderTraversal2(root);

    return 0;
}