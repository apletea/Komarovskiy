//реализация алгаритма в качестве отдельной функции
#include <iostream>

using namespace std;



int xorshift128(int x) {
    int t;
    int a=21,b=34,c=4;
    t = x ^ (x << a);
    t = t ^ (t >> b);

    return x = x ^ (t << c);
}
 int main()
 {
     return 0;
 }
