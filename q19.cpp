#include <iostream>
#include <cmath>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = max + 1;
    int count[range] = {0};
    int output[n];

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void bucketSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int bucketCount = maxVal / 10 + 1;
    int* buckets = new int[bucketCount];
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / 10;
        buckets[bucketIndex]++;
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (buckets[i] > 0) {
            for (int j = 0; j < n; j++) {
                if (arr[j] / 10 == i) {
                    arr[index++] = arr[j];
                }
            }
        }
    }
    delete[] buckets;
}

void radixSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        int output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, n;

    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Heap Sort\n";
        cout << "2. Counting Sort\n";
        cout << "3. Bucket Sort\n";
        cout << "4. Radix Sort\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                heapSort(arr, n);
                cout << "Array after Heap Sort: ";
                displayArray(arr, n);
                break;

            case 2:
                countingSort(arr, n);
                cout << "Array after Counting Sort: ";
                displayArray(arr, n);
                break;

            case 3:
                bucketSort(arr, n);
                cout << "Array after Bucket Sort: ";
                displayArray(arr, n);
                break;

            case 4:
                radixSort(arr, n);
                cout << "Array after Radix Sort: ";
                displayArray(arr, n);
                break;

            case 5:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
