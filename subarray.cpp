#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    int current = 0;
    for(int i =0;i<n;i++){
        current = 0;
        for(int j=i;j<n;j++){
            current += j;
            cout<<current<<endl;
        }
    }
}