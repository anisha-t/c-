/*Matrix Multiplication*/
#include<iostream>
using namespace std;

void multiplyMatrices()
{
int n1,n2,n3;
cin >> n1 >> n2 >> n3;
/*M1 matrix ka n1 row aur n2 col*/
int m1[n1][n2]; 

/*M2 matrix ka n2 row aur n3 col*/
int m2[n2][n3]; 

/*ANS matrix ka n1 row aur n3 col*/
int ans[n1][n3];

//for loop for m1 matrix input//
for(int i=0; i<n1; i++) {
for(int j=0; j<n2; j++)
cin >> m1[i][j];
}

//for loop for m2 matrix input//
for(int i=0; i<n2; i++) {
for(int j=0; j<n3; j++)
cin >> m2[i][j];
}

//for loop for ans matrix input//
for(int i=0; i<n1; i++) {
for(int j=0; j<n3; j++)
ans[i][j] = 0;//initally 0 h//
}

//multiplication of n1 and n3
for(int i=0; i<n1; i++) {
for(int j=0; j<n3; j++)
{
for(int k=0; k<n2; k++) {
ans[i][j] += m1[i][k]*m2[k][j];
}
}
}
//output for loop
for(int i=0; i<n1; i++) {
for(int j=0; j<n3; j++)
cout << ans[i][j] <<" ";
cout << endl;
}
}
/*OUTPUT:
3 4 3
2 4 1 2
8 4 3 6
1 7 9 5
1 2 3
4 5 6
7 8 9
4 5 6

33 42 51 
69 90 111 
112 134 156 
*/