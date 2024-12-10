#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

template <class T>
class Vector {
protected:
    T* _array;
    size_t _size;
    size_t _startIndex;

public:
    Vector() : _size(10), _startIndex(0), _array(new T[10]()) {}

    Vector(size_t size, size_t startIndex = 0)
        : _size(size), _startIndex(startIndex), _array(new T[size]()) {}

    Vector(const Vector<T>& vec)
        : _size(vec._size), _startIndex(vec._startIndex), _array(new T[vec._size]) {
        std::copy(vec._array, vec._array + _size, _array);
    }

    Vector(Vector<T>&& vec) noexcept
        : _array(vec._array), _size(vec._size), _startIndex(vec._startIndex) {
        vec._array = nullptr;
        vec._size = 0;
        vec._startIndex = 0;
    }

    ~Vector() {
        delete[] _array;
    }

    size_t GetSize() const { return _size; }
    size_t GetStartIndex() const { return _startIndex; }

    T& operator[](size_t index) {
        if (index >= _size) throw std::out_of_range("Index out of range");
        return _array[index];
    }

    const T& operator[](size_t index) const {
        if (index >= _size) throw std::out_of_range("Index out of range");
        return _array[index];
    }

    Vector<T>& operator=(const Vector<T>& vec) {
        if (this != &vec) {
            delete[] _array;
            _size = vec._size;
            _startIndex = vec._startIndex;
            _array = new T[_size];
            std::copy(vec._array, vec._array + _size, _array);
        }
        return *this;
    }

    friend istream& operator>>(istream& in, Vector& vec) {
        for (size_t i = 0; i < vec._size; i++) {
            in >> vec._array[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& os, const Vector& vec) {
        for (size_t i = 0; i < vec._size; i++) {
            os << vec._array[i];
            if (i + 1 != vec._size) os << ", ";
        }
        return os;
    }
};
