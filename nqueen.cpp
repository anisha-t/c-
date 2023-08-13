/*Nqueen using backtracking and recursion*/
#include<iostream>
using namespace std;

/*The isSafe function is used to check if it is safe to place a queen at position (x, y) on the chessboard. 
It checks if there is any queen present in the same column or on the diagonals of the current position.*/

bool isSafe(int** arr, int x, int y, int n)
{
    // Check whether the queen is already present in the column
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
            return false;
    }
    
    // Check whether the queen is diagonally placed or not
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col--;
    }
    
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col++;
    }
   
    return true;
}

/*The nqueen function is a recursive function that uses backtracking to find a solution to the N-Queens problem.
It starts with the first row (x = 0) and tries to place a queen in each column of that row. 
If it finds a safe position, it marks it as 1 in the arr array and recursively calls itself for the next row (x + 1). 
If all the queens can be placed successfully, it returns true. 
Otherwise, it backtracks by setting the current position to 0 and tries the next column.*/

bool nqueen(int** arr, int x, int n)
{
    if (x >= n) {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;

            if (nqueen(arr, x + 1, n)) {
                return true;
            }

            arr[x][col] = 0;
        }
    }

    return false;
}

// The main function, it takes the input value of N from the user and dynamically creates a 2D array arr of size NxN. 
// Initially, all elements of the array are set to 0.
// It calls the nqueen function with the initial row (0) and the size of the chessboard (n).
// If a solution is found (i.e., nqueen returns true), it prints the arrangement of queens by iterating over the arr array.

int main()
{
    int n;
    cin >> n;
    
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    
    if (nqueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

/*Output
4 
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 
*/