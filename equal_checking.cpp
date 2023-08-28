#include <Txlib.h>
#include <stdio.h>
#include <math.h>

#include "constants.h"
#include "equal_checking.h"

bool IsEqual(const double num1, const double num2)
{
    return fabs(num1 - num2) < EPS;
}

bool IsZero(const double num)
{
    return IsEqual(num, 0);
}
