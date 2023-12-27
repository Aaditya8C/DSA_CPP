// O(n)
#include <iostream>

#define SIZE 50

using namespace std;


class PostfixEvaluation{
    int *stack = new int[SIZE];
    int top;

    public:
    PostfixEvaluation(){
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
    PostfixEvaluation post;
    string postExpression;
    cout<<"Enter postfix expression: ";
    cin >> postExpression;
    
    
    for(int i = 0; i < postExpression.length(); i++){
        if(postExpression[i] == '+' || postExpression[i] == '-' || postExpression[i] == '*' || postExpression[i] == '/'){
            int operand2 = post.pop();
            int operand1 = post.pop();
            
            switch(postExpression[i]){
                case '+':
                    post.push(operand1 + operand2);
                    break;
                case '-':
                    post.push(operand1 - operand2);
                    break;
                case '*':
                    post.push(operand1 * operand2);
                    break;
                case '/':
                    post.push(operand1 / operand2);
                    break;
            }
        }else{
            post.push(postExpression[i] - '0');
        }
    }
    
    post.display();
    
    
    
    

    return 0;
}
