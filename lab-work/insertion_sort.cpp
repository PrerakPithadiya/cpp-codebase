/**
 * @file insertion_sort.cpp
 * @brief Implementation of Insertion Sort algorithm with demonstration
 *
 * This file contains the implementation of the Insertion Sort algorithm,
 * along with helper functions and a main function to demonstrate its usage.
 */

#include <iostream>
using namespace std;

/**
 * @brief Performs insertion sort on an array
 *
 * This function implements the Insertion Sort algorithm to sort an array
 * in ascending order.
 *
 * @param arr The array to be sorted
 * @param n The number of elements in the array
 */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // The element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insert the key at the correct position
    }
}

/**
 * @brief Prints the elements of an array
 *
 * This function prints all elements of an array to the console,
 * separated by spaces.
 *
 * @param arr The array to be printed
 * @param n The number of elements in the array
 */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Main function to demonstrate insertion sort
 *
 * This function creates a sample array, prints it, sorts it using
 * the insertion sort algorithm, and then prints the sorted array.
 *
 * @return 0 on successful execution
 */
int main()
{
    // Sample array for demonstration
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Perform insertion sort
    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

/**
 * Usage Instructions:
 * 1. Compile the program using a C++ compiler (e.g., g++ insertion_sort.cpp -o insertion_sort)
 * 2. Run the compiled executable (e.g., ./insertion_sort)
 * 3. The program will display the original array and the sorted array
 *
 * To use the insertion sort function in your own code:
 * 1. Include this file or copy the insertionSort function
 * 2. Call insertionSort(your_array, array_size) to sort your array
 */
