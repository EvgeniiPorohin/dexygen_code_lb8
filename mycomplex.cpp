/*!
   @file
   @brief Файл с описанием метода класса Complex
*/
#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;
/*!
   @brief Конструктор класса
   @param aRe действительная составляющая
   @param aIm мнимая составляющая
*/
Complex::Complex (double aRe, double aIm)
{
     Re = aRe;
     Im = aIm;
}
/*!
   @brief дружественый метод операции умножения
   @param aRval комплексное число
*/
Complex::Complex(const Complex& aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
}
/*!
   @brief деструктор класса
*/
Complex::~Complex()
{
    Re = 0.0;
    Im = 0.0;
}
/*!
   @brief установление мнимой и действительной состовляющих
*/
void Complex::Set (double aRe, double aIm)
{   Re = aRe;
    Im = aIm;
}
/*!
   @brief возврощает модуль комплекстного числа
   @return модуль комплуксное число
*/
Complex::operator double()
{
    return abs();
}
/*!
   @brief возвращает модуль выражения комплекстного числа
   @return модуль выражения комплуксное число
*/

    double Complex::abs()
{
    return sqrt (Re * Re + Im * Im);
}
/*!
   @brief возвращает результат сложения комплесного числа
   @return результат сложения комплексного числа
*/
Complex Complex::operator + (const Complex& aRval)
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}
/*!
   @brief возвращает результат вычитания комплесного числа
   @return результат сложения комплексного числа
*/
Complex Complex::operator - (const Complex& aRval)
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}
/*!
   @brief возвращает результат сложения действительного числа
   @return результат сложения комплексного числа
*/
Complex Complex::operator + (const double& aval)
{
    Complex result;
    result.Re = Re + aval;
    result.Im = Im;
    return result;
}
/*!
   @brief возвращает результат вычитания действительного числа
   @return результат
*/
Complex Complex::operator - (const double& aRval)
{
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}
/*!
   @brief возвращает результат умножения комплексного числа
   @return результат
*/
Complex Complex::operator * (const Complex& aRval)
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}
/*!
   @brief возвращает результат умножения действительного числа
   @return результат
*/
Complex Complex::operator * (const double& aRval)
{
   Complex Result;
   Result.Re = Re * aRval;
   Result.Im = Im * aRval;
   return Result;
}
/*!
   @brief возвращает результат деления действительного числа
   @return результат
*/
Complex Complex::operator / (const double& aRval)
{
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}
/*!
   @brief Ссылается на результат сложения комплексного числа
   @return возврат по значению
*/
Complex& Complex::operator += (const Complex&  arval)
{
  Re += arval.Re;
  Im += arval.Im;
  return *this;
}
/*!
   @brief Ссылается на результат вычитания комплексного числа
   @return возврат по значению
*/
Complex& Complex::operator -= (const Complex& aRval)
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}
/*!
   @brief Ссылается на результат умножения комплексного числа
   @return возврат по значению
*/
Complex& Complex::operator *= (const Complex& aRval)
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}
/*!
   @brief Ссылается на результат сложения действительного числа
   @return возврат по значению
*/
Complex& Complex::operator += (const double& aRval)
{
    Re += aRval;
    return *this;
}
/*!
   @brief Ссылается на результат вычитания действительного числа
   @return возврат по значению
*/
Complex& Complex::operator -= (const double& aRval)
{
    Re -= aRval;
    return *this;
}
/*!
   @brief Ссылается на результат умножения действительного числа
   @return возврат по значению
*/
Complex& Complex::operator *= (const double&  aRval)
{
    Re *= aRval;
    Im *= aRval;
    return * this;
}
/*!
   @brief Ссылается на результат деления действительного числа
   @return возврат по значению
*/
Complex& Complex::operator /= (const double& aRval)
{
    Re /= aRval;
    Im /= aRval;
    return *this;
}
/*!
   @brief Ссылается на результат равенства комплексного числа
   @return возврат по значению
*/
Complex& Complex::operator = (const Complex& aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}
/*!
   @brief Ссылается на результат равенства действительного числа
   @return возврат по значению
*/
Complex& Complex::operator = (const double& aRval)
{
    Re = aRval;
    Im = 0.0;
    return *this;
}
/*!
   @brief извлекает мнимую и действительную часть
   @return извлечение
*/
istream& operator >> (istream& stream, Complex& a)
{
   char tmp[256];
   stream >> a.Re >> a.Im >> tmp;
   return stream;
}
/*!
   @brief вставляет мнимую и действительную часть
   @return вставка
*/
ostream& operator << (ostream& stream, Complex& a)
{
   stream << a.Re;
   if( ! (a.Im < 0) ) stream << '+';
   stream << a.Im << 'i';
   return stream;
}
/*!
   @brief возвращает результат сложения действительного и комплексного числа
   @param aLval действительное число
   @return результат сложения
*/
Complex operator + (const double& aLval, const Complex& aRval)
{
   Complex Result;
   Result.Re = aLval + aRval.Re;
   Result.Im = aRval.Im;
   return Result;
}
/*!
   @brief возвращает результат вычитания действительного и комплексного числа
   @return вставка
*/
Complex operator - (const double& aLval, const Complex& aRval)
{
   Complex Result;
   Result.Re = aLval - aRval.Re;
   Result.Im = - aRval.Im;
   return Result;
}
/*!
   @brief возвращает результат умнажения действительного и комплексного числа
   @return вставка
*/
Complex operator * (const double& aLval, const Complex& a)
{
   Complex r;
   r.Re = aLval * a.Re;
   r.Im = aLval * a.Im;
   return r;
}
