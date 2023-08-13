#include<iostream>
using namespace std;
class Shape{
public:
virtual void draw()
{
    cout<<"Drawing generic shape"<<endl;   
}
};
class Circle : public  Shape {
    public:
    void draw ()override
    {
        cout<<"Drawing circle"<<endl;
    }
};
int main()
{
    Shape *shapePtr=new Circle();
    shapePtr->draw();
    delete shapePtr;
    return 0;
}