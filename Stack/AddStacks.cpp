#include <iostream>

#define SIZE 100

using namespace std;

class Stack
{
    int top;
    int *stack = new int[SIZE];

    public:
    Stack(){
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
};


int main()
{
    //Declaration
    Stack s1;
    Stack s2;
    Stack s3;
    string firstNum;
    string secondNum;
    int maxStackSize;
    int a;
    int b;
    int c;
    int carry = 0;
    int rep = 0;
    
    //User Input
    cout << "Enter first number: ";
    getline(cin, firstNum);
    cout << endl;

    cout << "Enter second number: ";
    getline(cin, secondNum);
    cout << endl;

    //Adding to stacks
    for (int i = 0; i < firstNum.length(); i++)
    {
        s1.push(int(firstNum[i] - '0'));
    }

    for (int i = 0; i < secondNum.length(); i++)
    {
        s2.push(int(secondNum[i] - '0'));
    }
    
    
    //Finding length of largest stack
    if (firstNum.length() > secondNum.length())
        maxStackSize = firstNum.length();
    else
        maxStackSize = secondNum.length();
    
    
    //Addition of two stacks
    while (!s1.isEmpty() || !s2.isEmpty())
    {
        a = s1.pop();
        b = s2.pop();
        if(rep == maxStackSize - 1)
            c = a + b + carry;
        else
            c = (a + b + carry) % 10;
        carry = (a + b) / 10;
        s3.push(c);
        rep++;
    }
    
    //Display added stack
    cout<<"Sum of two numbers is: ";
    for (int i = 0; i < maxStackSize; i++)
    {
        cout << s3.pop();
    }

       
    return 0;
}





