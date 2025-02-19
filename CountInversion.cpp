#include <iostream>
using namespace std;

// Merge function to merge two sorted halves and count inversions
int CountandMerge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[m + 1 + j];
    }

    int res = 0, i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
            res += (n1 - i); // Count inversions
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    return res;
}

// Merge Sort function to count inversions
int countInv(int arr[], int l, int r) {
    int res = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
        res += CountandMerge(arr, l, m, r);
    }
    return res;
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

    int inversions = countInv(arr, 0, n - 1);  // Count and sort

    cout << "Sorted array: ";
    printArray(arr, n);  // Print the sorted array

    cout << "Number of inversions: " << inversions << endl;

    return 0;
}
