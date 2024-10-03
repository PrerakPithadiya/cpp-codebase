/**
 * @file quick_sort.cpp
 * @brief Implementation of the Quick Sort algorithm
 *
 * This file contains the implementation of the Quick Sort algorithm,
 * along with helper functions for swapping elements, partitioning the array,
 * and printing the array. It also includes a main function to demonstrate
 * the usage of the Quick Sort algorithm.
 */

#include <iostream>
using namespace std;

/**
 * @brief Swaps two integer values
 * @param a Reference to the first integer
 * @param b Reference to the second integer
 */
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Partitions the array and returns the pivot index
 * @param arr The array to be partitioned
 * @param low The starting index of the partition
 * @param high The ending index of the partition
 * @return The index of the pivot element after partitioning
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the rightmost element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;                  // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap elements
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot in its correct position
    return i + 1;                // Return the partitioning index
}

/**
 * @brief Implements the Quick Sort algorithm
 * @param arr The array to be sorted
 * @param low The starting index of the array or subarray
 * @param high The ending index of the array or subarray
 */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Get the partition index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * @brief Prints the elements of an array
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
 * @brief Main function to demonstrate the Quick Sort algorithm
 * @return 0 on successful execution
 */
int main()
{
    // Initialize the array to be sorted
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    cout << "Original array: ";
    printArray(arr, n);

    // Sort the array using Quick Sort
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

/**
 * Usage Instructions:
 * 1. Compile the program using a C++ compiler (e.g., g++ quick_sort.cpp -o quick_sort)
 * 2. Run the compiled executable (e.g., ./quick_sort)
 * 3. The program will display the original array and the sorted array
 *
 * To use the Quick Sort algorithm in your own code:
 * 1. Include the necessary functions (quickSort, partition, and swap) in your program
 * 2. Call the quickSort function with your array, starting index (0), and ending index (n-1)
 *    Example: quickSort(your_array, 0, array_size - 1);
 */
