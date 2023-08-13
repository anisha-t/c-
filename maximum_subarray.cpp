#include <iostream>
using namespace std;

int maxSubarrayProduct(int arr[], int n) {
    int maxEndingHere = arr[0];
    int minEndingHere = arr[0];
    int maxProduct = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0)
            swap(maxEndingHere, minEndingHere);

        maxEndingHere = max(arr[i], maxEndingHere * arr[i]);
        minEndingHere = min(arr[i], minEndingHere * arr[i]);

        maxProduct = max(maxProduct, maxEndingHere);
    }

    return maxProduct;
}

int main() {
    int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Subarray product is " << maxSubarrayProduct(arr, n);
    return 0;
}

