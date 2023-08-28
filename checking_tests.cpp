#include <Txlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <assert.h>

#include "solve.h"
#include "checking_tests.h"
#include "equal_checking.h"
#include "constants.h"
#include "input_output.h"

void RunOneTest (const TestData ref)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    short unsigned int greenColour = 10;
    short unsigned int redColour   = 12;
    short unsigned int whiteColour = 7;

    double x1 = 0, x2 = 0;
    SolveSquare(ref.a, ref.b, ref.c, &x1, &x2);

    if ((IsEqual(x1, ref.x1) && IsEqual(x2, ref.x2)) ||
        (IsEqual(x2, ref.x1) && IsEqual(x1, ref.x2)))
    {
        SetConsoleTextAttribute(hConsole, greenColour);
        printf ("TEST CORRECT\n");
        SetConsoleTextAttribute(hConsole, whiteColour);
    }
    else
    {
        SetConsoleTextAttribute(hConsole,  redColour);
        printf ("TEST FAILED:\n"
                "\tEquation:\n\t\t");

        PrintEquation(ref.a, ref.b, ref.c);

        printf("\t\tExpected:\n"
                "\t\tx1 = %lg, x2 = %lg\n"
                "\t\tGot:\n"
                "\t\tx1 = %lg, x2 = %lg\n\n",
                ref.x1, ref.x2, x1, x2);
        SetConsoleTextAttribute(hConsole, whiteColour);
    }

}

void RunAllTests()
{
    FILE *allTestsFile = fopen("Tests.txt", "r");
    assert (allTestsFile != NULL);

    int testsNumber = 0;
    fscanf (allTestsFile, "%d", &testsNumber);

    TestData test = {};


    for (int i = 0; i < testsNumber; i++)
    {
        fscanf (allTestsFile, "%lg %lg %lg %lg %lg %d",
                &test.a, &test.b, &test.c, &test.x1, &test.x2, &test.nRoots);

        RunOneTest (test);
    }

}
