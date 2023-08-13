// //Fibonaic series
// #include <iostream>
// using namespace std;
// int main(){
// int num,first=0,second=1,next;
// cin>>num;
// cout<<"Fibonaic series: "<<endl;

// for(int i =0;i<num;i++)
// {
//     cout<<first<<endl;
//     next=first+second;
//     first=second;
//     second=next;
// }
// return 0;
// }
// /*OUTPUT:
// 5
// Fibonaic series:
// 0
// 1
// 1
// 2
// 3*/

// Recursive method:
#include <iostream>
using namespace std;
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n=9;
    cout<<n<<" "<<fib(n);
}