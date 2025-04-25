#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[minIdx], arr[i]);
    }
}

void runAndTime(int original[], int size, const char* name) {
    int arr[100];
    for (int i = 0; i < size; i++) arr[i] = original[i];

    auto start = high_resolution_clock::now();
    selectionSort(arr, size);
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

    cout << "Selection Sort\n";
    runAndTime(arr1, 5, "Arr1");
    runAndTime(arr2, 10, "Arr2");
    runAndTime(arr3, 50, "Arr3");
    runAndTime(arr4, 100, "Arr4");
    return 0;
}

