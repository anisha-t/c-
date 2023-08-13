//We are given two sorted arrays. We need to merge these two arrays such that the initial numbers
//(after complete sorting) are in the first array and the remaining numbers are in the second array
//Time Complexity: O(M * N)
//Auxiliary Space: O(1)
#include<iostream>
using namespace std;
void merge(int arr1[],int arr2[],int m,int n)//arr1,arr2,size of arr1,size of arr2
{
    //Iterate through all elements
    // of ar2[] starting from the last element

for(int i=n-1;i>=0;i)
{
    // Find the smallest element greater than ar2[i].
        // Move all elements one position ahead till the
        // smallest greater element is not found */
    int j,last=arr2[m-1];
    for(j=m-2;j>=0;j--)
    {
        arr1[j+1]=arr2[i];
 // If there was a greater element
        if(last>arr2[i])
        arr1[j+1]=arr2[i];
        arr2[i]=last;
    }
}
}
  
// Driver code
int main()
{
    int ar1[] = { 1, 5, 9, 10, 15, 20 };
    int ar2[] = { 2, 3, 8, 13 };
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    merge(ar1, ar2, m, n);
  
    cout << "After Merging \nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << ar1[i] << " ";
    cout << "\nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << ar2[i] << " ";
    return 0;
}