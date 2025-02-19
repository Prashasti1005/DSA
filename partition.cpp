#include <iostream>
using namespace std;

// Partition function for QuickSort
int partition(int arr[], int l, int h) {
    int pivot = arr[h]; // Pivot is the last element
    int temp[h - l + 1], index = 0;

    // Store elements <= pivot
    for (int i = l; i < h; i++) {
        if (arr[i] <= pivot) {
            temp[index] = arr[i];
            index++;
        }
    }

    // Place pivot in the correct position
    int pivotIndex = index;
    temp[index] = pivot;
    index++;

    // Store elements > pivot
    for (int i = l; i < h; i++) {
        if (arr[i] > pivot) {
            temp[index] = arr[i];
            index++;
        }
    }

    // Copy back to original array
    for (int i = l; i <= h; i++) {
        arr[i] = temp[i - l];
    }

    return l + pivotIndex; // Return the pivot's final position
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << "Original array: ";
    printArray(arr, n);

    int pivotIndex = partition(arr, 0, n - 1); // Partition using last element as pivot

    cout << "Array after partition: ";
    printArray(arr, n); // Print the array after partitioning

    cout << "Pivot is now at index: " << pivotIndex << endl;

    return 0;
}
