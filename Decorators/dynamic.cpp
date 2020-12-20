#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Shape
{
    virtual string str() const = 0;
};

struct Circle : Shape
{
    float radius;

    Circle(float radius) : radius(radius){}

    void resize(float factor)
    {
        radius *= factor;
    }

    string str() const override
    {
        ostringstream oss;
        oss << "A circle of radius " << radius << endl;
        return oss.str();
    }
};

struct Square : Shape
{
    float side;
    Square(){}
    Square(float side): side(side){}
    
    string str() const override
    {
        ostringstream oss;
        oss << "A square of side " << side;
        return oss.str();
    }
};


// ====================================================
// Dynamic decorators
// ====================================================
struct ColoredShape : Shape
{
    Shape& shape;
    string color;

    ColoredShape(Shape& shape, const string& color): shape(shape), color(color){}

    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has color " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape
{
    Shape& shape;
    uint8_t transparency;
    TransparentShape(Shape& shape, const uint8_t transparency): shape(shape), transparency(transparency) {}
    
    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has " << static_cast<float>(transparency) / 255.f * 100.f << "% transparency ";
        return oss.str();
    }
};

// ====================================================
// Static decorators
// ====================================================
/*
    Concept (introduced in c++20)
*/
template<typename T>
concept isAShape = std::is_base_of(Shape, T)::value;

template <isAShape T>
struct ColoredShape2 : T
{
    string color;
    ColoredShape2(){}
    template<typename...Args>
    ColoredShape2(const string& color, Args ...args) : T(std::forward<Args>(args)...);
};

int main()
{
    Square circle{5}, square{2};
    ColoredShape redCircle{circle, "red"}, redSquare{square, "red"};
    
    //! This does not work! The dynamic decorator does not have access to the methods of the original class.
    // redCircle.resize()
    TransparentShape mysquare{redSquare, 51};
    cout << mysquare.str() << endl;

    // ColoredShape2<Circle> redCircle;
    return  0;
}

