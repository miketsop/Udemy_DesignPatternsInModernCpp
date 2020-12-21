#include <iostream>
#include <string>
#include "boost/bimap.hpp"
#include "boost/flyweight.hpp"

using namespace std;
using namespace boost;

typedef uint16_t key;

struct User
{
public:
    friend ostream &operator<<(ostream& os, const User& obj);

    User(const string& first_name, const string& last_name):
        first_name{add(first_name)}, last_name{add(last_name)}{}

    const string& get_first_name() const
    {
        return names.left.find(first_name)->second;
    }

    const string& get_last_name() const
    {
        return names.left.find(last_name)->second;
    }
protected:
    key first_name, last_name;
    //  Don't keep them as names (strings)!!
    // string first_name, last_name;
    static bimap<key, string> names;
    static key seed;

    static key add(const string& s)
    {
        auto it =  names.right.find(s);
        if (it == names.right.end())
        {
            // Name is not existing in the bimap
            key id = ++seed;
            names.insert({seed, s});
            return id;
        }
        return it->second; // returns the key associated with this string
    }
};

struct User2
{
    flyweight<string> first_name, last_name;
    User2(const string& first_name, const string& last_name): first_name(first_name), last_name(last_name){}
};

ostream &operator<<(ostream& os, const User& obj)
{
    os << "Fist name: " << obj.get_first_name() << ", Last name: " << obj.get_last_name() << " (" << obj.last_name  << ") " << endl;
    return os;
}

key User::seed{0};
bimap<key,string> User::names{};

int main()
{
    User user1{"Mike","Tsopelas"};
    User user2{"Lotti", "Tsopelas"};

    cout << user1;
    cout << user2;

    /* Using boost builtin flyweight mechanism */
    User2 user3{"Mike","Tsopelas"};
    User2 user4{"Lotti", "Tsopelas"};

    cout << user3.first_name << " " << user3.last_name << endl;
    cout << user4.first_name << " " << user4.last_name << endl;

    cout << boolalpha;
    // Compare pointers to strings of flyweight for each user
    cout << (&user3.first_name.get() == &user4.first_name.get()) << endl;
    cout << (&user3.last_name.get() == &user4.last_name.get()) << endl;

    return 0;
}