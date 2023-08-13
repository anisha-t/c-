/*Rat In a Maze
Problem: Given a maze(2D matrix) with obstacles, starting from (0,0) you have to
reach (n-1, n-1). If you are currently on (x,y), you can move to right direction i.e(x+1,y) or down word i.e (x,y+1).
You can not move to the walls.*/

#include <iostream>
using namespace std;

/*Rat kaha ja sakta h na uske liywe check krna h ki maze me rat konse block me ja sakta h ya nahi*/

bool isSafe(int**arr,int x,int y,int n)//Dyanamically allocate kiya h//
{
    if(x<n && y<n && arr [x] [y]==1)//toh he rat vaha ja sakta h
    {
        return true;
    }
    return false;
}

/**/
bool ratinMaze(int**arr,int x,int y,int n,int**solnAarr)
{
    /*Base condition*/
    if(x==n-1 && y==n-1)
    {
        solnAarr [] =1;
        return true;
    }

    if(isSafe(arr,x,y,n))/*vo x aur y par ja sakte h ya nhi*/
    {
        solnAarr [x] [y] =1;
        /*recursive calling the function*/
        if(ratinMaze(arr,x+1, y, n,solnAarr))/*Right me jane se soln mil raha h ki nhi*/
    {
        return true;
    }
        if(ratinMaze(arr,x, y+1, n,solnAarr))/*down me jane se soln mil raha h ki nhi*/
    {
        return true;
    }
    /*Ab agar right aur down dono se nhi mil raha soln toh backtrack krna padega*/
     solnAarr [x] [y] = 0;/*Backtracking*/
    return false;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;

    int**arr=new int*[n];
    for(int i=0;i<n;i++)
    {
      arr[i]=new int [n];  
    }
    
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;i++) 
      {
        cin>>arr[i] [j];
      }
    }
    int**solnAarr=new int*[n];
    for(int i=0;i<n;i++)
    {
      solnAarr[i]=new int [n];  
      for(int j=0;j<n;i++) 
      {
        solnAarr[i] [j]=0;
      }
    }

    if(ratinMaze(arr,0,0,n,solnAarr))
    {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;i++) 
      {
        cout<< solnAarr[i] [j]<<" ";
      }cout<<endl;
    }

    }

    return 0;
}
/*input:
5 5
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1

Output:
1*/