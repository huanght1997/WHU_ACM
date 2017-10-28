#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// string的排序就是按照字母表顺序来的
int main()
{
    string str;
    while (cin >> str)
    {
        int len = str.length();
        str += str.substr(0, len - 1);
        vector<string> v;
        for (int i = 0; i < len; i++)
            v.push_back(str.substr(i, len));
        cout << *min_element(v.begin(), v.end()) << endl;
    }
    return 0;
}