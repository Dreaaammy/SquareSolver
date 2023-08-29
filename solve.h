#ifndef SOLVE_H
#define SOLVE_H

enum roots {
            INF_ROOTS = -1, IMG_ROOTS = 3, ZERO_ROOTS = 0,
            TWO_ROOTS = 2, ONE_ROOT = 1
            };

int SolveSquare         (const double a, const double b, const double c, double* x1, double* x2);
int SolveLinear         (double b, double c, double* x1);

#endif // SOLVE_H
