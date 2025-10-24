#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include "point.h"

class Figure {
public:
    virtual double area() const = 0;    

    virtual Point center() const = 0;   

    virtual void print(std::ostream& os) const = 0; 

    virtual void read(std::istream& is) = 0;  
            
    virtual operator double() const = 0;

    virtual ~Figure() = default;      
};

std::ostream& operator<<(std::ostream& os, const Figure& fig);
std::istream& operator>>(std::istream& is, Figure& fig);

#endif