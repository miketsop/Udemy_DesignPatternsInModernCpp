#include <iostream>

using namespace std;

struct Renderer
{
    virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRenderer : Renderer
{
    void render_circle(float x, float y, float radius) override 
    {
        cout << "Rendering as vector a circle of a radius " << radius << endl;
    }
};

struct RasterRenderer : Renderer
{
    void render_circle(float x, float y, float radius) override 
    {
        cout << "Rasterizing a circle of a radius " << radius << endl;
    }
};


/*
    Shape is implementing our "bridge" in this case - as it holds a reference to our renderers
*/
struct Shape
{
protected:
    Renderer& renderer;
    Shape(Renderer& renderer) : renderer(renderer){}
public:
    virtual void draw() = 0;
    virtual void resize(float factor) = 0;
};

struct Circle : Shape 
{
    float x, y, radius;
    Circle(Renderer& renderer, float x, float y, float radius) : Shape(renderer), x{x}, y{y}, radius{radius}{}
    void draw() override
    {
        //  The type of render_circle being called depends on what type the renderer is (in this case either VectorRenderer or RasterRenderer)
        renderer.render_circle(x, y, radius);
    }  

    void resize(float factor) override
    {
        radius *= factor;
    }
};

int main()
{
    RasterRenderer rr;
    Circle raster_circle{rr, 5, 5, 5};
    raster_circle.draw();
    raster_circle.resize(2.0);
    raster_circle.draw();
    return 0;
}