#include <iostream>
using namespace std; 
class AreaFinder
{
    float l, b, h; 
    float result; 
    public:
    AreaFinder(float hh = 0, float ll = 0, float bb = 0) 
    {
        l = ll; 
        b = bb; 
        h = hh;
    }
    void Display(int ll)
    {
        if(l = 0)
            result = 3.14f * h * h; 
        else
            result = l * b; 
        cout<< result; 
    }
};
int main()
{
    AreaFinder objAF(10, 10, 20);
    objAF.Display(0); 
    return 0; 
}