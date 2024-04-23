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

template<typename Compare>
int partition(vector<Student>& arr, int low, int high, Compare comp) {
    Student pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
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
void quickSort(vector<Student>& arr, int low, int high, Compare comp) {
    if (low < high) {
        int part = partition(arr, low, high, comp);
        quickSort(arr, low, part - 1, comp);
        quickSort(arr, part + 1, high, comp);
    }
}

