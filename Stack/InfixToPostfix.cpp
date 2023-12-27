#include <iostream>
#include <string> 

#define SIZE 50

using namespace std;


class InfixToPostfix{
    char *stack = new char[SIZE];
    int top;

    public:
    InfixToPostfix(){
        top = -1;
    }   

    void push(char item)
    {
        if(!isFull()){    
            top += 1;
            stack[top] = item;
        }
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
    
    int peek()
    {
        return stack[top];
    }
    
    bool isFull(){
        if(top == SIZE - 1)
            return true;
        else
            return false;
    }
    
    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }
    
    
    bool includeExp(char item){
        if(item == '(' || item == '+' || item == '-' || item == '*' || item == '/')
            return true;
        else
            return false;
    }
    
    int getPriority(char item){
        switch(item){
            case '/':
            case '*':
                return 4;
                break;
            case '(':
                return 3;
                break;
            case '+':
            case '-':
                return 2;
                break;
            default:
                cout << "kdljewlkd";
                return 0;
        }
    }
};

int main()
{
    InfixToPostfix ip;
    string infix,postfix;
    cout<<"Enter infix expression: ";
    cin >> infix;
    
    for(int i = 0; i < infix.length(); i++){
        char ch = infix[i];
        
        if(ip.includeExp(ch)){
            if(ip.isEmpty())
                ip.push(ch);
            else{
                int op = ip.peek();
                while(ip.getPriority(ch) <= ip.getPriority(op)){
                    int result = ip.pop();
                    if(result != '(')
                        postfix += result;
                }
                ip.push(ch);
            }
        }
        else{
            postfix = postfix + ch;
        }
    }
    
    while(!ip.isEmpty()){
        char item = ip.pop();
        if(item != ')' || item != '(')
        {
            postfix += item;
        }
    }
    
    // cout << ip.getPriority('+');
    cout << postfix;
    
    

    return 0;
}




