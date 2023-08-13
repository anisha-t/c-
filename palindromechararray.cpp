/*To check the given word is palindrome or not?
Palindrome is the word that we reverse remainthe sa,me as before
Example: NITIN if we reverse it will be the same */
#include<iostream>
using namespace std;
int main()
{
    /*Taking the input*/
    int n;
    cin >>n;
    char array[n+1];
    cin>> array;

    /*checking the word is palindrom*/
    bool check = 1
    ;
    for (int i = 0; i < n; i++)
    {
        if(array[i]!=array[n-1-i])
        {
            check=0;
            break;
        }
    }
    
    if(check==true)
    {
        cout<<"word is palindrome"<<endl;
    }

    else
    {
        cout<<"word is not palindrome";
    }
    

    return 0;
}