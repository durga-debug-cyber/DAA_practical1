#include <iostream>
#include <utility> 

void selectionSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {
        
        int min_idx = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[arr[min_idx]]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

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
