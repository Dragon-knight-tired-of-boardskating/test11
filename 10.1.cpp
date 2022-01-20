#include <stdio.h>
#include <iostream>
using namespace std;
class CommonDivisor
{
private:
    int x, y;
public:
    CommonDivisor(int xi = 1, int yi = 1) { x = xi; y = yi;}
    CommonDivisor(const CommonDivisor& b) { x = b.x; y = b.y; }
    ~CommonDivisor(){}
    int gcd(); int lcm();
    int min() { return x > y ? y : x; };
    int max() { return x > y ? x : y; }
    void set(int ix, int iy) { x = ix; y = iy; }
    void get(int& ix, int& iy)const { ix = x; iy = y; }
};
int CommonDivisor::gcd()
{
    int gcd=1;
    for (int i = min(); i >= 1; i--)
    {
        if (x % i == 0 && y % i == 0) { gcd = i; break; }
    }
    return gcd;
}
int CommonDivisor::lcm()
{
    int lcm = max();
    for (int i = lcm;; i += lcm)
    {
        if (i % min() == 0) { lcm = i; break; }
    }
    return lcm;
}
int main()
{
    CommonDivisor A;
    int a=0, b=0,test1=0,test2=0,gcd=0,lcm=0; 
    cin >> a >> b; cout << a << " " << b << endl;
    A.set(a, b);
    A.get(test1, test2);
    gcd = A.gcd(); lcm = A.lcm();
    std::cout << "test1 is " << test1 << "test2 is " << test2 << endl;
    std::cout << "gcd of A is" << gcd << "," << "lcm of A is " << lcm << endl;
}
