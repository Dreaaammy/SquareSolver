#include <Txlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "solve.h"
#include "input_output.h"
#include "checking_tests.h"

int main(int argc, char* argv[])
{
    PrintHelloText ();

    if (argc > 1 && strcmp(argv[1], "--test") == 0)
    {
        RunAllTests ();
    }
    else
    {
        PrintRequestNumbersEnter();
        double a = NAN, b = NAN, c = NAN;
        InputCoeffs (&a, &b, &c);

        double x1 = NAN, x2 = NAN;
        int nRoots = SolveSquare (a, b, c, &x1, &x2);
        OutputAnswerText (nRoots, x1, x2);
    }

    return 0;  
}
