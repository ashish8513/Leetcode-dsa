#include<iostream> 
using namespace std;
class IndiaBix
{
    int x; 
    float y; 
    public:
    void Function()
    {
        x = 4; 
        y = 2.50; delete this;
    }
    void Display()
    {
        cout<< x << " " << y;
    } 
}; 
int main()
{
    IndiaBix *pBix = new IndiaBix();
    pBix->Function(); 
    pBix->Function(); 
    pBix->Display(); 
    return 0; 
} 