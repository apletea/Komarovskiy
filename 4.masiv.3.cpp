#include <iostream>
#include <clocale>
//Вывести кол-во положительных и количество отрицательных элементов в массиве А.
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
   setlocale(LC_ALL,"Russian");
   int mas[N];
   int p=0,o=0;
    mas[0]=4;
   for (int i=1;i<N;i++)
   {
    mas[i]=xorshift128(mas[i-1]);
   }
   for (int i=N-1;i>=0;i--)
   {
    mas[i]=mas[i]%51;
    if (mas[i]>=0){p++;}
    else {o++;}
   }
   cout<<"Кол-во положительных элементов:="<<p<<endl;
   cout<<"Кол-во отрицательных элемteтов:="<<o<<endl;

    return 0;
}
