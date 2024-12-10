#include "Matrix.h"

int main() {
    size_t n = 3;
    Matrix<int> m1(n), m2(n);

    cout << "Enter elements for matrix 1:\n";
    cin >> m1;

    cout << "Enter elements for matrix 2:\n";
    cin >> m2;

    cout << "Matrix 1:\n" << m1 << endl;
    cout << "Matrix 2:\n" << m2 << endl;

    Matrix<int> m3 = m1 + m2;
    cout << "Matrix 1 + Matrix 2:\n" << m3 << endl;

    Matrix<int> m4 = m1 - m2;
    cout << "Matrix 1 - Matrix 2:\n" << m4 << endl;

    Matrix<int> m5 = m1 * m2;
    cout << "Matrix 1 * Matrix 2:\n" << m5 << endl;

    return 0;
}
