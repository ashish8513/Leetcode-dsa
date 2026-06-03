#include<iostream>
using namespace std; 
class IndiaBix
{
    public:
    IndiaBix()
    {
        cout<< "India";
    }
    ~IndiaBix()
    {
        cout<< "Bix";
    }
};
int main()
{
    IndiaBix objBix;
    return 0; 
}