#include <iostream>
#include <vector>
#include <utility> // For std::swap

// Rearranges the array elements around a pivot
int partition(std::vector<int>& arr, int low, int high) {
    // Choose the rightmost element as the pivot
    int pivot = arr[high]; 
    
    // Index of the smaller element
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of the smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    
    // Place the pivot in its correct sorted position
    std::swap(arr[i + 1], arr[high]);
    
    // Return the partitioning index
    return i + 1;
}

// The main function that implements Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    // Base case: If low is less than high
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper function to print the vector
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {9, 4, 8, 3, 7, 1, 6, 2, 5};
    
    std::cout << "Unsorted array: ";
    printArray(data);

    // Call quickSort on the entire vector
    quickSort(data, 0, data.size() - 1);

    std::cout << "Sorted array:   ";
    printArray(data);

    return 0;
}
