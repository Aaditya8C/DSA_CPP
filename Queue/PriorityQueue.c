#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int rear = -1;
int front = -1;
int arr[SIZE];
int priority[SIZE];

int main()
{
    printf("Enter queue elements with priority:\n");

    enqueue(10, 1);
    enqueue(90, 4);
    enqueue(30, 1);
    enqueue(40, 4);
    enqueue(80, 2);

    show();
    dequeue();
    dequeue();
    show();
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

void enqueue(int item, int priorityVal)
{
    if (isFull())
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear += 1;
        arr[rear] = item;
        priority[rear] = priorityVal;
    }
}

int peek()
{
    int highestPriorityIndex = 1;
    int elementWithHighPriority = priority[0];

    for (int i = 1; i <= rear; i++)
    {
        // comparing first array element with other elements & replacing it with next element whenever necesssary
        if (elementWithHighPriority < priority[i])
        {
            elementWithHighPriority = priority[i];
            highestPriorityIndex = i;
        }
        else if (elementWithHighPriority == priority[i])
        {
            if (arr[highestPriorityIndex] < arr[i])
            {
                highestPriorityIndex = i;
            }
        }
    }
    return highestPriorityIndex;
}

int dequeue()
{
    int highPrIndex = peek();
    if (isEmpty())
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Element deleted from queue:%d\n", arr[highPrIndex]);

        // need to shift elements as the random element will be removed due to this dequeue operation
        for (int i = highPrIndex; i <= rear; i++)
        {
            arr[i] = arr[i + 1];
            priority[i] = priority[i + 1];
        }
        rear--; // as we have shifted elements in the array we need to reduce value of rear
    }
}

void show()
{
    if (front == -1)
        printf("Empty queue\n");
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