#ifndef CODEBUILDER_H_
#define CODEBUILDER_H_

#include <string>
#include <ostream>
#include "myClass.hpp"

using namespace std;

class myClass;

class CodeBuilder
{
public:
    myClass *root;

    CodeBuilder(const string &myclassname);

    CodeBuilder &add_field(const string &name, const string &type);
};

ostream &operator<<(ostream &os, const CodeBuilder &obj);

#endif
