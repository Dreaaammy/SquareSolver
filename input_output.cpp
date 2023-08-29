#include <Txlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "solve.h"
#include "input_output.h"
#include "equal_checking.h"

// Функция получает на вход количество корней,
// их значения и выводит в соответсвующем виде
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

// Функция выводит приветственный текст
void PrintHelloText()
{
    printf ("# Square equation solver\n"
            "# (C) Liapin Aleksey, 2017\n\n");
}

// Функция выводит текст,
// предлагающий ввести коэффиценты
void PrintRequestNumbersEnter()
{
    printf ("# Enter a, b, c: \n");
}

//
int InputCoeffs (double* a, double* b, double* c)
{
    printf ("Please enter three numbers:\n");
    int check = 0;
    while ((check = scanf ("%lf %lf %lf", a, b, c)) != 3 && check != EOF)
    {
        FlushBuffer ();
    }

    if (check == EOF) {
        printf("EOF reached\n");
        return 1;
    }

    return 0;
}

// Функция очищает буфер
void FlushBuffer()
{
    while (getchar() != '\n');
}

// Функция получает на вход коэффиценты уравнения, цвет,
// печатает его в математическом виде
void PrintEquation (const Color color, const double a, const double b, const double c)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);

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

    SetConsoleTextAttribute(hConsole, white);
}

// Функция получает цвет и текст,
// который выводит в соответсвующем цвете
void ColorPrinting (const Color color, const char text[])
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
    printf ("%s", text);
    SetConsoleTextAttribute(hConsole, white);
}

// Функция получает на вход цвет (color),
// перекрашивает весь следующий текст в этот цвет
void EnableColor (const Color color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Функция отменяет перекрашивание текста
void DisableColor ()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, white);
}
