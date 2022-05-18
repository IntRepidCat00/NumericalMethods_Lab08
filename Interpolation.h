#ifndef LAB08_INTERPOLATION_H
#define LAB08_INTERPOLATION_H
#include <iostream>
#include <cmath>

class Interpolation
{
private:
    double X[10]{0.01, 0.06, 0.11, 0.16, 0.21, 0.26, 0.31, 0.36, 0.41, 0.46};
    double Y[10]{0.99, 0.95, 0.91, 0.88, 0.84, 0.81, 0.78, 0.74, 0.71, 0.68};
    int size{10};

    double x0{0.22};
public:
    void enterData();
    void printTable();
    double divDiff(int n0, int n);
    void LagrangePoly();
    void NewtonPoly();
};


#endif //LAB08_INTERPOLATION_H
