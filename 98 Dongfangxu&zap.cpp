#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int get_consecutive_num(const string& haystack, const char * needle)
{
    int found = haystack.find(needle);
    if (found == string::npos)
        return 0;
    int count = 1;
    int max = 1;
    while (true)
    {
        int next = haystack.find(needle, found + 1);
        if (next == found + strlen(needle))
        {
            count++;
            if (max < count)
                max = count;
        }
        else if (next == string::npos)
            return max;
        else
            count = 1;
        found = next;
    }
}

int main()
{
    int T;
    cin >> T;
    cin.get();
    for (int Ti = 0; Ti < T; Ti++)
    {
        string s;
        getline(cin, s);
        int count_dfx = get_consecutive_num(s, "dongfangxu");
        int count_zap = get_consecutive_num(s, "zap");
        if (count_dfx >= count_zap)
            cout << "dongfangxu!" << endl;
        else
            cout << "zap!" << endl;
    }
    return 0;
}
