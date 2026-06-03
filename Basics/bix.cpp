#include<iostream>
using namespace std; 
class IndiaBix
{
    int Num; 
    public:
    IndiaBix(int x)
    {
        Num = x;
    }
    int BixFunction(void);
};
int IndiaBix::BixFunction(void)
{
    static int Sum = 0; 
    int Dec;
    Dec = Num % 10; 
    Num = Num / 10; 
    if((Num / 100)) BixFunction(); 
    Sum  = Sum * 10 + Dec; 
    return Sum;
}
int main()
{
    IndiaBix objBix(12345);
    cout<< objBix.BixFunction();
    return 0; 
}