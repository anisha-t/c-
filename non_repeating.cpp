//Find the first non repeating char in a string
#include <iostream>
using namespace std;
int main()
{
    char str[100]="anisha";
    int i;
    int freq[256]={0};
    for(i=0;str[i]!='\0';i++)
    {
        freq[str[i]]++;

    }
    cout<<"The non repeating characters are:";
    for(i=0;i<256;i++)
    {
        if(freq[i]==1)
        {
            cout<<char(i)<<" ";
        }
    }
    return 0;
}
/*The non repeating characters are:h i n s*/