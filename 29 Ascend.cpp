#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (cin >> str && str != "$")
    {
        for (int i = 0; i < str.length(); i++)
            str[i] = (str[i] - 'A' - (i + 1) % 26 + 26) % 26 + 'A';
        cout << str << endl;
    }
    return 0;
}
