#ifndef MYCLASS_H_
#define MYCLASS_H_

#include <string>
#include <vector>
#include <utility>
#include <iostream>

#include "CodeBuilder.hpp"

using namespace std;

class CodeBuilder;

class myClass
{
    string name;
    vector<pair<string, string>> attributes;

    myClass(const string &nameClass);

public:
    friend class CodeBuilder;
    friend ostream& operator<<(ostream &os, const CodeBuilder &obj);
};

#endif