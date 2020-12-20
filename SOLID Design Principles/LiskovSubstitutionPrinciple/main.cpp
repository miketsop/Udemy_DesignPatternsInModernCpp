#include <iostream>

using namespace std;

class Rectangle
{
protected:
    int width, height;

public:
    ~Rectangle(){};

    Rectangle(int width, int height) : width(width), height(height){};

    int getHeight()
    {
        return Rectangle::height;
    }

    int getWidth()
    {
        return Rectangle::width;
    }

    virtual void setHeight(int height)
    {
        Rectangle::height = height;
    }

    virtual void setWidth(int width)
    {
        Rectangle::width = width;
    }

    int area() const
    {
        return width * height;
    }
};

class Square : public Rectangle
{
public:
    Square(int size) : Rectangle(size, size)
    {
    }

    void setWidth(int width)
    {
        this->width = width;
        this->height = width;
    }

    void setHeight(int width)
    {
        this->width = width;
        this->height = width;
    }
};

struct RectangleFactory {
    static Rectangle createRectangle(int w, int h);
    static Rectangle createSquare(int size);
};

void process(Rectangle &r)
{
    int w = r.getWidth();
    r.setHeight(10);
    cout << "Expected area = " << (w * 10)
         << ", got " << r.area() << endl;
}

int main()
{
    Rectangle r(3, 4);
    process(r);

    Square sq(5);
    process(sq);
    return 0;
}