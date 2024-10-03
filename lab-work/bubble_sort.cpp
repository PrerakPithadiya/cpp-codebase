/**
 * @file bubble_sort.cpp
 * @brief Implementation of the Bubble Sort algorithm with optimizations.
 *
 * This file contains the implementation of the Bubble Sort algorithm,
 * along with helper functions and a demonstration in the main function.
 * The algorithm is optimized with a flag to detect if the array is already sorted.
 *
 * @author [Prerak Pithadiya]
 * @date [3 October 2024]
 */

#include <iostream>
using namespace std;

/**
 * @brief Performs the Bubble Sort algorithm on an array.
 *
 * This function sorts an array in ascending order using the Bubble Sort algorithm.
 * It includes an optimization to break early if the array is already sorted.
 *
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 *
 * @note Time Complexity: O(n^2) in worst and average cases, O(n) in best case.
 * @note Space Complexity: O(1) as it sorts in-place.
 */
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false; // Flag to check if a swap occurred

        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                swap(arr[j], arr[j + 1]);
                swapped = true; // A swap occurred
            }
        }

        // If no two elements were swapped in the inner loop, the array is sorted
        if (!swapped)
        {
            break;
        }
    }
}

/**
 * @brief Prints the elements of an array.
 *
 * This function prints all elements of an array to the console,
 * separated by spaces and followed by a newline.
 *
 * @param arr The array to be printed.
 * @param n The number of elements in the array.
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
 * @brief Main function to demonstrate the Bubble Sort algorithm.
 *
 * This function creates a sample array, prints it, sorts it using
 * the Bubble Sort algorithm, and then prints the sorted array.
 *
 * @return 0 on successful execution.
 */
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

/**
 * @note Usage Instructions:
 * 1. Compile the program using a C++ compiler (e.g., g++ bubble_sort.cpp -o bubble_sort).
 * 2. Run the compiled executable (e.g., ./bubble_sort).
 * 3. The program will display the original array and the sorted array.
 *
 * @note To use the bubbleSort function in your own code:
 * 1. Include this file or copy the bubbleSort function.
 * 2. Call bubbleSort(your_array, array_size) where your_array is the array to be sorted
 *    and array_size is the number of elements in the array.
 */
