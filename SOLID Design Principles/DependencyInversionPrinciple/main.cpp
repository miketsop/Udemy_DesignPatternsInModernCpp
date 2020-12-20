#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

//* A.  High level modules should not depend on low-level modules.
//*     Both should depend on abstractions.
//* B.  Abstractions should not depend on details.
//*     Details should depend on abstractions.

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

struct RelationshipBrowser
{
    virtual vector<Person> findAllChildrenOf(const string &name) = 0;
};

//* Low level module
struct Relationships : RelationshipBrowser
{
    vector<tuple<Person, Relationship, Person>> relations;

    void addParentAndChild(const Person &parent, const Person &child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> findAllChildrenOf(const string &name) override{
        vector<Person> result;
        for (auto&& [first, rel, second] : relations){
            if (first.name == name && rel == Relationship::parent){
                result.push_back(second);
            }
        }
        return result;
    }
};


//* High level module
struct Research
{
    Research(RelationshipBrowser &browser){
        for (auto& child : browser.findAllChildrenOf("John")){
            cout << "John has a child called " << child.name << endl;
        }
    }
    //! Here we make the module depend very much on the implementation details of struct Relationships
    // Research(Relationships &relationships)
    // {
    //     auto &relations = relationships.relations;
    //     for (auto &&[first, rel, second] : relations)
    //     {
    //         if (first.name == "John" && rel == Relationship::parent)
    //         {
    //             cout << "John has a child called " << second.name << endl;
    //         }
    //     }
    // };
};

int main()
{
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Matt"};

    Relationships relationships;
    relationships.addParentAndChild(parent, child1);
    relationships.addParentAndChild(parent, child2);

    Research _(relationships);
    return 0;
}