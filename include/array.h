#ifndef ARRAY_H
#define ARRAY_H

#include "./figure.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

class Array {
private:
    size_t _size;       
    size_t _capacity;   
    Figure** _dataArray;

public:
    Array();
    Array(const size_t& capacity);
    ~Array();

    void add(Figure* fig);
    void remove(size_t index);
    double totalArea() const;
    void printAllCentersAndAreas() const;
    const Figure& operator[](size_t index) const;
    size_t size() const { return _size; }
};

#endif