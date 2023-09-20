/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

#define SIZE 50

using namespace std;


class InfixEvaluation{
    int *stack = new int[SIZE];
    int top;

    public:
    InfixEvaluation(){
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
    
    void display(){
        while(!isEmpty()){
            cout << pop();
        }
    }
};

int main()
{
    InfixEvaluation infix;
    string infixExpression;
    cout<<"Enter postfix expression: ";
    cin >> infixExpression;
    
    
    for(int i = infixExpression.length() - 1; i >= 0; i--){
        if(infixExpression[i] == '+' || infixExpression[i] == '-' || infixExpression[i] == '*' || infixExpression[i] == '/'){
            int operand1 = infix.pop();
            int operand2 = infix.pop();
            
            switch(infixExpression[i]){
                case '+':
                    infix.push(operand1 + operand2);
                    break;
                case '-':
                    infix.push(operand1 - operand2);
                    break;
                case '*':
                    infix.push(operand1 * operand2);
                    break;
                case '/':
                    infix.push(operand1 / operand2);
                    break;
            }
        }else{
            infix.push(infixExpression[i] - '0');
        }
    }
    
    infix.display();
    
    
    
    

    return 0;
}
