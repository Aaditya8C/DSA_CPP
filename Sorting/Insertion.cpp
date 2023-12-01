#include <iostream>
using namespace std;

class InsertionSort
{
    int size;
    int *arr = new int[size];
public:
    InsertionSort()
    {
        cout << "Enter size of your array" << endl;
        cin >> size;

        for (int i = 0; i < size; i++)
        {
            cout << "Enter " << i << " th "
                 << "element to insert in array" << endl;
            cin >> arr[i];
        }
    }

    void sort()
    {
        for (int i = 0; i < size; i++)
        {
            int key = arr[i + 1];
            for (int j = i; j >= 0; j--)
            {
                if (key < arr[j])
                {
                    int temp = arr[j];
                    arr[j] = key;
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void display()
    {
        sort();
        for (int i = 0; i < size; i++)
            cout << arr[i] << endl;
    }
};
int main()
{
    InsertionSort ist;
    cout << "Your sorted array is:" << endl;
    ist.display();

    // return 0;
}