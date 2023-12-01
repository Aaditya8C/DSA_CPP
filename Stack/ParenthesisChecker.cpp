
#include <iostream>

#define SIZE 50

using namespace std;

class ParenthsisChecker
{
    char *stack = new char[SIZE];
    int top;

public:
    ParenthsisChecker()
    {
        top = -1;
    }

    void push(char item)
    {
        top += 1;
        stack[top] = item;
    }

    char pop()
    {
        char popElem;
        if (isEmpty())
            return 0;
        else
        {
            popElem = stack[top];
            top -= 1;
        }
        return popElem;
    }

    char peek()
    {
        return stack[top];
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool includesEnd(char item)
    {
        if (item == ')' || item == '}' || item == ']')
            return true;
        else
            return false;
    }
    bool includesStart(char item)
    {
        if (item == '(' || item == '{' || item == '[')
            return true;
        else
            return false;
    }

    bool isValidBracket(char opening, char closing)
    {
        if (opening == '(' && closing == ')')
        {
            return true;
        }
        else if (opening == '{' && closing == '}')
        {
            return true;
        }
        else if (opening == '[' && closing == ']')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    ParenthsisChecker checker;
    string expression;
    cout << "Enter expression: ";
    cin >> expression;
    bool isValid = true;

    for (int i = 0; i < expression.length(); i++)
    {
        if (checker.includesEnd(expression[i])){
            if (!checker.isEmpty())
            {
                char openingBracket = checker.peek();
                if (checker.isValidBracket(openingBracket, expression[i]))
                {
                    checker.pop();
                    continue;
                }
            }
            else
            {
                isValid = false;
                break;
            }
        }
        else if (checker.includesStart(expression[i])){
            checker.push(expression[i]);
        }
    }

    if (checker.isEmpty() && isValid)
        cout << "Valid expression";
    else
        cout << "Invalid expression";

    return 0;
}
