#include <iostream>
#include <fstream>
#include <clocale>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct Drob{
    int chislitel;
    int znaminatel;
};

int nodq(int a, int b) {
    int nod = 1L;
    int tmp;
    if (a == 0L)
        return b;
    if (b == 0L)
        return a;
    if (a == b)
        return a;
    if (a == 1L || b == 1L)
        return 1L;
    while (a != 0 && b != 0) {
        if (((a & 1L) | (b & 1L)) == 0L) {
            nod <<= 1L;
            a >>= 1L;
            b >>= 1L;
            continue;
        }
        if (((a & 1L) == 0L) && (b & 1L)) {
            a >>= 1L;
            continue;
        }
        if ((a & 1L) && ((b & 1L) == 0L)) {
            b >>= 1L;
            continue;
        }
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        tmp = a;
        a = (b - a) >> 1L;
        b = tmp;
    }
    if (a == 0)
        return nod * b;
    else
        return nod * a;
}

void sokr(Drob &b){
    int nod = nodq(b.chislitel, b.znaminatel);
    b.chislitel/=nod;
    b.znaminatel/=nod;
}
Drob pp(Drob a1, Drob a2)
{
     Drob a3;
     a3.chislitel = a1.chislitel*a2.znaminatel+a1.znaminatel*a2.chislitel;
     a3.znaminatel = a1.znaminatel*a2.znaminatel;
     return a3;
}
Drob mm(Drob a1, Drob a2)
{
    Drob a3;
    a3.chislitel = a1.chislitel*a2.znaminatel-a1.znaminatel*a2.chislitel;
    a3.znaminatel = a1.znaminatel*a2.znaminatel;
    return a3;
}
Drob multiplied(Drob a1, Drob a2)
{
    Drob a3;
    a3.chislitel = a1.chislitel*a2.chislitel;
    a3.znaminatel = a1.znaminatel*a2.znaminatel;
    return a3;
}
Drob qutioent(Drob a1, Drob a2)
{
    Drob a3;
    a3.chislitel = a1.chislitel*a2.znaminatel;
    a3.znaminatel = a1.znaminatel*a2.chislitel;
    return a3;
}
//программа складывающая дроби
int main()
{
    setlocale(LC_ALL,"Russia");
    Drob a1,a2,a3;
    cout << "Введите числитель и знаменатель,через пробел, первой дроби, а потом второй дроби"<<endl;
    cin >> a1.chislitel>>a1.znaminatel>>a2.chislitel>>a2.znaminatel;
    cout << "Введите операцию которую хотите сделать над дробями"<<endl;
    char op;
    cin >> op;

    switch (op)
        {
        case '+':
            {
                a3 = pp(a1,a2);
                break;
            }
        case '-':
            {
                a3=mm(a1,a2);
                break;
            }
        case '*':
            {
                a3=multiplied(a1,a2);
                break;
            }
        case '/':
            {
                a3=qutioent(a1,a2);
                break;
            }
        default:cout << "Введите операцию заново" << endl;
        break;
        }
        sokr(a3);
        if (a3.znaminatel == 1){cout << a3.chislitel;}
        else{
        cout << a3.chislitel<< "/" <<a3.znaminatel;}


    return 0;
}
