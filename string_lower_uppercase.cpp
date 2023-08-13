// To convert a string in to its lower and uppercase
#include<bits/stdc++.h>
using namespace std;
int main() {
    string st1="abcde";
    transform(st1.begin(),st1.end(),st1.begin(),::toupper);
    cout<<st1<<endl;

    string st2="IJKLM";
    transform(st2.begin(),st2.end(),st2.begin(),::tolower);
    cout<<st2<<endl;
    return 0;
}
/*
ABCDE
ijklm
*/