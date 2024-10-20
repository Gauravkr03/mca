#include <iostream>

void deleteElement(int arr[], int &n, int index) {
    if (index >= 0 && index < n) {
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; // decrease the size of the array
    } else {
        std::cout << "Not a valid position!" << std::endl;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index;

    std::cout << "Original array: ";
    printArray(arr, n);

    std::cout << "Enter the position of the element to delete: ";
    std::cin >> index;

    deleteElement(arr, n, index);

    if (index >= 0 && index < n + 1) {
        std::cout << "Array after deletion: ";
        printArray(arr, n);
    }

    return 0;
}


// case 10:
//                 insertionSort(arr, n);
//                 break;
