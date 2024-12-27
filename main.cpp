#include "Matrix.h"
#include <iostream>
using namespace std;

int main() {
    size_t n = 3;
    Matrix<double> m1(n), m2(n);

    cout << "Enter elements for matrix 1:\n";
    cin >> m1;

    cout << "Enter elements for matrix 2:\n";
    cin >> m2;

    cout << "Matrix 1:\n" << m1 << endl;
    cout << "Matrix 2:\n" << m2 << endl;

    Matrix<double> m3 = m1 + m2;
    cout << "Matrix 1 + Matrix 2:\n" << m3 << endl;

    Matrix<double> m4 = m1 - m2;
    cout << "Matrix 1 - Matrix 2:\n" << m4 << endl;

    Matrix<double> m5 = m1 * m2;
    cout << "Matrix 1 * Matrix 2:\n" << m5 << endl;

    m1.Normalize();
    cout << "Normalized Matrix 1:\n" << m1 << endl;

    return 0;
}
