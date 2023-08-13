#include<iostream>
#include<climits>
using namespace std;
/*kadane function is use for nonwrapping element*/
int kadane(int array[],int n)
{
    int currentSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentSum+=array[i];
        if (currentSum<0)
        {
            currentSum=0;
        }
        maxSum = max(maxSum,currentSum);
    }
    return maxSum;
}

int main(){
    int n;
    cin>>n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    int wrapsum;
    int nonwrapsum;/*That is not in use for sum*/

    nonwrapsum=kadane(array,n);
    /*to getwrapsum*/
    int totalsum=0;
    for (int i = 0; i < n; i++)
    {
        totalsum+=array[i];/*Total sum of all the elements
                             of the array*/
        array[i]=-array[i];/*Here we reverse the sign*/
    }

    wrapsum = totalsum +kadane(array,n);/*idar reverse vala
                                         array use kiya h*/
    cout<<max(wrapsum,nonwrapsum);
    return 0;
} 