#include <iostream>
#include <vector>
using namespace std;

template <class T>
void printArray(T arr[], int n)
{
    cout << '[';
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ,";
    }
    cout << arr[n - 1] << ']' << endl;
}

template <class T>
void printVector(vector<T> V)
{
    int n = V.size();
    cout << '[';
    for (int i = 0; i < n - 1; i++)
    {
        cout << V[i] << " ,";
    }
    cout << V[n - 1] << ']' << endl;
}

template <class T>
void insertionSort(T arr[], int n)
{
    T temp;
    int j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i; j > 0 && temp < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}


