#include <Txlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solve.h"
#include "equal_checking.h"

// Функция получает коэффиценты квадратного уравнения,
// решает его, находя корни и выводит их количество
int SolveSquare (const double a, const double b, const double c, double* x1, double* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (IsZero(a))
    {
        return SolveLinear (b, c, x1);
    }
    else
    {
        double const discriminant = b * b - 4 * a * c;
        if (IsZero(discriminant))
        {
            *x1 = *x2 = -b / (2 * a);
            return ONE_ROOT;
        }
        else if (discriminant > 0)
        {
            assert (discriminant > 0);

            double sqrt_discrim = sqrt(discriminant);
            *x1 = (-b + sqrt_discrim) / (2 * a);
            *x2 = (-b - sqrt_discrim) / (2 * a);
            return TWO_ROOTS;
        }
        else
        {
            assert (discriminant < 0);
            return IMG_ROOTS;
        }
    }
}

// Функция, получая коэффиценты, решает линейное уравнение,
// находит его корни, выводит их количество
int SolveLinear (double b, double c, double* x1)
{
    if (IsZero(b))
    {
        return IsZero(c) ? INF_ROOTS : ZERO_ROOTS;
    }
    else
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }
}


