#include <iostream>

using namespace std;

struct Point
{
    int x{0}, y{0};

    Point() {}

    Point(const int x, const int y) : x{x}, y{y} {}

    friend ostream &operator<<(ostream &os, const Point &p)
    {
        
        os << "(" << p.x << ", " << p.y << ")" << endl;
        return os;
    }
};

struct Line
{
    Point *start, *end;

    Line(Point *const start, Point *const end)
        : start(start), end(end)
    {
        cout << "Line constructor!" << endl;
    }

    ~Line()
    {
        delete start;
        delete end;
    }

    Line deep_copy() const
    {
        cout << "Called deep_copy() on line object!" << endl;
        Point p1(this->start->x, this->start->y);
        Point p2(this->end->x, this->end->y);
        return Line(&p1, &p2);
    }

    friend ostream &operator<<(ostream &os, const Line &l)
    {
        os << "(" << l.start->x << ", " << l.start->y << ")" <<  " --> " <<  "(" << l.end->x << ", " << l.end->y << ")" << endl; ;
        return os;
    }
};

int main()
{
    Point p1(1, 1);
    Point p2(2, 2);
    Line l1(&p1, &p2);
    Line l2 = l1.deep_copy();
    l2.start->x = 3;

    cout << p1;
    cout << l1;
    cout << l2;
    return 0;
}