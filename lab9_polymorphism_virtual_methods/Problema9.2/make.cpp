#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846 // valore Pi
#endif

// clasa abstracta shape
class Shape
{
public:
    virtual void draw() = 0;      // virtual function pt. a desena / afisa forme
    virtual double getArea() = 0; // virtual function pt. a calcula aria
    virtual ~Shape() {}           // destructor
};

// clasa circle care mosteneste shape
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    void draw() override
    {
        cout << "Drawing Circle with radius: " << radius << endl;
    }
    double getArea() override
    {
        return M_PI * radius * radius; // exemplu de formula pt o arie (cerc): pi*r*r
    }
};

class Triangle : public Shape
{
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    void draw() override
    {
        cout << "Drawing Triangle with base: " << base << " and height: " << height << endl;
    }
    double getArea() override
    {
        return 0.5 * base * height;
    }
};

class Square : public Shape
{
private:
    double side;

public:
    Square(double s) : side(s) {}
    void draw() override
    {
        cout << "Drawing Square with side: " << side << endl;
    }
    double getArea() override
    {
        return side * side;
    }
};

class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    void draw() override
    {
        cout << "Drawing Rectangle with length: " << length << " and width: " << width << endl;
    }
    double getArea() override
    {
        return length * width;
    }
};

int main()
{
    vector<Shape *> shapes; // vector pt forme

    shapes.push_back(new Circle(5));
    shapes.push_back(new Triangle(4, 6));
    shapes.push_back(new Square(3));
    shapes.push_back(new Circle(7));

    shapes.push_back(new Rectangle(4, 8));

    double totalArea = 0;

    // se trece prin vector si se aduna toate ariile
    for (auto shape : shapes)
    {
        shape->draw();
        totalArea += shape->getArea();
    }

    cout << "\nThe total area of all shapes is: " << totalArea << endl;

    for (auto shape : shapes)
    {
        delete shape;
    }

    return 0;
}