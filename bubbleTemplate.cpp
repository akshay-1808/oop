#include <iostream>
using namespace std;

template <class T>
void bubbleSort(T arr[], int n);

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    float *arr = new float[n];         // create dynamic array using new      

    cout << "Enter the list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    // Deallocate the dynamic array
    delete[] arr;

    return 0;
}

template <class T>
void bubbleSort(T arr[], int n)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "The sorted list is:  ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}
