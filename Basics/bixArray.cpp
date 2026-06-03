#include <iostream> 
using namespace std;
class BixArray
{
    int Matrix[3][3]; 
    public:
    BixArray()
    {
        for(int i = 0; i<3; i++)
           for(int j = 0; j < 3; j++) 
              Matrix[j][i] = i + j; 
    }
    void Display(void)
    {
        for(int i = 0; i < 3; i++)
           for(int j = 0; j < 3; j++) 
              cout<< Matrix[j][i] << " "; 
    } 
}; 
int main()
{
    BixArray objBix;
    objBix.Display();
    return 0; 
}