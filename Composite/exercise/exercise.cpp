#include "exercise.h"
#include <iostream>

using namespace std;

int sum(const vector<ContainsIntegers*> items)
{
    int sum = 0;
    for (ContainsIntegers* i : items)
    {
        sum += i->addValues();
    }
    return sum;
}

int main()
{
    SingleValue s1{5};
    ManyValues s2;
    s2.add(10);
    s2.add(1);

    cout << "Sum of all values is " << sum({&s1, &s2}) << endl;
    return 0;
}