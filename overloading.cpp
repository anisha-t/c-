#include<iostream>
using namespace std;
class MathsOverload{
public:
int sum(int a,int b)
{
    return a+b;
}
double sum(double f1, double f2){
    return f1+f2;
}
};
int main()
{
    MathsOverload maths;
    cout<<maths.sum(2,3)<<endl;
    cout<<maths.sum(2.8,3.8)<<endl;
    return 0;
}
/*
5
6.6
*/