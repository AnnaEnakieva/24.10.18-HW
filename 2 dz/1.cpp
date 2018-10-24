# 24.10.18-HW
//*Реализуйте структуру Rational для работы с рациональными числами, как с несократимыми дробями.
В программе должно присутствовать описание структуры и программа показывающая работоспособность структуры.
Комментарий 1. Структура должна уметь работать с арифметикой и сравнениями. 
С помощью структуры должна быть возможность создавать пользовательские функции. 
Комментарий 2. Программа должна содержать использование ВСЕХ методов. 
На примере рациональных чисел посмотрите когда именно вызываются методы. 
Для этого добавьте отладочную печать работающую при их использовании. Например, “Copying Constructor is working”. //*

#include "stdafx.h"

 

#include <math.h>

#include <iostream>

#include <string>

#include <numeric>

 

using namespace std;

 

/* Standard C Function: Greatest Common Divisor */

int

gcd(int a, int b)

{

       int c;

       while (a != 0) {

              c = a; a = b % a;  b = c;

       }

       return b;

}

 

 

struct rational

{

       int m;

       int n;

 

       // internal function for reduction

       void reduce()

       {

              int d = gcd(m, n);

              m /= d;

              n /= d;

       }

 

       // m defines the fraction's sign

       void fix_sign()

       {

              // check the sign

              if (m < 0 && n < 0) {

                     m = -m;

                     n = -n;

              }

              // m defines fraction's sign

              else if (n < 0)

              {

                     m = -m;

                     n = -n;

              }

       }

 

       rational(int a, int b)

       {

              m = a;

              n = b;

              // check the sign

              fix_sign();

              reduce();

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

 

       rational operator+(rational& A)

       {

              m = m * A.n + A.m * n;

              n *= A.n;

              reduce();

              return *this;

       }

 

       rational operator-(rational& A)

       {

              m = m * A.n - A.m * n;

              n *= A.n;

              reduce();

              return *this;

       }

 

       rational operator/(rational& A)

       {

              m *= A.n;

              n *= A.m;

              fix_sign();

              reduce();

              return *this;

       }

 

       rational operator*(rational& A)

       {

              m *= A.m;

              n *= A.n;

              reduce();

              return *this;

       }

 

       rational & operator*=(int &a)

       {

              m *= a;

              reduce();

              return *this;

       }

 

       rational & operator *=(rational & A)

       {

              m *= A.m;

              n *= A.n;

              reduce();

              return *this;

       }

 

       bool operator==(rational & A )

       {

              return ((m == A.m) && (n == A.n));

       }

 

       bool operator!=(rational const & A)

       {

              return ((m != A.m) || (n != A.n));

       }

 

       bool operator<(rational const & A)

       {

              return ((m * A.n) < (A.m * n));

       }

 

       bool operator >(rational const & A)

       {

              return ((m * A.n) > (A.m * n));

       }

 

       bool operator <=(rational const & A)

       {

              return ((m * A.n) <= (A.m * n));

       }

       bool operator >=(rational const & A)

       {

              return ((m * A.n) >= (A.m * n));

       }

 

};

 

 

std::ostream& operator<< (std::ostream& stream, const rational& A)

{

       stream << A.m << "/" << A.n;

       return stream;

}

 

int main() {

       int argh1,argh2,argh3, argh4;

       cin >> argh1 >> argh2 >> argh3 >>argh4;

       cout << "\n";

 

       rational A(argh1, argh2), B(argh3, argh4);

       cout << "A = " << A << "\n" << "B = " << B << "\n";

       cout << "\n";

 

       cout << "A + B = " << A + B << "\n";

       cout << "A - B = " << A - B << "\n";

       cout << "A * B = " << A * B << "\n";

       cout << "A / B = " << A / B << "\n";

       cout << "\n";

 

 

       if (A==B)

       {

              cout << A << " == " << B << "\n";

       };

 

       if (A!=B)

       {

              cout << A << " != " << B << "\n";

       };

 

       if (A > B)

       {

              cout << A << " > " << B << "\n";

       };

 

       if (A >= B)

       {

              cout << A << " >= " << B << "\n";

       };

 

       if (A < B)

       {

              cout << A << " < " << B << "\n";

       };

 

       if (A <= B)

       {

              cout << A << " <= " << B << "\n";

       };

 

       return 0;

}  
