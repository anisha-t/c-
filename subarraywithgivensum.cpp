// find subarray which adds to given number S 
//ex N=5,S=12,A[]= {1,2,3,7,5}
// ans = 2 4 (index)
#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;

    int a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int i=0, j=0, st=-1, en=-1, sum=0;//start and end will store final  ans
                                    //sum variable will store the sum of i and j

    while(j<n && sum+a[j]<=s)//sum aur a[j] ka addition should be less or equal to s
    {

        sum += a[j];//sum me add kardiya h
        j++;
    }

    if (sum==s)// st aur end milgaya h toh 
    {
        cout<<i+1<<" "<<j<<endl;//i+1 is due to 1 index
        return 0;
    }

    while (j<n){
        sum +=a[j];

        while(sum>s)
        {
            sum -= a[i];//sum mese - kardo a[i]
            i++;
        }
        if (sum==s)
        {
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en<<endl;
    return 0;
}
/*OUTPUT
5 12
1 2 3 7 5
2 4
*/