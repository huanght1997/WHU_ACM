#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str) && str != "ENDOFINPUT")
    {
        getline(cin, str);
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = (str[i] - 'A' - 5 + 26) % 26 + 'A';
            cout.put(str[i]);
        }
        cout << endl;
        getline(cin, str);
    }
    return 0;
}