#include "CodeBuilder.hpp"

CodeBuilder::CodeBuilder(const string &class_name)
{
    this->root = new myClass(class_name);
}

CodeBuilder& CodeBuilder::add_field(const string &name, const string &type)
{
    this->root->attributes.push_back(make_pair(type, name));
    return *this;
}

ostream &operator<<(ostream &os, const CodeBuilder &obj)
{
    os << "Class " << obj.root->name << endl
       << "{" << endl;
    for (auto i : obj.root->attributes)
    {
        os << "\t" << i.first << " " << i.second << ";" << endl;
    }
    os << "};" << endl;
    return os;
}