
#include <iostream>

using namespace std;

class Queue
{
    int front, rear, size = 50;
    int *queue = new int[size];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int item)
    {
        if (!isFull())
        {
            rear += 1;
            queue[rear] = item;
            if (rear == 0)
                front += 1;
        }
        else
        {
            cout << "Queue overflowed";
        }
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            return queue[front++];
        }
        else
        {
            cout << "Queue underflowed";
            return 0;
        }
    }

    bool isFull()
    {
        if (rear == size - 1)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if ((rear == -1 && front == -1) || (front > rear))
            return true;
        else
            return false;
    }

    void display()
    {
        if (isEmpty())
            cout << "Stack undeflowed" << endl;
        else
        {

            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << "\t";
            }
        }
    }

    int stackPeek()
    {
        return queue[front];
    }
};

class Stack
{
    Queue q1;
    Queue q2;

public:
    void push(int item)
    {

        while (!q1.isEmpty() && !q2.isFull())
        {
            q2.enqueue(q1.dequeue());
        }

        q1.enqueue(item);

        while (!q2.isEmpty() && !q1.isFull())
        {
            q1.enqueue(q2.dequeue());
        }
    }

    void pop()
    {
        cout << "Your popped element is: " << q1.dequeue();
    }

    void display()
    {
        q1.display();
    }

    void peek()
    {
        cout << "Peeked element is: " << q1.stackPeek();
    }
};
int main()
{
    Stack st;
    int ch, item;

    while (1)
    {
        cout << "\n1.Push element into the stack\n";
        cout << "2.Pop element from the stack\n";
        cout << "3.Display stack\n";
        cout << "4.Peek element\n";
        cout << "\nEnter choice of operation:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter item to insert:";
            cin >> item;
            st.push(item);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.display();
            break;
        case 4:
            st.peek();
            break;
        }
    }

    return 0;
}
