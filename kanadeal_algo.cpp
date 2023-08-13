#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int currentSum = array[0]; // Initialize currentSum with the first element (-1)
    int maxSum = array[0]; // Initialize maxSum with the first element (-1)

    // Loop through the array starting from the second element (index 1)
    for (int i = 1; i < n; i++) {
        currentSum = max(array[i], currentSum + array[i]); // Update currentSum with the maximum of current element and (currentSum + current element)
        maxSum = max(maxSum, currentSum); // Update maxSum with the maximum of maxSum and currentSum
    }

    cout << maxSum << endl;
    return 0;
}
