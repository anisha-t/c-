#include <iostream>
#include <algorithm>
using namespace std;
int kthSmallest(int arr[], int size, int k) {
    // First, sort the array in ascending order
    sort(arr, arr + size);

    // The kth smallest element will be at index (k - 1) in the sorted array
    return arr[k - 1];
}

int main() {
    int arr[] = {7, 2, 9, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int kthSmallestElement = kthSmallest(arr, size, k);
    cout << "The " << k << "th smallest element is: " << kthSmallestElement << std::endl;

    return 0;
}