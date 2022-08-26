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

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
int countLength(Node *&head);
void insertAtSpecificPosition(Node *&head, int pos, int value);

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

int countLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }

    return count;
}

void insertAtSpecificPosition(Node *&head, int pos, int value)
{
    int i = 0;
    Node *newNode = new Node(value);
    Node *temp = head;
    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }

    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int main()
{
    Node *head = NULL;
    int value, position;
    cout << "Choice 1: Insertion at head" << endl
         << "Choice 2: Insertion at tail" << endl
         << "Choice 3: Insertion at specific position" << endl
         << "Choice 0: Exit" << endl
         << endl;
    cout << "Next Choice: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the Desired Position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }

    cout << endl
         << "Linked List: ";
    display(head);
    cout << "Length of the list: " << countLength(head) << endl;
    return 0;
}
