#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s;
    while (cin >> s && s != "R0C0")
    {
        string r, c;
        int pos_c = s.find('C');
        r = s.substr(1, pos_c - 1);
        c = s.substr(pos_c + 1);
        long col = stol(c,nullptr);
        stack<char> st;
        while (col != 0)
        {
            if (col % 26 == 0)
            {
                st.push('Z');
                col = col / 26 - 1;
            }
            else
            {
                st.push(col % 26 + 'A' - 1);
                col = col / 26;
            }
        }
        while (!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        cout << r << endl;
    }
    return 0;
}
