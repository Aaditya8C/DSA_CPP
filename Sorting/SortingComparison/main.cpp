#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

class InsertionSort
{
    int size;
    // int *arr = new int[size];
    std::vector<int> data;
    int value;

public:
    InsertionSort(){
          std::ifstream inputFile("data1.txt");


    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        // return 1;
    }
    
    while (inputFile >> value) {
        data.push_back(value);
    }
    
    inputFile.close();

    std::cout << "Data imported from file:\n";
    }

    void insertionSort()
    {
        for (int i = 0; i < data.size(); i++)
        {
            int key = data[i + 1];
            for (int j = i; j >= 0; j--)
            {
                if (key < data[j])
                {
                    int temp = data[j];
                    data[j] = key;
                    data[j + 1] = temp;
                }
            }
        }
    }
    
    void mergeSort(vector<int>& data, int l, int r)
    {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergeSort(data, l, mid);
        mergeSort(data, mid + 1, r);
        merge(data, l, mid, r);
    }

    void merge(vector<int>& data, int l, int mid, int r)
    {
        int subArrOne = mid - l + 1;
        int subArrTwo = r - mid;

        int temp1[subArrOne];
        int temp2[subArrTwo];

        for (int i = 0; i < subArrOne; i++)
        {
            temp1[i] = data[l + i];
        }

        for (int i = 0; i < subArrTwo; i++)
        {
            temp2[i] = data[mid + 1 + i];
        }

        int i = 0;
        int j = 0;
        int k = l;

        while (i < subArrOne && j < subArrTwo)
        {
            if (temp1[i] < temp2[j])
            {
                data[k] = temp1[i];
                k++;
                i++;
            }
            else
            {
                data[k] = temp2[j];
                k++;
                j++;
            }
        }

        while (i < subArrOne)
        {
            data[k] = temp1[i];
            k++;
            i++;
        }
        while (j < subArrTwo)
        {
            data[k] = temp2[j];
            k++;
            j++;
        }
    }
// {
    void display()
    {
        insertionSort();
        // mergeSort(data, 0,data.size() - 1);
        cout << "Sorted data" << endl;
        // for (int i = 0; i < data.size(); i++)
        //     cout << data[i] << endl;
    }
};
int main()
{ 
    InsertionSort ist;
    auto start_time = chrono::high_resolution_clock::now();
    ist.display();
    auto end_time = std::chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "\nTime taken by loop: " << duration.count() << " microseconds" << endl;

    return 0;
}
