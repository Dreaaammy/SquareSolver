#include <Txlib.h>
#include <stdio.h>
#include <math.h>

#include "equal_checking.h"

// Функция получает на вход два числа типа double,
// проверяет их на равенство
bool IsEqual(const double num1, const double num2)
{
    return fabs(num1 - num2) <= ((fabs(num1) > fabs(num2) ? fabs(num2) : fabs(num1)) * EPS);
}

// Функция сравнивает число с 0,
// ипользуя функцию IsEqual()
bool IsZero(const double num)
{
    return IsEqual(num, 0);
}
