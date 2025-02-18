#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void isort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // The element to be inserted into the sorted portion
        int j = i - 1;     // Index to compare the sorted part of the array

        // Move elements of arr[0..i-1] that are greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element to the right
            j--;  // Move to the previous element
        }

        // Place the key at its correct position
        arr[j + 1] = key;  // Insert the key into the sorted portion
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    
    cout << "Original array: ";
    printArray(arr, n);

    isort(arr, n);  // Sort the array using Insertion Sort

    cout << "Sorted array: ";
    printArray(arr, n);  // Print the sorted array

    return 0;
}
