#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

typedef enum {
            red = 12, green = 10,
            blue = 9, white = 7
            } Color;

void ColorPrinting              (const Color color, const char text[]);
void PrintEquation              (const Color color, const double a, const double b, const double c);
void OutputAnswerText           (int nRoots, const double x1, const double x2);
int  InputCoeffs                (double* a, double* b, double* c);
void EnableColor                (const Color color);
void DisableColor               ();
void PrintHelloText             ();
void FlushBuffer                ();
void PrintRequestNumbersEnter   ();

#endif // INPUT_OUTPUT_H
