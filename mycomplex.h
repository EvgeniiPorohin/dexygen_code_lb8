/*
   @file
   @brief Заголовочный файл класса Complex
*/
#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;
/*!
   @brief Заголовочный файл класса Complex
*/
class Complex
{
/*!
   @brief действительная состовляющая
*/
    double Re;
/*!
   @brief мнимая состовляющая
*/
	double Im;
/*!
   @brief список членов класса
*/
	public:
        Complex(double aRe = 0, double aIm = 0);
        Complex(const Complex&);
        ~Complex();
/*!
   @brief установление мнимой и действительной состовляющих
*/
        void Set(double aRe, double aIm = 0);
        operator double();
/*!
   @brief модуль комплекстного числа
*/
        double abs();
/*!
   @brief дружественный класс операции перегрузки ввода >>
*/
        friend istream& operator >> (istream&, Complex&);
/*!
   @brief дружественный класс операции перегрузки вывода <<
*/
        friend ostream& operator << (ostream&, Complex&);
/*!
   @brief операции для мнимой и действительной части
*/
        Complex operator * (const Complex&);
        Complex operator * (const double&);
        Complex operator / (const double&);
        Complex operator - (const double&);
        Complex operator + (const Complex&);
        Complex operator - (const Complex&);
        Complex operator + (const double&);
/*!
   @brief дружественый метод операции сложения
*/
        friend Complex operator + (const double&, const Complex&);
/*!
   @brief дружественый метод операции вычитания
*/
        friend Complex operator - (const double&, const Complex&);
/*!
   @brief дружественый метод операции умножения
*/
        friend Complex operator * (const double&, const Complex&);
/*!
   @brief перезагрузка операций для действительного и комплекстного числа
*/
        Complex& operator += (const Complex&);
        Complex& operator -= (const Complex&);
        Complex& operator *= (const Complex&);
        Complex& operator += (const double&);
        Complex& operator -= (const double&);
        Complex& operator *= (const double&);
        Complex& operator /= (const double&);
        Complex& operator = (const Complex&);
        Complex& operator = (const double&);
};
#endif
