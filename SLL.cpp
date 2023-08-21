#include <iostream>
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

void insertAtHead(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *newnode = new Node(d);
        head = newnode;
    }
    else
    {
        Node *newnode = new Node(d);

        newnode->next = head;
        head = newnode;
    }
}

void insertAtTail(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *newnode = new Node(d);
        head = newnode;
    }
    else
    {
        Node *newnode = new Node(d);
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertAtPosition(Node *&head, int d, int pos)
{
    if (head == NULL)
    {
        Node *newnode = new Node(d);
        head = newnode;
    }
    else
    {
        if (pos == 1)
        {
            insertAtHead(head, d);
        }
        else
        {
            Node *newnode = new Node(d);
            Node *temp = head;
            int count = 1;

            while (count < pos - 1)
            {
                temp = temp->next;
                count++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void deleteHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteTail(Node *&head)
{
    Node *temp = head;
    Node *current = head;

    while (temp->next != NULL)
    {
        current = temp;
        temp = temp->next;
    }
    current->next = NULL;
    free(temp);
}

void deletePosition(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteHead(head);
    }
    else
    {
        Node *temp = head;
        Node *current = head;
        int count = 1;
        while (count < pos)
        {
            current = temp;
            temp = temp->next;
            count++;
        }
        current->next = temp->next;
        free(temp);
    }
}

void print(Node *&head)
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
    Node *node = new Node(10);
    cout << node->data << endl;
    cout << node->next << endl;

    Node *head = node;

    print(head); // Initial LL

    insertAtHead(head, 15); // 15 at head
    insertAtHead(head, 5);  // 5 at head

    insertAtTail(head, 20); // 20 at tail
    insertAtTail(head, 30); // 30 at tail

    insertAtPosition(head, 10, 2); // 18 at 2nd position
    insertAtPosition(head, 45, 4); // 45 at 4th position
    insertAtPosition(head, 25, 1); // 25 at 1st position
    insertAtPosition(head, 40, 9);

    print(head); // LL after insertion -> 25 5 10 15 45 10 20 30

    deleteHead(head);
    deleteTail(head);
    deletePosition(head, 4);
    deletePosition(head, 6);
    deletePosition(head, 1);

    print(head);

    return 0;
}