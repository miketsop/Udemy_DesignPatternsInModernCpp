#include "HtmlElement.h"

using namespace std;

HtmlElement::HtmlElement(){};

HtmlElement::HtmlElement(const string &name, const string &text) : name(name), text(text){
};

string HtmlElement::str(int indent = 0) const
{
    ostringstream oss;
    string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0)
    {
        oss << string(indent_size * (indent + 1), ' ') << text << endl;
    }
    for (const auto &e : elements)
    {
        oss << e.str(indent + 1);
    }
    oss << i << "</" << name << ">" << endl;
    return oss.str();
}

HtmlBuilder HtmlElement::create(string root_name)
{
    return HtmlBuilder(root_name); // Constructs a builder
}
