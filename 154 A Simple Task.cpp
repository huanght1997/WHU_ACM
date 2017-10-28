#include <iostream>
#include <cctype>
using namespace std;

int main()
{   
    char str[51];
    int cases = 1;
    while (cin >> str && str[0] != '#')
    {   
        cout << "Case " << cases << ": ";
        int pos = 0;
        while (str[pos] != '\0')
        {   
            if (pos % 2 == 1)
                str[pos] = toupper(str[pos]);
            pos++;
        }
        cout << str << endl;
        cases++;
    }   
    return 0;
}   
