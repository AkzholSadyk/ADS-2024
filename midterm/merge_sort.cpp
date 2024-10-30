#include <iostream>
#include <climits> 

using namespace std;

void merge(int* arr, int beg, int mid, int end) {
    int* left = new int[mid - beg + 2];
    int* right = new int[end - mid + 1];

    left[mid - beg + 1] = INT_MAX;
    right[end - mid] = INT_MAX;

    for (int i = 0; i < mid - beg + 1; i++) {
        left[i] = arr[beg + i];
    }

    for (int i = 0; i < end - mid; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = beg;

    while (k <= end) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int* arr, int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

int main() {
    int arr[7] = {7, 6, 5, 4, 3, 2, 1};

    mergeSort(arr, 0, 6);

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
