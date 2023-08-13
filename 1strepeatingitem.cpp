/* find 1st repeating item in array i.e item that occurs more than once 
and whose index of first occurrence is smallest.
ex- 7 
1 5 3 4 3 5 6 here 5 and 3 are repeating but 5 has smallest index 
indexing start from 1 not 0
*/
#include<iostream>
#include<climits>
using namespace std;
int main(){

    int n;
    cin>>n;

    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }

const int N = 1e6 + 2;  //10 rise to 6 according to constraint
int idx[N]; //  array that stores the index of repeating element

for (int i=0; i<N; i++){
    idx[i] = -1; //intialize by -1
}

int minidx = INT_MAX; //touse INT_MAX we have to get header file climits
// minidx variable stores the index of output

for (int i=0; i<n; i++){ // input array is checked here

    if (idx[a[i]] != -1){ //not equal to -1 i.e no element is repeating
    //so update minidx with that element's index  

        minidx = min(minidx, idx[a[i]]);//updating 
    }
    else{
        idx[a[i]] == i; //print index

    }}
    if (minidx == INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<< minidx + 1 <<endl;
    }
    return 0;
}




