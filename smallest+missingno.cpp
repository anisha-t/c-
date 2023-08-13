/* Ex - 0 -9 1 3 -4 5
here 2 is smallest + missing no. ignore negative nos  


*/
#include<iostream>
using namespace std;
int main(){

int n;
cin>>n;

int a[n];
for ( int i=0; i<n; i++){
    cin>>a[i];
}

const int N = 1e6;
bool check[N];
for (int i = 0; i < N; i++)
{
    check[i]=false;//0
}
for (int i = 0; i < n; i++)
{
    if(a[i]>=0)//positive numbers
    {
        check[a[i]]=true;//1
    }
}
// now checking our check array which index is false or missing
int ans = -1;
for (int i = 0; i < N; i++)
{
    if (check[i]==false)
    {
        ans = i;
        break;
    }
    
}
cout<<ans<<endl;
return 0;
}



