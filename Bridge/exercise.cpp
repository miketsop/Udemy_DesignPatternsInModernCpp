#include <string>
#include <iostream>

using namespace std;

struct Renderer
{
    virtual string what_to_render_as(string& name) = 0;
};

struct VectorRenderer : Renderer
{
    string what_to_render_as(string& name) override 
    {
        return "Drawing " + name + " as lines";
    }
};

struct RasterRenderer : Renderer
{
    string what_to_render_as(string& name) override 
    {
        return "Drawing " + name + " as pixels";
    }
};

struct Shape
{
protected:
    string name;
    Renderer& renderer;
    Shape(Renderer& renderer) : renderer(renderer){}
    virtual void str() = 0;
};

struct Triangle : Shape
{
    Triangle(Renderer&& renderer) : Shape(renderer)
    {
        name = "Triangle";
    }

    void str() override
    {
        cout << renderer.what_to_render_as(name) << endl;
    }
};

struct Square : Shape
{
    Square(Renderer&& renderer) : Shape(renderer)
    {
        name = "Square";
    }

    void str() override
    {
        cout << renderer.what_to_render_as(name) << endl;
    }
};

int main()
{
    // cout << "Hello " << endl;
    RasterRenderer rr;
    VectorRenderer vr;
    Triangle{VectorRenderer{}}.str();
    // Triangle{vr}.str();
    // Square{rr}.str();
    // Square{vr}.str();
    return 0;
}