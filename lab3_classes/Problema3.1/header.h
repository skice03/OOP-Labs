#ifndef HEADER_H
#define HEADER_H

#include <iostream>

using namespace std;

class Rectangle
{
private:
    double width;
    double height;

public:
    // constructor
    Rectangle(double w = 0, double h = 0) : width(w), height(h) {}

    void setDimensions(double w, double h)
    {
        width = w;
        height = h;
    }

    double getPerimeter() const
    {
        return 2 * (width + height);
    }

    double getArea() const
    {
        return width * height;
    }

    void comparePerimeter(const Rectangle &other) const
    {
        double myPerimeter = getPerimeter();
        double otherPerimeter = other.getPerimeter();

        if (myPerimeter > otherPerimeter)
            cout << "The first rectangle's perimeter is greater.\n";
        else if (myPerimeter < otherPerimeter)
            cout << "The second rectangle's perimeter is greater.\n";
        else
            cout << "Both rectangles have the same perimeter.\n";
    }

    void compareArea(const Rectangle &other) const
    {
        double myArea = getArea();
        double otherArea = other.getArea();

        if (myArea > otherArea)
            cout << "The first rectangle's area is greater.\n";
        else if (myArea < otherArea)
            cout << "The second rectangle's area is greater.\n";
        else
            cout << "Both rectangles have the same area.\n";
    }
};

#endif