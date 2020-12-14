#include "HtmlBuilder.h"

using namespace std;

HtmlBuilder::HtmlBuilder(string root_name)
{
    root = new HtmlElement(root_name, "");
}

HtmlBuilder &HtmlBuilder::addChild(string child_name, string child_text)
{
    HtmlElement e{child_name, child_text};
    root->elements.emplace_back(e);
    return *this;
}

HtmlElement HtmlBuilder::build()
{
    return *root;
}

string HtmlBuilder::str() const { return root->str(0); }

// operator HtmlBuilder::HtmlElement() const
// {
//     return root;
// }
