#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();

    int array[n+1];
    cin>>array;

    cin.getline(array,n);
    cin.ignore();

    int i=0;
    int current_len =0,max_len=0;
    int st = 0,max_st=0;

    while(1)
    {
        if (array[i]==''|| array[i]=='\0')
        {
            if (current_len>max_len)
            {
                max_len=current_len;
                max_st=st;
            }
            current_len=0;
            st =i+1;
        }
        else
        {
            current_len++;

        }
        if(array[i]=='\0')
        {
            break;
        }
        i++
        
    }

    cout<<max_len<<endl;
    for(int i =0;i<max_len;i++)
    {
        cout<<array[i+max_st];
    }

    return 0;
}