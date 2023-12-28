// O(n)
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
    string prefixExpression;
    cout<<"Enter prefix expression: ";
    cin >> prefixExpression;
    
    
    for(int i = prefixExpression.length() - 1; i >= 0; i--){
        if(prefixExpression[i] == '+' || prefixExpression[i] == '-' || prefixExpression[i] == '*' || prefixExpression[i] == '/'){
            int operand1 = infix.pop();
            int operand2 = infix.pop();
            
            switch(prefixExpression[i]){
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
            infix.push(prefixExpression[i] - '0');
        }
    }
    
    infix.display();
    
    
    
    

    return 0;
}
