#include <iostream>
#include <clocale>
#include <math.h>
#include <stdlib.h>


using std::cout;
using std::cin;
using std::endl;


void initialize (int mas[], int N)
{
	for (int i=0;i<N;i++)
	{
	cin>>mas[i];
	}
}

void ink (int &k)
{
	cin>>k;
}

void poisk (int mas[], int N, int k)
{int q=-2;
	while (q==-2)
	{
	 	for (int i=0;i<N;i++)
	 	{
	 	if (mas[i]==k){q=k;}
	 	if ((i==N-1) && (q<0))q=-1;
		}
	}
	cout<<q;

}

	int main ()
{	

	setlocale (LC_ALL,"Russian");
	const int N=10;
	int mas[N];
	int k;
	initialize (mas,N);
	ink(k);
	poisk (mas,N,k);



}

