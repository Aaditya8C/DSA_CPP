#include <iostream>

using namespace std;

// #define size 100

class ArrayOps
{
    int arr[100] = {2,8,4,5,6};
    int count = 0;
    // int size = sizeof(arr) / sizeof(arr[0]);
    
    
    public:
        
        ArrayOps(){
            // for(int i = 0; i < 4; i++){
            //     arr[i] = i + 2;
            //     count++;
                
            // }
            count = 5;
        }
        
        void display(){
            cout << "\nArray Elements: ";
            for(int i = 0;i < count;i++){
                cout << arr[i] << "\t";
            }
        }
        
        
        void insert(){
            int no,num;
            cout << "Enter no of elements to be inserted in array: ";
            cin >> no;
            
            for(int i = 0; i < no; i++){
                cout << "Enter " << i << " th number: ";
                cin >> num;
                arr[count] = num;
                count++;
                
            }
        }
        
        void deleteItem(){
            int num;
            cout << "\nEnter value to be deleted in array: ";
            cin >> num;
            
            for(int i = 0; i < count; i++){
                if(arr[i] == num){
                    count--;
                    for(int j = i; j < count;j++)
                    {
                        arr[j] = arr[j + 1];
                    }
                }
            }
        }
        
        void search(){
            int num;
            cout << "\nEnter value to be searched in array: ";
            cin >> num;
            
            for(int i = 0; i < count; i++){
                if(arr[i] == num){
                    cout << "Your searched value is: " << arr[i] << endl;
                    cout << "Location of your searched value is: " << i << endl; 
                    break;
                }
            }
        }
        
        void sort(){
            int sortType;
            cout << "\n1. Bubble Sort" << endl;
            cout << "2. Insertion Sort" << endl;
            
            cout << "Which sort do you want to perform? ";
            cin >> sortType;
            
            switch(sortType){
                case 1:
                    bubbleSort();
                    break;
                case 2:
                    insertionSort();
                    break;
                case 3:
                    cout << "Invalid Choice!!!!";
                    break;
            }
        }
        
        
        void bubbleSort(){
            //  {-2,45,0,11,-9}
            int temp;
            cout<<endl<<endl;
            for(int s = 0; s < count; s++){
                for(int i = 0; i < count - s - 1; i++){
                    if(arr[i] > arr[i + 1]){
                        temp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = temp;
                    }
                }
            }
            
            cout << "\nYour sorted array is: ";
            display();
        }
        
        void insertionSort(){
            // {2,8,4,5,6}
             // {2,8,4,5,6}
            int key,i,j;
            
            for(i = 1; i < count; i++){
                key = arr[i];
                j = i - 1;
                
                while(j >= 0 && arr[j] > key){
                    arr[j + 1] = arr[j];
                    j -= 1;
                }
                
                arr[j + 1] = key;
            }
            
            cout << "\nYour sorted array is: ";
            display();
            
        }
};

int main()
{
    ArrayOps array;
    array.display();
    
    int ch;
    
    while(1){
        cout << "\n\n1. Insert elements in array" << endl;
        cout << "2. Delete element in array" << endl;
        cout << "3. Search element in array" << endl;
        cout << "4. Sort the array" << endl;
        cout << "5. Display elements in array" << endl;
        
        cout << "\nEnter which operation to perform:";
        cin >> ch;
        
        switch(ch){
            case 1:
                array.insert();
                break;
            case 2:
                array.deleteItem();
                break;
            case 3:
                array.search();
                break;
            case 4:
                array.sort();
                break;
            case 5:
                array.display();
                break;
            default:
                cout << "Invalid Choice!!!!";
                break;
        }
    }

    return 0;
}
