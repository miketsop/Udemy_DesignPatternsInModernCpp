#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ContainsIntegers
{
    virtual int addValues() = 0;
};

struct SingleValue : ContainsIntegers
{
  int value{ 0 };

  SingleValue() = default;

  explicit SingleValue(const int value)
    : value{value}
  {
  }

  int addValues() override
  {
    return value;
  }
};

struct ManyValues : vector<int> , ContainsIntegers
{
  void add(const int value)
  {
    push_back(value);
  }

  int addValues() override
  {
    int sum = 0;
    for (int i : *this)
    {
        sum += i;
    }
    return sum;
  }
};

int sum(const vector<ContainsIntegers*> items);