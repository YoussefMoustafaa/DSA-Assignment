#include <iostream>
#include <algorithm>
#include <vector>
#include "../StudentClass/Student.h"
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
int insertionSort(T arr[], int n)
{
    int comparisons = 0;
    T temp;
    int j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i; j > 0 && temp < arr[j - 1]; j--)
        {
            comparisons++;
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
    return comparisons;
}

int insertionSortForStudents(Student arr[], int n, bool compareByName = false)
{
    int comparisons = 0;
    Student temp;
    int j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        if (compareByName)
        {
            for (j = i; j > 0 && studentNameComparer(temp, arr[j - 1]); j--)
            {
                comparisons++;
                arr[j] = arr[j - 1];
            }
            arr[j] = temp;
        }
        else
        {
            for (j = i; j > 0 && studentGPAComparer(temp, arr[j - 1]); j--)
            {
                comparisons++;
                arr[j] = arr[j - 1];
            }
            arr[j] = temp;
        }
    }
    return comparisons;
}

template <typename T>
void shellSort(T arr, int size)
{
    int gap = size / 2;

    while (gap > 0)
    {
        for (int i = gap; i < size; i++)
        {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

//   for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
//     arr[j] = arr[j - gap];
// }
// arr[j] = temp;
int shellSortForStudent(Student arr[], int size, bool compareByName = false, bool desc = false)
{
    int gap = size / 2;
    int comparisons = 0;

    while (gap > 0)
    {
        for (int i = gap; i < size; i++)
        {
            Student temp = arr[i];
            int j;
            if (compareByName)
            {
                for (j = i; j >= gap && studentNameComparer(arr[j - gap], temp); j -= gap)
                {
                    arr[j] = arr[j - gap];
                    comparisons++;
                }
                arr[j] = temp;
            }
            else
            {
                for (j = i; j >= gap && studentGPAComparer(arr[j - gap], temp); j -= gap)
                {
                    arr[j] = arr[j - gap];
                    comparisons++;
                }
                arr[j] = temp;
            }
        }
        gap /= 2;
    }
    if (!desc)
    {
        for (int i = 0; i < size / 2; i++)
        {
            Student temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
        }
    }
    return comparisons;
}

// template <class T>
// void selectionSort(T arr[], int n) //{4, 23, 67, 89, 10, 12, 1, 14, 899, -97, 0, 154, 25, 1447, 69};

// {

//     for (int i = 0; i < n - 1; i++)
//     {
//         int least = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[least] > arr[j])
//                 least = j;
//         }
//         swap(arr[i], arr[least]);
//     }
// }

// template <class T>
// void bubbleSort(T arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         bool swapped = false;
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//                 swapped = true;
//             }
//         }
//         if (!swapped)
//             break;
//     }
// }

// template <class T>
// void merge(T arr[], int l, int m, int r)
// {
//     // define sizes
//     int s1 = m - l + 1;
//     int s2 = r - m;

//     // create arrays

//     T a1[s1];
//     T a2[s2];
//     // copy data to temp arrays
//     for (int i = 0; i < s1; i++)
//     {
//         a1[i] = arr[l + i];
//     }
//     for (int i = 0; i < s2; i++)
//     {
//         a2[i] = arr[m + 1 + i];
//     }

//     // remerging arrays
//     int i = 0, j = 0, k = l;
//     while (i < s1 && j < s2)
//     {
//         if (a1[i] <= a2[j])
//         {
//             arr[k++] = a1[i++];
//         }
//         else
//         {
//             arr[k++] = a2[j++];
//         }
//     }
//     while (i < s1)
//     {
//         arr[k++] = a1[i++];
//     }
//     while (j < s2)
//     {
//         arr[k++] = a2[j++];
//     }
// }

// template <class T>
// void mergeSort(T arr[], int l, int r)
// {
//     if (l < r)

//     {
//         int m = l + (r - l) / 2;
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);
//         merge(arr, l, m, r);
//     }
//     //{4, 23, 67, 89, 10, 12, 1, 14, 899, -97, 0, 154, 25, 1447, 69
// }

// template <class T>
// int partition(T arr[], int l, int r)
// {
//     int i = l;
//     int j = r;
//     int piv = l;
//     while (true)
//     {
//         while (arr[piv] < arr[j])
//         {
//             j--;
//         }
//         if (piv == j)
//         {
//             break;
//         }
//         else
//         {
//             swap(arr[piv], arr[j]);
//             piv = j;
//         }
//         while (arr[piv] > arr[i])
//         {
//             i++;
//         }
//         if (piv == i)
//         {
//             break;
//         }
//         else
//         {
//             swap(arr[piv], arr[i]);
//             piv = i;
//         }
//     }
//     return piv;
// }

// template <class T>
// void quickSort(T arr[], int l, int r)
// {
//     if (l < r)
//     {
//         int pivot = partition(arr, l, r);
//         quickSort(arr, l, pivot - 1);
//         quickSort(arr, pivot + 1, r);
//     }
// }

// void shellSort(vector<int> &arr)
// {
//     int n = arr.size();

//     // Start with a big gap, then reduce the gap
//     for (int gap = n / 2; gap > 0; gap /= 2)
//     {
//         // Do a gapped insertion sort for this gap size.
//         // The first gap elements arr[0..gap-1] are already in gapped order
//         // keep adding one more element until the entire array is gap sorted
//         for (int i = gap; i < n; i += 1)
//         {
//             // add arr[i] to the elements that have been gap sorted
//             // save arr[i] in temp and make a hole at position i
//             int temp = arr[i];

//             // shift earlier gap-sorted elements up until the correct location for arr[i] is found
//             int j;
//             for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
//                 arr[j] = arr[j - gap];

//             // put temp (the original arr[i]) in its correct location
//             arr[j] = temp;
//         }
//     }
// }