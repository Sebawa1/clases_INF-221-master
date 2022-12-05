/**
 * @file:  testcases.h
 * @brief: Declarations for test cases for zero finding
 */

#ifndef TESTCASES_H
#define TESTCASES_H

struct test {
    double (*f)(double);
    double (*fprime)(double);
    double x0, x1;
    double zero;
};

extern struct test testcase[];
extern int n;
extern int fcalls;

#endif /* TESTCASES_H */
