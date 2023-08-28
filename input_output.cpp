#include <Txlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "solve.h"
#include "input_output.h"
#include "constants.h"
#include "equal_checking.h"

void OutputAnswerText (int nRoots, const double x1, const double x2)
{
    switch (nRoots)
    {
        case ZERO_ROOTS:
            printf ("No roots\n");
            break;

        case ONE_ROOT:
            printf ("x1 = %lg\n", x1);
            break;

        case TWO_ROOTS:
            printf ("x1 = %lg, x2 = %lg\n", x1, x2);
            break;

        case IMG_ROOTS:
            printf ("Roots are imaginary numbers\n");
            break;

        case INF_ROOTS:
            printf ("Any number\n");
            break;

        default:
            printf ("ERROR: nRoots = %d\n", nRoots);
            break;
    }
}

void PrintHelloText()
{
    printf ("# Square equation solver\n"
            "# (C) Liapin Aleksey, 2017\n\n");
}

void PrintRequestNumbersEnter()
{
    printf ("# Enter a, b, c: \n");
}

void InputCoeffs (double* a, double* b, double* c)
{
    while (scanf ("%lf %lf %lf", a, b, c) != 3)
    {
        printf ("Please enter three numbers:\n");
        FlushBuffer ();
        return;
    }
    printf("Try again");
    InputCoeffs(a, b, c);
    return;
}

void FlushBuffer()
{
    int check = 0;
    while ((check = getchar()) != '\n' && check != EOF);
}

void PrintEquation (const double a, const double b, const double c)
{
    if      (IsEqual(a,  1)) printf("x^2 ");
    else if (IsEqual(a, -1)) printf("-x^2 ");
    else if (!IsZero(a))     printf("%.3lgx^2 ", a);

    if (!IsZero(b))
    {
        if      (IsEqual(b,  1)) printf("+ ");
        else if (IsEqual(b, -1)) printf("- ");
        else if (b < 0)          printf("- %.3lg", fabs(b));
        else                     printf("+ %.3lg", fabs(b));
        printf("x ");
    }

    if (c < 0)  printf("- %.3lg = 0\n", fabs(c));
    else        printf("+ %.3lg = 0\n", fabs(c));
}

