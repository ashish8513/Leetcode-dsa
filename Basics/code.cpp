#include<iostream> 
using namespace std;
class Bix
{
    public:
      int x;
};
int main()
{
    Bix *p = new Bix();

    (*p).x = 10;
    cout<< (*p).x << " " << p->x << " " ;

    p->x = 20;
    cout<< (*p).x << " " << p->x ;

    return 0;
}