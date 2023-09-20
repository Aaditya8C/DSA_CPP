#include <stdio.h>

int MAXSIZE = 5;
int stack[5];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;

    else
        return 0;
}

int isFull()
{
    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

void push(int item)
{
    if (!isFull())
    {
        top += 1;
        stack[top] = item;
    }
    else
    {
        printf("Stack is already full");
    }
}

int pop()
{
    int item;
    if (!isEmpty())
    {
        item = stack[top];
        top -= 1;
        return item;
    }
    else
    {
        printf("Stack is empty");
    }
}

int peek()
{
    return stack[top];
}

int main()
{
    push(20);
    push(41);
    push(85);
    push(800);
    push(74);

    printf("Element at the top of stack: %d", peek());

    printf("\nStack elements:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", stack[i]);
    }

    int poppedElem = pop();
    int poppedElem2 = pop();
    printf("\nPopped element: %d\n", poppedElem);
    printf("\nSecond Popped element: %d\n", poppedElem2);

    printf("Is Stack empty? %s\n", isEmpty() ? "true" : "false");
    printf("Is Stack full? %s\n", isFull() ? "true" : "false");
    return 0;
}
