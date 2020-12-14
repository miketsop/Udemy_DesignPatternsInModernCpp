#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
    Point(float x, float y) : x(x), y(y) {}

    float x, y;

private:
    //! Typically a Factory Class contains methods/constructors for something else.
    //! If you declare it as an inner class then you have access to all the private members of the outer class as well!
    class PointFactory
    {
        PointFactory() {}

    public:
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

public:
    friend ostream &operator<<(ostream &os, const Point &point)
    {
        os << "x: " << point.x << " y: " << point.y << endl;
        return os;
    }
    static PointFactory Factory;
};

int main()
{
    // auto p = Point::NewPolar(5, M_PI_4);
    // auto p = PointFactory::NewPolar(5, M_PI_4);
    // auto p = Point::PointFactory::NewPolar(5, M_PI_4);
    auto p = Point::Factory.NewPolar(5, M_PI_4);
    cout << p << endl;
}