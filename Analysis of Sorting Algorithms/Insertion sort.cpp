#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void runAndTime(int original[], int size, const char* name) {
    int arr[100];
    for (int i = 0; i < size; i++) arr[i] = original[i];

    auto start = high_resolution_clock::now();
    insertionSort(arr, size);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    cout << name << ": " << duration << " microseconds\n";
}

int main() {
    int arr1[] = {5,4,3,2,1};
    int arr2[] = {10,9,8,7,6,5,4,3,2,1};
    int arr3[50], arr4[100];
    for (int i = 0; i < 50; i++) arr3[i] = 50 - i;
    for (int i = 0; i < 100; i++) arr4[i] = 100 - i;

    cout << "Insertion Sort\n";
    runAndTime(arr1, 5, "Arr1");
    runAndTime(arr2, 10, "Arr2");
    runAndTime(arr3, 50, "Arr3");
    runAndTime(arr4, 100, "Arr4");
    return 0;
}

