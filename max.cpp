#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int max_no =INT_MIN;
    int n;
    cin>>n;
    int array[n];
    for(int i =0;i<n;i++){
        cin>>array[i];
    }
    for(int i=0;i<n;i++)
    {
        max_no = max(max_no,array[i]);
        cout<<max_no<<" ";
    }

    return 0;

}