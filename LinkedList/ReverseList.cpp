
#include <iostream>

using namespace std;


class Node{
    public:
        int info;
        Node* next;
        
        Node(){
            info = 0;
            next = NULL;
        }
};

class LinkedList{
    Node* start;
    public:
    
        LinkedList(){
            start = NULL;
        }
        
        void insertAtBeg(int data){
            Node* p = new Node();
            p->info = data;
            
            if(start == NULL){
                start = p;
                return;
            }
            p->next = start;
            start = p;
        }
        

        void reverseList(){
            Node* prev;
            Node* current;
            Node* next;
            current = start;
            prev = next = NULL;
            
            while(current != NULL){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            start = prev;
        }
        
       
        void displayList(){
            Node* temp = start;
            while(temp != NULL){
                cout << temp->info << '\t';
                temp = temp->next;
            }
        }
};
int main()
{
    LinkedList ll;
    ll.insertAtBeg(30);
    ll.insertAtBeg(20);
    ll.insertAtBeg(10);
    ll.insertAtBeg(40);
    ll.insertAtBeg(26);
    ll.displayList();
    
    cout << endl << endl;
    ll.reverseList();
    cout << "List after reversal:" << endl;
    ll.displayList();
    cout << endl << endl;

    return 0;
}



