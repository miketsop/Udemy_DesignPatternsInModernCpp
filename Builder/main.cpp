#include "HtmlElement.h"
#include "HtmlBuilder.h"

using namespace std;

int main()
{
    auto text = "hello";
    string output;
    output += "<p>";
    output += text;
    output += "</p>";
    cout << output << endl;

    //* If you have a list of words...
    string words[] = {"hello", "world"};
    ostringstream oss;
    oss << "<ul>";
    for (auto w : words)
    {
        oss << " <li> " << w << "</li>" << endl;
    }
    oss << "</ul>";
    cout << oss.str() << endl;

    //* =================================================================================
    //* But this does not take advantage of OOP... so lets see the builder design pattern
    //* =================================================================================
    cout << "Second way " << endl;
    HtmlBuilder builder("ul");
    builder.addChild("li", "hello");
    builder.addChild("li", "world");

    cout << builder.str() << endl;

    //* =================================================================================
    //*  Can also create a "fluent interface", by being able to type the following:
    //* =================================================================================
    cout << "Third way " << endl;
    HtmlBuilder builder2("ul");
    builder2.addChild("li", "hello").addChild("li", "world");
    cout << builder2.str() << endl;

    //* Here we return an HtmlBuilder
    cout << "Fourth way " << endl;
    auto elem = HtmlElement::create("ul").addChild("li", "hello");
    cout << elem.str() << endl;

    //* Here we use build() to return the actual HtmlElement
    cout << "Fifth way " << endl;
    auto elem2 = HtmlElement::create("ul").addChild("li", "hello").build();
    cout << elem2.str(0) << endl;
    return 0;
}