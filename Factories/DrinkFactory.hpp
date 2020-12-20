#pragma once

#include <map>
#include <memory>
#include <functional>
// #include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"

using namespace std;

class DrinkFactory
{
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;

public:
    DrinkFactory()
    {
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string &name)
    {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);
        return drink;
    }
};

class DrinkWithVolumeFactory
{
    map < string, function<unique_ptr<HotDrink()>> factories;

public:
    DrinkWithVolumeFactory()
    {
        factories["tea"] = [/* capture list */] {
            auto tea = make_unique<Tea>();
            tea->prepeare(200);
            return tea;
        };
    }

    unique_ptr<HotDrink> make_drink(const string &name)
    {
        return factories[name]();
    }
}