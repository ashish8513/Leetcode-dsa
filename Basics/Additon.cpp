#include<iostream>
using namespace std; 
class Addition
{
    int x; 
    public: 
    Addition()
    {
        x = 0;
    }       
    Addition(int xx)
    {
        x = xx;
    }
    Addition operator + (int xx = 0)
    {
        Addition objTemp; 
        objTemp.x = x + xx; 
        return(objTemp);
    }
    void Display(void)
    {
        cout<< x << endl;
    }
};
int main()
{
    Addition objA(15), objB;
    objB = objA + 5;
    objB.Display();
    return 0; 
}