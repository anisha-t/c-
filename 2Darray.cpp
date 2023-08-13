/*INPUT and OUPUT in an 2D array*/
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr [n] [m];//n is row and m is column//

    for (int i = 0; i < n; i++)//which array we are including //
    {
        for (int j = 0; j < m; j++)//with this we include the element//
        {
            cin>>arr[i] [j];
        }
        
    }
    cout<<"Matrix is :"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";//output of matrix
        }
        cout<<"\n";
    }

/*Searching an element x in an array*/
int x;
cin>>x;
bool falg =false;
for(int i =0;i<n;i++)
{
    for(int j = 0;j<m;j++)
    {
        if(arr [i][j]==x)
        {
            cout<<i<<" "<<j<<endl;
            flag = true;
        }
    }
    if(falg)
    {
        cout<<"Element is found"<<endl;

    }
    else
    {
        cout<<"Element is not found";
    }
    
}
}
