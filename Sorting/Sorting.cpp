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

template <class T>
void selectionSort(T arr[], int n) //{4, 23, 67, 89, 10, 12, 1, 14, 899, -97, 0, 154, 25, 1447, 69};

{

    for (int i = 0; i < n - 1; i++)
    {
        int least = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[least] > arr[j])
                least = j;
        }
        swap(arr[i], arr[least]);
    }
}

template <class T>
void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

template <class T>
void merge(T arr[], int l, int m, int r)
{
    // define sizes
    int s1 = m - l + 1;
    int s2 = r - m;

    // create arrays

    T a1[s1];
    T a2[s2];
    // copy data to temp arrays
    for (int i = 0; i < s1; i++)
    {
        a1[i] = arr[l + i];
    }
    for (int i = 0; i < s2; i++)
    {
        a2[i] = arr[m + 1 + i];
    }

    // remerging arrays
    int i = 0, j = 0, k = l;
    while (i < s1 && j < s2)
    {
        if (a1[i] <= a2[j])
        {
            arr[k++] = a1[i++];
        }
        else
        {
            arr[k++] = a2[j++];
        }
    }
    while (i < s1)
    {
        arr[k++] = a1[i++];
    }
    while (j < s2)
    {
        arr[k++] = a2[j++];
    }
}

template <class T>
void mergeSort(T arr[], int l, int r)
{
    if (l < r)

    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    //{4, 23, 67, 89, 10, 12, 1, 14, 899, -97, 0, 154, 25, 1447, 69
}

template <class T>
int partition(T arr[], int l, int r)
{
    int i = l;
    int j = r;
    int piv = l;
    while (true)
    {
        while (arr[piv] < arr[j])
        {
            j--;
        }
        if (piv == j)
        {
            break;
        }
        else
        {
            swap(arr[piv], arr[j]);
            piv = j;
        }
        while (arr[piv] > arr[i])
        {
            i++;
        }
        if (piv == i)
        {
            break;
        }
        else
        {
            swap(arr[piv], arr[i]);
            piv = i;
        }
    }
    return piv;
}

template <class T>
void quickSort(T arr[], int l, int r)
{
    if (l < r)
    {
        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}