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
        else
        {
            while (temp->next != start)
                temp = temp->next;
            temp->next = p;
            p->next = start;
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
            // cout << "List is empty";
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

        while (temp->next != start)
        {
            cout << temp->info << "  -->  ";
            temp = temp->next;
        }
        if (temp->next == start)
        {
            cout << temp->info;
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
    ll.insertAtBetween(8, 2);
    ll.displayList();
    while (1)
    {
        cout << "\n1. Insert at beginning: " << endl;
        cout << "2. Insert at between: " << endl;
        cout << "3. Insert at end: " << endl;
        cout << "4. Delete at beginning: " << endl;
        cout << "5. Delete at between: " << endl;
        cout << "6. Delete at end: " << endl;
        cout << "7. Display List: " << endl;
        cout << "8. Exit: " << endl;

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
            ll.deleteAtBeg();
            break;
        case 5:
            cout << "Enter data to delete: ";
            cin >> data;
            ll.deleteAtBetween(data);
            break;
        case 6:
            ll.deleteAtEnd();
            break;
        case 7:
            ll.displayList();
            break;
        case 8:
            return 0;
        }
    }

    return 0;
}
