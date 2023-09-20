/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

#define SIZE 50

using namespace std;


class ParenthsisChecker{
    char *stack = new char[SIZE];
    int top;

    public:
    ParenthsisChecker(){
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
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    
    bool includesEnd(char item){
        if(item == ')' || item == '}' || item == ']')
            return true;
        else
            return false;
    }
    bool includesStart(char item){
        if(item == '(' || item == '{' || item == '[')
            return true;
        else
            return false;
    }
    
    bool isValidBracket(char opening,char closing){
        if(opening == '(' && closing == ')'){
            return 0;
        }else if(opening == '{' && closing == '}'){
            return 0;
        }else if(opening == '[' && closing == ']'){
            return 0;
        }else{
            return 1;
        }
    }
};

int main()
{
    ParenthsisChecker checker;
    string expression;
    cout<<"Enter expression: ";
    cin >> expression;
    
    
    for(int i = 0; i < expression.length(); i++){
        if(checker.includesEnd(expression[i])){
            char openingBracket = checker.pop();
            if(checker.isValidBracket(openingBracket,expression[i])){
                // cout << "Invalid Expression";
                break;
            }
        }else if(checker.includesStart(expression[i])){
            checker.push(expression[i]);
        }
    }
    
    if(checker.isEmpty())
        cout << "Valid expression";
    else
        cout << "Invalid expression";
    
    
    
    

    return 0;
}


