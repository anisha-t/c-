//Swapping 3 variables without using 4th variable
// #include<iostream>
//  using namespace std;
// void swapthree(int a,int b,int c)
// {
//     a= a+b+c;
//     b=a-(b+c);
//     c=a-(b+c);
//     a=a-(b+c);
// }
// int main()
// {
//     int x=1,y=2,z=3;
//     cout<<"Before swaping the variables: x: "<<x<<",y: "<<y<<",z:"<<z<<endl;
//     swapthree(x,y,z);
//     cout<<"After swapping three variables  x: "<<x<<",y: "<<y<<",z:"<<z;
//     return 0;
// }
/*
Before swaping the variables: x: 1,y: 2,z:3
After swapping three variables  x: 1,y: 2,z:3
*/

#include<iostream>
using namespace std;
void swaptwo(int a,int b)
{
    a=a+b;
    b=a-b;
    a=a-b;

}
int main()
{
    int x =5 , y=7 ;
    cout<<"Before swaping the variables: x: "<<x<<",y: "<<y<<endl;
    swaptwo(x,y);
    cout<<"After swapping three variables  x: "<<x<<",y: "<<y;
    return 0;
}
/*
Before swaping the variables: x: 5,y: 7
After swapping three variables  x: 5,y: 7
*/