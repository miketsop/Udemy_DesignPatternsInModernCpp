#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
    Point(float x, float y) : x(x), y(y) {}

    float x, y;
    // friend class PointFactory;

    friend ostream &operator<<(ostream &os, const Point &point)
    {
        os << "x: " << point.x << " y: " << point.y << endl;
        return os;
    }
};

//! Typically a Factory Class contains methods/constructors for something else.
struct PointFactory {
    PointFactory () {}
    /* 
        NewCartesian and NewPolar are factory methods
        static is optional...
     */
    static Point NewCartesian(float x, float y)
    {
        return {x, y}; // return Point
    }

    static Point NewPolar(float r, float theta)
    {
        return {r * cos(theta), r * sin(theta)}; // return Point
    }
};

int main()
{
    // auto p = Point::NewPolar(5, M_PI_4);
    auto p = PointFactory::NewPolar(5, M_PI_4);
    cout << p << endl;
}