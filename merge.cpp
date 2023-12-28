#include <iostream>
using namespace std;

class MergeSort
{
    int size;
    int *arr = new int[size];

public:
    MergeSort()
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

    void mergeSort(int *arr, int l, int r)
    {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    void merge(int *arr, int l, int mid, int r)
    {
        int subArrOne = mid - l + 1;
        int subArrTwo = r - mid;

        int temp1[subArrOne];
        int temp2[subArrTwo];

        for (int i = 0; i < subArrOne; i++)
        {
            temp1[i] = arr[l + i];
        }

        for (int i = 0; i < subArrTwo; i++)
        {
            temp2[i] = arr[mid + 1 + i];
        }

        int i = 0;
        int j = 0;
        int k = l;

        while (i < subArrOne && j < subArrTwo)
        {
            if (temp1[i] < temp2[j])
            {
                arr[k] = temp1[i];
                i++;
                k++;
            }
            else
            {
                arr[k] = temp2[j];
                j++;
                k++;
            }
        }

        while (i < subArrOne)
        {
            arr[k] = temp1[i];
            i++;
            k++;
        }
        while (i < subArrOne)
        {
            arr[k] = temp2[j];
            j++;
            k++;
        }
    }
    void display()
    {
        mergeSort(arr, 0, size - 1);
        for (int i = 0; i < size; i++)
            cout << arr[i] << endl;
    }
};
int main()
{
    MergeSort mst;
    cout << "Your sorted array is:" << endl;
    mst.display();
}