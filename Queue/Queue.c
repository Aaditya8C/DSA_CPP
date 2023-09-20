#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int rear = -1;
int front = -1;
int arr[SIZE];

int main()
{
    int ch;
    while (1)
    {
        printf("1.Enqueue Ops\n");
        printf("2.Dequeue Ops\n");
        printf("3.Display queue\n");
        printf("4.Exit\n");

        printf("Enter choice of ops: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("Unknown choice");
            break;
        }
    }
}

int isFull()
{
    if (rear == SIZE - 1 && front == 0)
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

void enqueue()
{
    int item;
    if (isFull())
        printf("Queue Overflow");
    else
    {
        if (front == -1)
            front = 0;
        printf("Element to be inserted in the Queue: ");
        scanf("%d", &item);
        rear += 1;
        arr[rear] = item;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Element deleted from queue:%d\n", arr[front]);
        if (front == rear)
            front = rear = -1;
        else
            front += 1;
    }
}

void show()
{
    if (front == -1)
        printf("Empty queue");
    else
    {
        printf("Queue:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d", arr[i]);
            printf("\n");
        }
    }
}