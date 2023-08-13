/*How to convert a string in to its upper and lower case*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{   
    string str="abcdefghijklmnopqrstuvwxyz";

/*For UPPER case*/

/*for (int i = 0; i < count; i++)
{
    if (str[i]>="a" && str[i]<="z")
    {
        str[i]-=32;
    }
    
}cout<<str<<endl;*/

/*For Lower case*/

/*for (int i = 0; i < count; i++)
{
    if (str[i]>="A" && str[i]<="Z")
    {
        str[i]+=32;
    }
    
}cout<<str<<endl;
*/

/*For UPPER case*/
transform(str.begin(),str.end(),str.begin(),toupper);
cout<<str<<endl;

/*For Lower case*/

transform(str.begin(),str.end(),str.begin(),toupper);
cout<<str<<endl;

    return 0;
}