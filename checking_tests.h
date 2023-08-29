#ifndef CHECKING_TESTS_H
#define CHECKING_TESTS_H  // header guard

struct TestData
{
    double a, b, c;
    double x1, x2;
    int nRoots;
};

void RunOneTest     (const TestData ref);
void RunAllTests    ();

#endif  //CHECKING_TESTS_H
