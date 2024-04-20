# data-structures
## 1. Sorting Algorithms:
Assuming that you have a class, Student:
1. Implement the student class with its constructor.
2. Overload the operator < such that it compares the names
of two student objects.
3. Read student objects from a file named students.txt, which will have
the number of students followed by their information as follows:
4. Implement Insertion Sort, Selection Sort, Bubble Sort, Shell Sort,
Merge Sort, Quick Sort and Count Sort algorithms.
  a. Each algorithm should be a separate function implemented using
  templates to allow sorting of different types of data.

5. Sort the array of students’ objects with each of the previous algorithms.
  a. Sort the data one time by Name and another time by GPA.
6. Calculate the running time of each algorithm for each array.

7. The output will be two files, SortedByGPA.txt and SortedByName.txt. Each file
contains:
  a. Algorithm name.
  b. Number of comparisons.
  c. Running Time.
  d. Sorted Student Elements.


## 2. Linear Structures:
Implement the following data structures and demonstrates how to use them in the main
function.
### • Implement a Single Linked List, Double Linked List and Circular Linked List
with the following methods:
  o insertAtHead (elementType element) : void
  o insertAtTail (elementType element) : void
  o insertAt (elementType element, int index) : void
  o removeAtHead () : void
  o removeAtTail () : void
  o removeAt (int index) : void
  o retrieveAt (int index): elementType
  o replaceAt (elementType newElement, int index)
  o isExist (elementType element) : bool
  o isItemAtEqual (elementType element, int index) : bool
  o swap (int firstItemIdx, int secondItemIdx) : void // swap two nodes without swapping
  data.
  o isEmpty () : bool
  o linkedListSize () : int
  o clear (): void
  o print () : void
### • Implement a Stack with the following methods:
  o push (elementType element) : void
  o pop () : elementType element //return the first element and remove it.
  o top () : elementType element //return the first element without removing it.
  o isEmpty () : bool
  o stackSize () : int
  o clear (): void
  o print () : void
  • Implement a Queue with the following methods:
  o enqueue (elementType element) : void
  o dequeue () : elementType element //return the first element and remove it.
  o first () : elementType element //return the first element without removing it.
  o isEmpty () : bool
  o queueSize () : int
  o clear (): void
  o print () : void
