#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    Rectangle rect1, rect2;

    double width1, height1;
    cout << "Enter the width and height of the first rectangle: ";
    cin >> width1 >> height1;
    rect1.setDimensions(width1, height1);

    double width2, height2;
    cout << "Enter the width and height of the second rectangle: ";
    cin >> width2 >> height2;
    rect2.setDimensions(width2, height2);

    // afisare rezultate
    cout << "\nRectangle 1:\n";
    cout << "Perimeter: " << rect1.getPerimeter() << endl;
    cout << "Area: " << rect1.getArea() << endl;

    cout << "\nRectangle 2:\n";
    cout << "Perimeter: " << rect2.getPerimeter() << endl;
    cout << "Area: " << rect2.getArea() << endl;

    cout << "\nComparison:\n";
    rect1.comparePerimeter(rect2);
    rect1.compareArea(rect2);

    return 0;
}