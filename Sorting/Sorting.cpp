#include <iostream>
#include <vector>
#include "../StudentClass/Student.h"
using namespace std;

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
//Selection Sort
template <class T>
int selectionSort(T arr[], int n)
{
   int comparisons = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++; 
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
        }
    }
    return comparisons;
}
int selectionSortForstudent(Student arr[], int n,bool compareByName = false)
{
    if(!compareByName){
        int comparisons = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                comparisons++;
                if (arr[j].getGPA() < arr[minIndex].getGPA())
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                std::swap(arr[i], arr[minIndex]);
            }
        }
        return comparisons;
    }else{
        int comparisons = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                comparisons++;
                if (arr[j].getName() < arr[minIndex].getName())
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                std::swap(arr[i], arr[minIndex]);
            }
        }
        return comparisons;

    }

}
//bubble sort
template <class T>
int bubbleSort(T arr[], int n)
{
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++; 
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    return comparisons;
}
int bubbleSortForStudent(Student arr[], int n,bool compareByName = false)
{
    if(!compareByName){
        int comparisons = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                comparisons++;
                if (arr[j].getGPA() > arr[j + 1].getGPA())
                {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
        return comparisons;
    }else{
        int comparisons = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                comparisons++;
                if (arr[j].getName() > arr[j + 1].getName())
                {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
        return comparisons;

    }

}

// Quick sort
template<typename T>
int partiton(vector<T>& Array, int low, int high){
    T pivot=Array[low];
    int i=low,j=high;
    do
    {
        do{i++;} while (Array[i]<=pivot);

        do{j--;} while (pivot<Array[j]);
        if(i<j){
            swap(Array[i],Array[j]);
        }

    } while (i<j);
    swap(Array[low],Array[j]);
    return j;


}
template<typename T>
void QuickSort(vector<T>& Array, int low, int high){
    int j;
    if(low<high){
        j= partiton(Array,low,high);
        QuickSort(Array,low,j);
        QuickSort(Array,j+1,high);
    }

}
bool compareByGPA(const Student& a, const Student& b) {
    return a.getGPA() < b.getGPA();
}
bool compareByName(const Student& a, const Student& b) {
    return a.getName() < b.getName();
}

int CompNoForQuickSort = 0;
template<typename Compare>
int partition(Student arr[], int low, int high, Compare comp) {
    Student pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        CompNoForQuickSort++;
        if (comp(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
// Quick sort for student class
template<typename Compare>
int quickSort(Student arr[], int low, int high, Compare comp) {
    CompNoForQuickSort++;
    if (low < high) {
        int part = partition(arr, low, high, comp);
        quickSort(arr, low, part - 1, comp);
        quickSort(arr, part + 1, high, comp);
    }
    return CompNoForQuickSort;
}
template<class T>
int merge(T A[], int l, int mid, int h)
{
    int compNumber = 0;
    int i = l, j = mid + 1, k = l;
    T B[h + 1];

    while (i <= mid && j <= h)
    {
        compNumber++;
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];

    for (; j <= h; j++)
        B[k++] = A[j];

    for (int i = l; i <= h; i++)
        A[i] = B[i];

    return compNumber;
}

template<class T>
int mergeSort(T A[], int n)
{
    int compNumber = 0;
    int l, mid, h;
    int i, p;
    for (p = 2; p <= n; p *= 2)
    {
        for (i = 0; i + p - 1 < n; i += p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;

            compNumber += merge(A, l, mid, h);
        }
    }
    if (p / 2 < n)
        compNumber += merge(A, 0, p / 2 - 1, n - 1);

    return compNumber;
}


int mergeForStudents(Student A[], int l, int mid, int h, bool compareByName = false)
{
    int count = 0;
    int i = l, j = mid + 1, k = l;
    Student B[h + 1];

    while (i <= mid && j <= h)
    {
        count++;
        if (compareByName) {
            if (studentNameComparer(A[i], A[j]))
                B[k++] = A[i++];
            else
                B[k++] = A[j++];
        } else {
            if (studentGPAComparer(A[i], A[j]))
                B[k++] = A[i++];
            else
                B[k++] = A[j++];
        }
    }

    for (; i <= mid; i++)
        B[k++] = A[i];

    for (; j <= h; j++)
        B[k++] = A[j];

    for (int i = l; i <= h; i++)
        A[i] = B[i];

    return count;
}


int mergeSortForStudents(Student arr[], int n, bool compareByName = false)
{
    int count = 0;
    int l, mid, h;
    int i, p;
    for (p = 2; p <= n; p *= 2)
    {
        for (i = 0; i + p - 1 < n; i += p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;

            count += mergeForStudents(arr, l, mid, h, compareByName);
        }
    }
    if (p / 2 < n)
        count += mergeForStudents(arr, 0, p / 2 - 1, n - 1, compareByName);

    return count;
}

