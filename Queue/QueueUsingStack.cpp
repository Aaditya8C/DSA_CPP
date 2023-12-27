// O(n)
#include <iostream>

using namespace std;

class Stack
{
private:
    int *stack = new int[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int item)
    {
        top += 1;
        stack[top] = item;
    }

    int pop()
    {
        int popElem;
        if (isEmpty())
            return 0;
        else
        {
            popElem = stack[top];
            top -= 1;
        }
        return popElem;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void display()
    {
        if (isEmpty())
            cout << "Queue undeflowed" << endl;
        else
        {

            for (int i = top; i >= 0; i--)
            {
                cout << stack[i] << "\t";
            }
            cout << endl;
        }
    }
};

class Queue
{
    Stack s1, s2;

public:
    void enqueue(int item)
    {
        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
        s1.push(item);
        while (!s2.isEmpty())
        {
            s1.push(s2.pop());
        }
    }

    void dequeue()
    {
        if (!s1.isEmpty())
        {

            cout << "Dequeued element is:" << s1.pop();
            cout << endl
                 << endl;
        }
        else
            cout << "Queue undeflowed" << endl;
    }

    void display()
    {
        s1.display();
    }
};

int main()
{
    Stack s1;
    Queue q;
    int item;

    cout << "Second stack" << endl;

    int ch;

    while (1)
    {
        cout << "1. Insert Element in queue\n";
        cout << "2. Delete element in queue\n";
        cout << "3. Display queue\n";
        cout << "\nEnter choice of operation:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter item to insert: ";
            cin >> item;
            q.enqueue(item);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        }
    }

    return 0;
}
