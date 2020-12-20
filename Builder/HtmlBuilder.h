#ifndef HTMLBUILDER_H_
#define HTMLBUILDER_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "HtmlElement.h"

using namespace std;

struct HtmlElement;
struct HtmlBuilder
{
    HtmlElement* root;

    public:
    HtmlBuilder(string root_name);
    HtmlBuilder &addChild(string child_name, string child_text);

    HtmlElement build();

    string str() const;

    // operator HtmlElement() const;
};

#endif