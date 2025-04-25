#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void runAndTime(int original[], int size, const char* name) {
    int arr[100];
    for (int i = 0; i < size; i++) arr[i] = original[i];

    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
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

    cout << "Merge Sort\n";
    runAndTime(arr1, 5, "Arr1");
    runAndTime(arr2, 10, "Arr2");
    runAndTime(arr3, 50, "Arr3");
    runAndTime(arr4, 100, "Arr4");
    return 0;
}

