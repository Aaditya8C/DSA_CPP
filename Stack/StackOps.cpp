#include <iostream>

using namespace std;

class StackOps
{
    int size;
    int top;
    int *stack = new int[size];

public:
    StackOps()
    {
        top = -1;
        cout << "Enter size of the stack: ";
        cin >> size;
    }

    void push()
    {
        int item;

        if (isFull())
            cout << "Stack overflow\n";
        else
        {
            cout << "Enter item to push: ";
            cin >> item;
            top += 1;
            stack[top] = item;
        }
    }

    bool isFull()
    {
        if (top == size - 1)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    void pop()
    {
        if (isEmpty())
            cout << "Stack underflowed\n";
        else
        {
            cout << "Popped element is: " << stack[top] << "\n";
            top -= 1;
        }
    }
    void display()
    {
        if (isEmpty())
            cout << "No elements to display\n";
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << stack[i] << "\t";
            }
        }
    }
};

int main()
{
    StackOps stackObj;
    int ch;

    cout << "1.Push element\n";
    cout << "2.Pop element\n";
    cout << "3.Display stack\n";

    while (1)
    {
        cout << "\nEnter choice of operation:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            stackObj.push();
            break;
        case 2:
            stackObj.pop();
            break;
        case 3:
            stackObj.display();
            break;
        }
    }

    return 0;
}
