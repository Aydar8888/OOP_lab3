#include "../include/array.h"


Array::Array() : _size(0), _capacity(4) {
    _dataArray = new Figure*[_capacity];
}

Array::Array(const size_t& capacity) : _size(0), _capacity(capacity) {
    if (_capacity == 0) _capacity = 1;
    _dataArray = new Figure*[_capacity];
}

Array::~Array() {
    for (size_t i = 0; i < _size; ++i) {
        delete _dataArray[i]; 
    }
    delete[] _dataArray;
}

void Array::add(Figure* fig) {
    if (!fig) return;

    if (_size >= _capacity) {
        size_t new_capacity = _capacity * 2;
        Figure** new_data = new Figure*[new_capacity];
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = _dataArray[i];
        }
        delete[] _dataArray;
        _dataArray = new_data;
        _capacity = new_capacity;
    }

    _dataArray[_size] = fig;
    ++_size;
}

void Array::remove(size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Индекс за пределами массива");
    }

    delete _dataArray[index]; 
    for (size_t i = index; i < _size - 1; ++i) {
        _dataArray[i] = _dataArray[i + 1];
    }

    --_size;
}

double Array::totalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < _size; ++i) {
        total += double(*_dataArray[i]);
    }
    return total;
}

void Array::printAllCentersAndAreas() const {
    for (size_t i = 0; i < _size; ++i) {
        Point c = _dataArray[i]->center();
        double a = double(*_dataArray[i]);
        std::cout << "Фигура " << (i + 1) << ":\n";
        std::cout << "  Центр: (" << c.get_x() << ", " << c.get_y() << ")\n";
        std::cout << "  Площадь: " << a << "\n";
    }
}

const Figure& Array::operator[](size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Индекс за пределами массива");
    }
    return *_dataArray[index];
}