#include <iostream>
#include <vector>
using namespace std;
class Heap
{
    int heapSize;

public:
    void maxHeapify(vector<int>& arr,int i)
    {
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;
        int largest = i;


        if (left < heapSize && arr[left] > arr[i])
            largest = left;
        if (right < heapSize && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxHeapify(arr,largest);
        }
    }

    void buildMaxHeap(vector<int>& arr)
    {
        heapSize = arr.size();
        for (int i = (arr.size() / 2) - 1; i >= 0; i--)
            maxHeapify(arr,i);
    }

    void heapSort(vector<int>& arr)
    {
        for (int i = arr.size() - 1; i >= 1; i--)
        {
            swap(arr[0], arr[i]);
            heapSize -= 1;
            maxHeapify(arr,0);
        }
    }
};

int main()
{
    Heap hp;
    vector<int> arr{1, 2, 3, 4, 7, 8, 9, 10, 14, 16};
    hp.buildMaxHeap(arr);
    hp.heapSort(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}