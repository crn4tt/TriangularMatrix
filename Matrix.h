#pragma once
#include "Vector.h"
#include <stdexcept>
using namespace std;

template <class T>
class Matrix : public Vector<Vector<T>> {
public:
    Matrix(size_t n)
        : Vector<Vector<T>>(n, 0) {
        for (size_t i = 0; i < n; i++) {
            this->_array[i] = Vector<T>(n - i, i);
        }
    }

    Matrix(const Matrix& mt) : Vector<Vector<T>>(mt) {}

    Matrix(const Vector<Vector<T>>& mt) : Vector<Vector<T>>(mt) {}

    Matrix& operator=(const Matrix& mt) {
        if (this != &mt) {
            Vector<Vector<T>>::operator=(mt);
        }
        return *this;
    }

    Matrix operator+(const Matrix& mt) {
        if (this->_size != mt._size) {
            throw std::invalid_argument("Matrices must be of the same size for addition.");
        }

        Matrix result(this->_size);
        for (size_t i = 0; i < this->_size; i++) {
            for (size_t j = 0; j < this->_array[i].GetSize(); j++) {
                result._array[i][j] = this->_array[i][j] + mt._array[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& mt) {
        if (this->_size != mt._size) {
            throw std::invalid_argument("Matrices must be of the same size for subtraction.");
        }

        Matrix result(this->_size);
        for (size_t i = 0; i < this->_size; i++) {
            for (size_t j = 0; j < this->_array[i].GetSize(); j++) {
                result._array[i][j] = this->_array[i][j] - mt._array[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& mt) {
        if (this->_size != mt._size) {
            throw std::invalid_argument("Matrices must be of the same size for multiplication.");
        }

        Matrix result(this->_size);

        for (size_t i = 0; i < this->_size; i++) {
            for (size_t j = i; j < this->_size; j++) {
                T sum = 0;

                for (size_t k = i; k <= j; k++) {
                    if ((k - i) < this->_array[i].GetSize() && (j - k) < mt._array[k].GetSize()) {
                        sum += this->_array[i][k - i] * mt._array[k][j - k];
                    }
                }

                result._array[i][j - i] = sum;
            }
        }
        return result;
    }


    friend istream& operator>>(istream& in, Matrix& mt) {
        for (size_t i = 0; i < mt._size; i++) {
            in >> mt._array[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& os, const Matrix& mt) {
        for (size_t i = 0; i < mt._size; i++) {
            os << "|";
            for (size_t j = 0; j < i; j++) os << "0, ";
            os << mt._array[i] << "|\n";
        }
        return os;
    }
};
