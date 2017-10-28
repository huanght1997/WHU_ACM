#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (!islower(s[0]) || s[s.size()-1] == '_')
    {
        cout << "Error!" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (!(isalnum(s[i]) || s[i] == '_'))
        {
            cout << "Error!" << endl;
            return 0;
        }
    }
    if (s.find('_') != string::npos)
    {
        // Cannot be java style
        // Check Uppercase
        if (any_of(s.begin(), s.end(), [](char c){return isupper(c);}))
            cout << "Error!" << endl;
        else
        {
            int pos = 0;
            while ((pos = s.find('_', pos)) != string::npos)
            {
                if (s[pos+1] == '_')
                {
                    cout << "Error!" << endl;
                    return 0;
                }
                s.replace(pos, 2, 1, toupper(s[pos+1]));
            }
            cout << s << endl;
        }
    }
    else
    {
        // Java style
        for (int i = 0; i < s.size(); i++)
        {
            if (isupper(s[i]))
            {
                char tmp[2];
                tmp[0] = '_';
                tmp[1] = tolower(s[i]);
                s.replace(i, 1, tmp, 2);
            }
        }
        cout << s << endl;
    }
    return 0;
}
