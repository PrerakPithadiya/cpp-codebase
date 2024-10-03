#include <iostream>
using namespace std;

/**
 * @file selection_sort.cpp
 * @brief Implementation of the Selection Sort algorithm
 *
 * This file contains the implementation of the Selection Sort algorithm,
 * along with helper functions to print arrays and a main function to
 * demonstrate the sorting process.
 */

/**
 * @brief Performs the Selection Sort algorithm on an array
 *
 * This function sorts an array in ascending order using the Selection Sort algorithm.
 * It iterates through the array, finding the minimum element in the unsorted portion
 * and swapping it with the first unsorted element.
 *
 * @param arr The array to be sorted
 * @param n The number of elements in the array
 */
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Assume the first unsorted element is the minimum
        int minIndex = i;

        // Find the index of the minimum element in the unsorted portion
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j; // Update the index of the minimum element
            }
        }

        // Swap the found minimum element with the first unsorted element
        swap(arr[i], arr[minIndex]);
    }
}

/**
 * @brief Prints the elements of an array
 *
 * This function prints all elements of an array to the console,
 * separated by spaces and followed by a newline.
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
 * @brief Main function to demonstrate the Selection Sort algorithm
 *
 * This function creates a sample array, prints the original array,
 * sorts it using the Selection Sort algorithm, and then prints the sorted array.
 *
 * @return 0 on successful execution
 */
int main()
{
    // Sample array to be sorted
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Perform Selection Sort
    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

/**
 * @note Usage Instructions:
 * 1. Compile the program using a C++ compiler (e.g., g++ selection_sort.cpp -o selection_sort)
 * 2. Run the compiled executable (e.g., ./selection_sort)
 * 3. The program will display the original array, sort it, and then display the sorted array
 *
 * @note Design and Implementation:
 * - The program uses the Selection Sort algorithm, which has a time complexity of O(n^2)
 * - The sorting is performed in-place, meaning no additional arrays are created
 * - The code is modular, with separate functions for sorting, printing, and the main logic
 * - Error handling for invalid inputs is not implemented in this version
 */
