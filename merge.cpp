#include <iostream>
using namespace std;

// Merge function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;     // Size of right subarray

    // Temporary arrays to hold the split parts
    int leftArr[n1], rightArr[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merging the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find the middle point
        mergeSort(arr, left, mid);  // Recursively sort the first half
        mergeSort(arr, mid + 1, right);  // Recursively sort the second half
        merge(arr, left, mid, right);  // Merge the two sorted halves
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    
    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);  // Call mergeSort to sort the array

    cout << "Sorted array: ";
    printArray(arr, n);  // Print the sorted array

    return 0;
}
