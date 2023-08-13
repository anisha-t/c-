//Write a program to reverse a string
#include <iostream>
#include<string.h>
using namespace std;
int main()
{
    char str[]="Anisha";
    cout<<"Orignal String:"<<str;

    cout<<endl<<"Reverse String:";
    for(int i=(strlen(str)-1);i>=0;i--)//strlen(str)-1=n-1=last se jabtak i=0 nhi ta -- karo ie ulta karo
    
        cout<<str[i];
    
    
    return 0;

}

