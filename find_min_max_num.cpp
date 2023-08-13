//Find maximum and minimum element in an array
//TIME COMPLEXITY:O(n)
#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    int min_no = INT_MAX;
    int max_no = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (array[i]>max_no)
        {
            max_no=array[i];
            
        }
        
        if (array[i]<min_no)
        {
            min_no=array[i];
        }


    }
    cout<<"Maximum no is :"<<max_no<<endl;
    cout<<"Minimum no is :"<<min_no<<endl;
    return 0;
}
/*
7
1 2 33 100 5 6 55
Maximum no is :100
Minimum no is :1
*/