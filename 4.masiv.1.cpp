#include <iostream>
//Вывести значения в "обратном порядке" (начиная от последнего элемента и заканчивая первым).
using std::cin;
using std::cout;
using std::endl;


int xorshift128(int x)
 {
    int t;
    int a=13,b=15,c=5;
    t = x ^ (x << a);
    t = t ^ (t >> b);

    return x = x ^ (t << c);
}

int main()
{  const int N=22563;
   int mas[N];
    mas[0]=4;
   for (int i=1;i<N;i++)
   {
    mas[i]=xorshift128(mas[i-1]);
   }
   for (int i=N-1;i>=0;i--)
   {
    mas[i]=mas[i]%51;
    cout<<mas[i]<<endl;
   }
    return 0;
}
