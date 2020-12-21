#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Sentence
{
    struct WordToken
    {
        bool capitalize;
        string mystr;
        
        WordToken(const bool capitalize, const string& str) : capitalize(capitalize), mystr(str){};
    };

    vector<WordToken> words;

    Sentence(const string& text)
    {
        string s;
        istringstream check1(text); 
        while (getline(check1, s, ' '))
        {
            words.emplace_back(WordToken{false, s});
        }
    }

    WordToken& operator[](size_t index)
    {
        return words[index];
    }

    string str() const
    {
        string s;
        for (const auto& word : words)
        {
            if (word.capitalize)
            {
                for (auto i = 0; i < word.mystr.length();i++){
                    s += toupper(word.mystr[i]);
                }
            }
            else
            {
                s += word.mystr;
            }
            s += " ";
        }
        return s;
    }
};

int main()
{
    Sentence sentence{"Hello world\n"};
    sentence[0].capitalize = true;
    cout << sentence.str(); // prints Hello WORLD
    return 0;
}