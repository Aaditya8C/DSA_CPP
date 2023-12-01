
#include <iostream>

using namespace std;

class Node
{
public:
    int info;
    Node *next;

    Node()
    {
        info = 0;
        next = NULL;
    }
};

class LinkedList
{
    Node *start;

public:
    LinkedList()
    {
        start = NULL;
    }

    void insertAtBeg(int data)
    {
        Node *p = new Node();
        p->info = data;

        if (start == NULL)
        {
            start = p;
            return;
        }
        p->next = start;
        start = p;
    }

    void removeNthElement(int pos)
    {
        Node *p = start;
        Node *temp = start;
        Node *q = NULL;
        int size = 1;
        int x;

        if (start == NULL)
        {
            cout << "List is empty";
            return;
        }

        while (temp->next != NULL)
        {
            temp = temp->next;
            size++;
        }

        if (pos > size)
        {
            cout << "Invalid position" << endl;
            return;
        }
        for (int i = 0; i < size - pos; i++)
        {
            q = p;
            p = p->next;
        }
        if (q == NULL)
            start = p->next;
        else
            q->next = p->next;
        x = p->info;
        delete p;
        cout << "Deleted element: " << x;
    }

    void insertAtEnd(int data)
    {
        Node *p = new Node();
        p->info = data;
        Node *temp = start;

        if (temp == NULL)
        {
            start = p;
            return;
        }
        else
        {
            while (temp->next != NULL)
                temp = temp->next;
        }

        temp->next = p;
    }

    void displayList()
    {
        Node *temp = start;
        if (temp->next == NULL)
        {
            cout << temp->info;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->info << "  -->  ";
                temp = temp->next;
            }
        }
    }
};
int main()
{
    LinkedList ll;
    int pos;
    ll.insertAtBeg(10);
    ll.insertAtBeg(20);
    ll.insertAtBeg(30);
    ll.insertAtEnd(500);
    ll.displayList();

    while (1)
    {
        cout << "\nEnter nth last position to remove element: ";
        cin >> pos;
        ll.removeNthElement(pos);
        cout << "\nList after removing nth last element: " << endl;
        ll.displayList();
    }

    return 0;
}
