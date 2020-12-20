#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Flower
{
  virtual string str() = 0;
};

struct Rose : Flower
{
  string str() override {
        string oss;
        oss = "A rose\n";
        return oss;
  }
};

struct RedFlower : Flower
{
    Flower& flower;
    string color;
    RedFlower(Flower& flower): flower(flower){
        color = "red";
    }

    string str() override {
        string oss = flower.str();
        if (oss.find("that is") == string::npos)
        {
            oss += " that is " + color;
        }
        else if (oss.find(color) == string::npos){
            oss += " and " + color;
        }
        return oss;
    }
};

struct BlueFlower : Flower
{
    Flower& flower;
    string color;
    BlueFlower(Flower& flower) : flower(flower){
        color = "blue";
    }

    string str() override {
        string oss = flower.str();
        if (oss.find("that is") == string::npos)
        {
            oss += " that is " + color;
        }
        else if (oss.find(color) == string::npos){
            oss += " and " + color;
        }
        return oss;
    }
};

int main()
{
    Rose rose;
    RedFlower red_rose{rose};   
    RedFlower red_red_rose{red_rose};
    BlueFlower blue_red_rose{red_rose};

    cout << rose.str();
    cout << red_rose.str();
    cout << red_red_rose.str();
    cout << blue_red_rose.str();

    return 0;
}