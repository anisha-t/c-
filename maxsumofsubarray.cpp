//Find the Maximum Sum Subarray Array//

#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int array[n];
    
    for (int i = 0;i<n;i++)
    {
        cin>>array[i];
    }
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {   int sum =0;
            for (int k = i; k <= j; k++)
            {
               sum +=array[k];
            }
            maxSum = max(maxSum,sum);
        }
    }
    cout<<maxSum<<endl;
    return 0;
}
/*OUTPUT:
4
-1 4 7 2
13
*/

/*Time Complexity: O(N3)*/