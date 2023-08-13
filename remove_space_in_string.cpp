//Remove a space from a string
#include<iostream>
using namespace std;
void removespace(char *str)
{
    // To keep track of non-space character count
    int count =0;
     // Traverse the given string. If current character is not space, then place it at index 'count++'
for(int i=0;str[i];i++)

    if(str[i]!=' ')
    str[count++]=str[i];
    str[count]='\0';


}
int main()
{
    char str[] ="H e l l o W o r l d ";
    removespace(str);
    cout << str;
    return 0;
}
/*HelloWorld*/