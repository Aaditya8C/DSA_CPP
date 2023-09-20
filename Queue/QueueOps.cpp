
#include <iostream>

using namespace std;


class Queue{
    int front,rear,size;
    int *queue = new int[size];
    
    public:
        Queue(){
            front = -1;
            rear = -1;
            cout << "Enter size of the queue: ";
            cin >> size;
            
        }
        
        void enqueue(int item){
            if(!isFull()){
                rear += 1;
                queue[rear] = item;
                if(rear == 0)
                    front += 1;
            }else{
                cout << "Queue overflowed";
            }
        }
        
        void dequeue(){
            if(!isEmpty()){
                cout << "\nDequeued element is:" << queue[front];
                front += 1;
            }else{
                cout << "Queue underflowed";
            }
        }
        
        bool isFull(){
            if(rear == size - 1)
                return true;
            else
                return false;
        }
        
        bool isEmpty(){
            if((rear == -1 && front == -1) || (front > rear))
                return true;
            else
                return false;
        }
        
        void display(){
            for(int i = 0; i <= rear;i++){
                cout << queue[i] << "\t";
            }
        }
    
};

int main()
{
    Queue queue;
    int ch,item;

    while (1)
    {
        cout << "\n1.Insert element into the queue\n";
        cout << "2.Delete element from the queue\n";
        cout << "3.Display queue\n";
        cout << "\nEnter choice of operation:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter item to insert:";
            cin >> item;
            queue.enqueue(item);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.display();
            break;
        }
    }

    return 0;
}

