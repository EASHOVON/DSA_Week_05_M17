#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    // Constructor Creating
    Node(int val)
    {
        // Initializing value and next member
        value = val;
        Next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val)
{
    // 1st step: NewNode Creation
    Node *newNode = new Node(val);
    // 2nd step: Update
    newNode->Next = head;
    head = newNode;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";
        n = n->Next;
    }
    cout << endl
         << endl;
}

int main()
{
    Node *head = NULL;
    int value;
    cout << "Choice 1: Insertion at head" << endl
         << "Choice 2: Insertion at tail" << endl
         << "Choice 3: Exit" << endl
         << endl;
    cout << "Next Choice: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        cout << "Enter the value: ";
        cin >> value;
        switch (choice)
        {
        case 1:
            insertAtHead(head, value);
            break;
        case 2:
            insertAtTail(head, value);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    display(head);
    return 0;
}
