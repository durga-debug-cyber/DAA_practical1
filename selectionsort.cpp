#include <iostream>
#include <utility> // For std::swap

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    // Loop through the entire array except the last element
    for (int i = 0; i < n - 1; i++) {
        // Assume the current position holds the minimum value
        int min_idx = i;
        
        // Test remaining elements to find the actual minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[arr[min_idx]]) {
                min_idx = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

// Function to print the array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Original array: ";
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    std::cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}
