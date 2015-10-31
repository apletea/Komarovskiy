#include <iostream>
//Вывести значения сначала элементов с нечетными коэффициентами (1-й, 3-й, 5-й,...) а затем - с четными.
using std::cin;
using std::cout;
using std::endl;


int xorshift128(int x)
 {
    int t;
    int a=21,b=34,c=4;
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
   }
   for (int i=1;i<N;i+=2)
   {
       cout<<mas[i]<<endl;
   }
   for (int i=0;i<N;i+=2)
   {
       cout<<mas[i]<<endl;
   }
    return 0;
}
