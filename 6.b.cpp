#include <iostream>
#include <clocale>
#include <math.h>
#include <stdlib.h>



using std::cout;
using std::cin;
using std::endl;

void initialize (int mas[], int n)//инитиализация массива
{   cout<<"введите десять целых чисел"<<endl;
	for (int i=0;i<n;i++)
	{
	cin>>mas[i];
	}
}

void couuut (int mas[], int n) // вывод массива
{
	for (int i=0;i<n;i++)
	{
	cout<<mas[i]<<"  ";
	}
	cout<<""<<endl;//зачем печатать пустой строку ""???? 
}
//-------------------------------------------------------------------------------------------------------
// начиная отсюда вообще какой-то бред.... 
// я ничего не понял. Зачем функция, которая просто вводит число!!!
void vvod (int & N)//ввод числа
{   cout<<"какой элемент массива удалить?"<<endl;
    cin>>N;
}
void udalenie (int A[], int & n, int N)//удаление числа
{
    for (int i=N-1;i<n;i++)
    {
        A[i]=A[i+1];
    }
    n--;// что такое n. Для чего оно????
}

// В программе объявлен массив А целых элементов (размер массива 10). Пользователь вводит массив c клавиатуры. Потом
//распечатываем массив. Вводим число N < 10. Затем удаляем N-ый элемент массива (сдвигая остальные элементы).
int main()
{   int n=10;
    int A[n];
    int N;
    initialize(A,n);//инитиализация
    couuut(A,n);//распечатываем массив
    vvod(N);//ввод числа
    udalenie (A,n,N);//удаление
    couuut(A,n);//распечатываем массив

    return 0;
}
