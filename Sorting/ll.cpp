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

public:
    LinkedList()
    {
        start = NULL;
    }

    void insertAtBeg(int data)
    {
        // 10 >> 20 >> 30 >> 40
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

    void insertAtBetween(int data, int pos)
    {
        Node *p = new Node();
        p->info = data;
        Node *temp = start;

        if (start == NULL)
        {
            start = p;
            p->next = start;
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
                temp = temp->next;
            if (temp == NULL)
            {
                cout << "Invalid position";
                return;
            }
            p->next = temp->next;
            temp->next = p;
        }
        // list->next = start;
    }

    void insertAtEnd(int data)
    {
        Node *p = new Node();
        p->info = data;
        Node *temp = start;

        if (start == NULL)
        {
            start = p;
            p->next = start;
        }
        else{
            while(temp->next != start)
                temp = temp->next;
            temp->next = p;
            p->next = start;
        }
    }

    void displayList()
    {
        Node *temp = start;
        if (temp->next == start)
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
    int data, pos;
    LinkedList ll;
    ll.insertAtBeg(10);
    ll.insertAtBeg(20);
    ll.insertAtBeg(30);
    ll.insertAtBeg(40);
    ll.insertAtEnd(500);
    ll.insertAtBetween(8,2);
    ll.displayList();
    while (1)
    {
        cout << "\n1. Insert at beginning: " << endl;
        cout << "2. Insert at between: " << endl;
        cout << "3. Insert at end: " << endl;
        cout << "4. Display List: " << endl;
        cout << "5. Exit: " << endl;

        cout << "\nEnter operation to perform: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            ll.insertAtBeg(data);
            break;
        case 2:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter position at which node should be inserted: ";
            cin >> pos;
            ll.insertAtBetween(data, pos);
            break;
        case 3:
            cout << "Enter data to insert: ";
            cin >> data;
            ll.insertAtEnd(data);
            break;
        case 4:
            ll.displayList();
        case 5:
            return 0;
        }
    }

    return 0;
}
