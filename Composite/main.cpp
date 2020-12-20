#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <array>
#include <functional>

using namespace std;

class Creature {
    enum Abilities {strength, agility, intelligence, count};
    array<int, count> abilities;    //  Fixed size container

public:
    int get_strength(){return abilities[strength];}
    void set_strength(int val) {abilities[strength] = val;}

    int get_agility(){return abilities[agility];}
    void set_agility(int val) {abilities[agility] = val;}

    int get_intelligence(){return abilities[intelligence];}
    void set_intelligence(int val) {abilities[intelligence] = val;}

    int sum() const
    {
        return accumulate(abilities.begin(), abilities.end(), 0);
    }

    double average() const 
    {
        return sum() / (double)count;
    }

    int max() const {
        return *max_element(abilities.begin(), abilities.end());
    }
};

int main()
{
    Creature orc;
    orc.set_strength(16);
    orc.set_agility(15);
    orc.set_intelligence(5);

    cout << "Orc has an average statistic of " << orc.average() << " and a max. of " << orc.max() << endl;
    return 0;
}