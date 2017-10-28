#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.get();
    for (int i = 0; i < t; i++)
    {
        char ch;
        bool sentence_begin = true, word_begin = true;
        while (cin.get(ch) && ch != '\n')
        {
            if (sentence_begin)
            {
                cout.put(toupper(ch));
                sentence_begin = false;
            }
            else if (word_begin)
            {
                cout.put(ch);
                word_begin = false;
            }
            else if (ch == ' ')
            {
                cout.put(ch);
                word_begin = true;
            }
            else
                cout.put(tolower(ch));
        }
        cout << endl;
    }
    return 0;
}
