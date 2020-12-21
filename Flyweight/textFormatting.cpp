#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BetterFormattedText
{
public:
    struct TextRange
    {
        int start, end;
        bool capitalize;
        bool covers(int position) const
        {
            return (position >= start) && (position <= end);
        }
    };

    TextRange& get_range(int start, int end)
    {
        formatting.emplace_back(TextRange{start, end});
        return *formatting.rbegin(); // returns a reverse iterator (dereferenced) which points to the member before rend();
    }

    BetterFormattedText(const string& str): plain_text(str){}

    friend ostream &operator<<(ostream& os, const BetterFormattedText& obj)
    {
        string s;
        for (auto i = 0; i < obj.plain_text.length(); i++)
        {
            auto c = obj.plain_text[i];
            for (const auto& rng : obj.formatting)
            {
                if (rng.covers(i) && rng.capitalize)
                {
                    c = toupper(c);
                }
            }
            s += c;
        }
        return os << s;
    }
private:
    string plain_text;
    vector<TextRange> formatting;
};

int main()
{
    BetterFormattedText txt{"This is a brave new world!"};
    txt.get_range(10, 15).capitalize = true;
    txt.get_range(20, 23).capitalize = true;
    cout << txt << endl;
    return 0;
}