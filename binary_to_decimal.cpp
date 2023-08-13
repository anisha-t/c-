//to convert binary to decimal: lastdigit*(2^base)
#include <iostream>
using namespace std;
int binaryToDecimal(int n)
{
    int num=n;
    int dec_value=0;
    int base=1;
    int temp=num;
    while(temp)
    {
        int lastdigit=temp%10;
        temp=temp/10;
        dec_value+=lastdigit*base;
        base=base*2;

    }
    return dec_value;
}
int main()
{
    int num=10101001;
    cout<<"Binary number is "<<binaryToDecimal(num)<<endl;
    return 0;
}
/*
Binary number is 169
*/