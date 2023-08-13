/*Spiral Order Matrix Traversal*/
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;

    /*Array input*/
    
    int arr[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin>>arr[i][j];
        
    }
    /*SPIRAL ORDER LOGIC*/
    int row_start = 0,row_end = n-1, column_start = 0, column_end = m-1;

    /*Tab tak chalna chaiye jab tak row ka start row ke end se kam ya equal just like column*/
    while(row_start<=row_end && column_start<=column_end)
    {
        /*For row_start*/
        for(int col=column_start;col<=column_end;col++)
        {
            cout<<arr[row_start][col]<<" ";
        }
        row_start++;

        /*For column_end i.e last column*/
        for(int row=row_start;row<=row_end;row++)
        {
            cout<<arr[row][column_end]<<" ";
        }
        column_end--;

        /*For row_end : ending row*/
        for(int col=column_end;col>=column_start;col--)
        {
            cout<<arr[row_end][col]<<" ";
        }
        row_end--;

        /*For colum_start : starting column*/
        for(int row =row_end;row>=row_start;row--)
        {
            cout<<arr[row] [column_start]<<" ";
        }
        column_start++;
    }
    return 0;
}

/*
5 6
1 5 7 9 10 11 
6 10 12 13 20 21
9 25 29 29 30 32 41
15 55 59 63 68 70
40 70 79 81 95 105

*/