/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
    Node *list;

public:
    LinkedList()
    {
        start = NULL;
        list = NULL;
    }

    void insertAtBeg(int data)
    {
        Node *p = new Node();
        Node *temp = start;
        p->info = data;

        if (start == NULL)
        {
            start = p;
            p->next = start;
        }
        else
        {
            temp = start;
            while (temp->next != start)
            {
                temp = temp->next;
            }
            temp->next = p;
            p->next = start;
            start = p;
        }
    }

    void deleteAtBeg()
    {
        int x;
        Node *temp = start;
        if (start == NULL)
        {
            cout << "List is empty";
            return;
        }
        while (temp->next != start)
            temp = temp->next;

        if (temp == start)
        {
            cout << "List is empty";
            x = start->info;
            delete temp;
        }
        else
        {
            x = start->info;
            start = start->next;
            temp->next = start;
        }

        cout << "Deleted Node: " << x << endl;
    }
    void deleteAtBetween(int val)
    {
        Node *p = start;
        Node *q = NULL;
        int x;

        if (start == NULL)
        {
            cout << "List is empty";
            return;
        }
        else
        {
            while (p != NULL && p->info != val)
            {
                q = p;
                p = p->next;
            }
            if (p == NULL)
            {
                cout << "Invalid Value";
                return;
            }
            if (q == NULL)
            {
                start = p->next;
            }
            else
            {
                q->next = p->next;
            }
            x = p->info;
            delete p;
            cout << "Deleted Node: " << x << endl;
        }
    }
    void deleteAtEnd()
    {
        int x;
        Node *temp = start;

        if (start == NULL)
        {
            cout << "List is empty";
            return;
        }
        while (temp->next->next != start)
            temp = temp->next;

        x = temp->next->info;
        temp->next = start;

        cout << "Deleted Node: " << x << endl;
    }

    void displayList()
    {
        Node *temp = start;
        cout << "List: " << temp;
        if (temp == NULL)
            cout << "List is empty";
        else if (temp->next == start)
        {
            cout << temp->info;
        }
        else
        {
            while (temp->next != start)
            {
                cout << temp->info << "  -->  ";
                temp = temp->next;
            }
            cout << temp->info << "  -->  ";
        }
    }
};

int main()
{
    int ch;
    int data;
    LinkedList ll;
    ll.insertAtBeg(10);
    ll.insertAtBeg(20);
    ll.insertAtBeg(30);
    ll.insertAtBeg(40);
    ll.displayList();
    while (1)
    {
        cout << "\n1. Delete at beginning: " << endl;
        cout << "2. Delete at between: " << endl;
        cout << "3. Delete at end: " << endl;
        cout << "4. Display List: " << endl;
        cout << "5. Exit: " << endl;

        cout << "\nEnter operation to perform: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            ll.deleteAtBeg();
            break;
        case 2:
            cout << "Enter data to delete: ";
            cin >> data;
            ll.deleteAtBetween(data);
            break;
        case 3:
            ll.deleteAtEnd();
            break;
        case 4:
            ll.displayList();
        }
    }

    return 0;
}
