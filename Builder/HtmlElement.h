#ifndef HTMLELEMENT_H_H
#define HTMLELEMENT_H_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "HtmlBuilder.h"

using namespace std;

struct HtmlBuilder;
struct HtmlElement
{
    friend struct HtmlBuilder;

    string name, text;
    vector<HtmlElement> elements;

    const size_t indent_size = 2;

    HtmlElement();
    HtmlElement(const string &name, const string &text);

    //* If you make the constructor private, then you force the user to use build()
public:
    string str(int) const;
    static HtmlBuilder create(string root_name);
};

#endif