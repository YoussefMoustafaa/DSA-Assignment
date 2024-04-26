#include <iostream>
#include <vector>
// #include "../StudentClass/Student.cpp"
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


// quicksort mestive
template<class T>
int partition(T A[], int l, int h)
{
    T pivot = A[l];
    int i = l, j = h;

    while (i < j)
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
            swap(A[i], A[j]);
    }

    swap(A[l], A[j]);
    return j;
}

template<class T>
void quickSort(T A[], int l, int h)
{
    int j;
    if (l < h) {
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);
    }
}
