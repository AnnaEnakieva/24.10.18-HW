# 24.10.18-HW
//*Реализуйте структуру Rational для работы с рациональными числами, как с несократимыми дробями.
В программе должно присутствовать описание структуры и программа показывающая работоспособность структуры.
Комментарий 1. Структура должна уметь работать с арифметикой и сравнениями. 
С помощью структуры должна быть возможность создавать пользовательские функции. 
Комментарий 2. Программа должна содержать использование ВСЕХ методов. 
На примере рациональных чисел посмотрите когда именно вызываются методы. 
Для этого добавьте отладочную печать работающую при их использовании. Например, “Copying Constructor is working”. *//


#include "math.h"
#include <iostream>
#include <string>
struct rational {
int m;
int n;
rational(int a, int b)
{
m = a / gcd(a, b);
n = b / gcd(a, b);
}
rational(int a)
{
m = a;
n = 1;
}
rational(const rational & A)
{
m = A.m;
n = A.n;
}
rational operator= (rational & A)
{
m = A.m;
n = A.n;
return *this;
}
rational & operator *=(rational & A)
{
m *= A.m;
n *= A.n;
int d = gcd(m, n);
m /= d;
n /= d;
return *this;
}
rational & operator*=(int &a)
{
return (*this) *= int(rational(a));
}
rational operator *(rational A, rational & B)
{
return A *= B;
}
bool operator ==(rational & A, rational B)
{
return ((A.m == B.m) && (A.n == B.n);
}

bool operator !=(rational const & A, rational const & B)
{
return !( A == B);
}
bool operator <(rational const & A, rational const & B)
{
return A<B;
}
bool operator >((rational const & A, rational const & B)
{
return B < A;
}

bool operator <=(rational const & A, rational const & B)
{
return !(A > B);
}
bool operator >=(rational const & A, rational const & B)
{
return !(A < B);
}
}

 

 

#include <iostream>


struct rational
{
int A;
int B;
rational();
rational(int A, int B = 1);
rational(const rational& r);
~rational();

rational& operator = (const rational& r);

rational& operator += (const rational& r);
rational& operator -= (const rational& r);
rational& operator *= (const rational& r);
rational& operator /= (const rational& r);

};
int main()
{
rational operator * (rational& n, rational& m);
rational operator - (rational& n, rational& m);
rational operator + (rational& n, rational& m);
rational operator / (rational& n, rational& m);

const bool operator < (const rational& n, const rational& m);
const bool operator == (const rational& n, const rational& m);
const bool operator <= (const rational& n, const rational& m);
const bool operator > (const rational& n, const rational& m);
const bool operator >= (const rational& n, const rational& m);
const bool operator != (const rational& n, const rational& m);
}

